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

#include <stdio.h>
#include <Winsock2.h>
#include "Acceptor.h"
#include "PacketHandler.h"

Acceptor::Acceptor(int port, Selector* selector, AbstractPlayerFactory* apf, bool master) {
	abstractPlayerFactory = apf;

	SOCKET acceptSocket = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (acceptSocket == INVALID_SOCKET) {
		printf ("socket error: %d\n", WSAGetLastError());
		return;
	}

	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = INADDR_ANY; //inet_addr("127.0.0.1");
	service.sin_port = htons(port);

	if (bind( acceptSocket, (SOCKADDR*) &service, sizeof(service)) == SOCKET_ERROR) {
		printf("bind() error: %d\n", WSAGetLastError());
		return;
	}

	if (listen( acceptSocket, 10 ) == SOCKET_ERROR) {
		printf("listen() error: %d\n", WSAGetLastError());
		closesocket(acceptSocket);
		return;
	}

	this->master = master;

	selector->registerSocket (acceptSocket, true, false, true, this);

}

void Acceptor::handle (Selector* selector, int socket) {
	SOCKET sock = accept( socket, NULL, NULL );
	printf ("accept\n");
	if (sock == INVALID_SOCKET) {
		printf("accept error: %d\n", WSAGetLastError());
		return;
	}

	AbstractPlayer* player = abstractPlayerFactory->createPlayer();
	PacketHandler* ph;
	if(master)
		ph = new PacketHandlerMaster(sock, player);
	else
		ph = new PacketHandlerMaple(sock, player);
	player->setPacketHandler(ph);
	selector->registerSocket (sock, true, false, true, ph);
}
