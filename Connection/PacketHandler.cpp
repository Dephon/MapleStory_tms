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

#include "PacketHandler.h"
//#include "Decoder.h"
#include <Winsock2.h>

#define HEADER_LEN 4
#define MASTER_HEADER_LEN 2
#define BUFFER_LEN 10000

PacketHandlerMaple::PacketHandlerMaple(int socket, AbstractPlayer* player) {
	this->socket = socket;
	buffer = new unsigned char[BUFFER_LEN];
	bytesInBuffer = 0;
	this->player = player;
	decoder = new Decoder();
	int l = send(socket, (char*)(decoder->getConnectPacket()), Decoder::CONNECT_LENGTH, 0);
	if (l < Decoder::CONNECT_LENGTH) {
		//TODO
	}
}

void PacketHandlerMaple::handle (Selector* selector, int socket) {
	if (bytesInBuffer < HEADER_LEN) {
		// read header
		int l = recv(socket, (char*)(buffer + bytesInBuffer), HEADER_LEN - bytesInBuffer, 0);
		if (l <= 0) {
			selector->unregisterSocket(socket);
			closesocket(socket);
			delete player;
		}
		bytesInBuffer += l;
	}

	if (bytesInBuffer >= HEADER_LEN) {
		int packetSize = Decoder::getLength(buffer);
		int l = recv(socket, (char*)(buffer + bytesInBuffer), HEADER_LEN + packetSize - bytesInBuffer, 0);
		if (l <= 0) {
			selector->unregisterSocket(socket);
			closesocket(socket);
			delete player;
		}
		bytesInBuffer += l;
		if (bytesInBuffer == packetSize + HEADER_LEN){
			decoder->decrypt(buffer + HEADER_LEN, packetSize);
			player->handleRequest(buffer + HEADER_LEN, packetSize);
			bytesInBuffer = 0;
		}
	}

}


void PacketHandlerMaple::sendPacket(unsigned char *buff, int size){
	unsigned char bufs[BUFFER_LEN];
	decoder->createHeader((unsigned char*)bufs, (short)(size));
	decoder->encrypt(buff, size);
	memcpy_s(bufs+HEADER_LEN, size, buff, size);
	decoder->next();
	send(socket, (const char*)bufs, size+HEADER_LEN, 0);
}
PacketHandlerMaster::PacketHandlerMaster(int socket, AbstractPlayer* player) {
	this->socket = socket;
	buffer = new unsigned char[BUFFER_LEN];
	bytesInBuffer = 0;
	this->player = player;
	decoder = new MasterDecoder();
}

void PacketHandlerMaster::handle (Selector* selector, int socket) {
	if (bytesInBuffer < MASTER_HEADER_LEN) {
		// read header
		int l = recv(socket, (char*)(buffer + bytesInBuffer), MASTER_HEADER_LEN - bytesInBuffer, 0);
		if (l <= 0) {
			selector->unregisterSocket(socket);
			closesocket(socket);
			delete player;
		}
		bytesInBuffer += l;
	}

	if (bytesInBuffer >= MASTER_HEADER_LEN) {
		int packetSize = MasterDecoder::getLength(buffer);
		int l = recv(socket, (char*)(buffer + bytesInBuffer), MASTER_HEADER_LEN + packetSize - bytesInBuffer, 0);
		if (l <= 0) {
			selector->unregisterSocket(socket);
			closesocket(socket);
			delete player;
		}
		bytesInBuffer += l;
		if (bytesInBuffer == packetSize + MASTER_HEADER_LEN){
			decoder->decrypt(buffer + MASTER_HEADER_LEN, packetSize);
			player->handleRequest(buffer + MASTER_HEADER_LEN, packetSize);
			bytesInBuffer = 0;
		}
	}

}


void PacketHandlerMaster::sendPacket(unsigned char *buff, int size){
	unsigned char bufs[BUFFER_LEN];
	decoder->createHeader((unsigned char*)bufs, (short)(size));
	decoder->encrypt(buff, size);
	memcpy_s(bufs+MASTER_HEADER_LEN, size, buff, size);
	send(socket, (const char*)bufs, size+MASTER_HEADER_LEN, 0);
}