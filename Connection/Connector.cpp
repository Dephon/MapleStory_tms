 /*This file is part of TitanMS.

    TitanMS is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    TitanMS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with TitanMS.  If not, see <http://www.gnu.org/licenses/>.*/

#include "Connector.h"
#include <windows.h>

#define MASTER_HEADER_LEN 2
#define BUFFER_LEN 10000

void _handle (Connector* connectorObject) {
	connectorObject->handle();
}

Connector::Connector(char* ip, int port){
	decoder = new MasterDecoder();
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	if (sock == INVALID_SOCKET) {
	    printf("Error at socket(): %ld\n", WSAGetLastError());
	    WSACleanup();
	    return;
	}
	
	sockaddr_in clientService; 
	clientService.sin_family = AF_INET;
	clientService.sin_addr.s_addr = inet_addr( ip );
	clientService.sin_port = htons( port );
	
	if ( connect( sock, (SOCKADDR*) &clientService, sizeof(clientService) ) == SOCKET_ERROR) {
		printf( "Failed to connect to Master Server.\n" );
		WSACleanup();
	    return;
	}
	printf("Connected to Master Server.\n");
	HANDLE hThread = CreateThread( 
		NULL, 
		0,
		(LPTHREAD_START_ROUTINE)_handle,
		(LPVOID)this,
		0,
		NULL);
}

void Connector::handle(){
	unsigned char packet[BUFFER_LEN];
	int len;
	while (1) {
		len = 0;
		while (len < MASTER_HEADER_LEN) {
			int l = recv(sock, (char*)packet+len, MASTER_HEADER_LEN - len, 0);
			len += l;
			if (l == SOCKET_ERROR) {
				printf("recv error: %d\n", WSAGetLastError());
				closesocket(sock);
				return;
			}
		}
		int packlen = decoder->getLength(packet);
		if(len == MASTER_HEADER_LEN){
			while (len < packlen+MASTER_HEADER_LEN){
				int l = recv(sock, (char*)packet+len, packlen + MASTER_HEADER_LEN - len, 0);
				len += l;
				if (l == SOCKET_ERROR) {
					printf("recv error: %d\n", WSAGetLastError());
					closesocket(sock);
					return;
				}
			}	
		}
		if(len == packlen + MASTER_HEADER_LEN){
			decoder->decrypt(packet+MASTER_HEADER_LEN, packlen);
			handlePacket(packet+MASTER_HEADER_LEN, packlen);
		}
			
	}	
}

void Connector::sendPacket(unsigned char* buf, int size){
	unsigned char bufs[BUFFER_LEN];
	decoder->createHeader((unsigned char*)bufs, (short)(size));
	decoder->encrypt(buf, size);
	memcpy_s(bufs+MASTER_HEADER_LEN, size, buf, size);
	send(sock, (const char*)bufs, size+MASTER_HEADER_LEN, 0);

}