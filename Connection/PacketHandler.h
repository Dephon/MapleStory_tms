#ifndef PACKETHANDLER_H
#define PACKETHANDLER_H

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

#include "../Decoder/Decoder.h"
#include "../Decoder/MasterDecoder.h"
#include "../Decoder/MapleEncryption.h"
#include "Selector.h"
#include "AbstractPlayer.h"

class PacketHandler: public Selector::SelectHandler {
public:

	virtual void handle (Selector* selector, int socket) = 0;
	virtual void sendPacket(unsigned char* buf, int len) = 0;
};

class PacketHandlerMaple: public PacketHandler {
public:

	PacketHandlerMaple(int socket, AbstractPlayer* player);
	void handle (Selector* selector, int socket);
	void sendPacket(unsigned char* buf, int len);

private:

	unsigned char* buffer;
	int bytesInBuffer;
	AbstractPlayer* player;
	Decoder* decoder;
	int socket;
};

class PacketHandlerMaster: public PacketHandler {
public:

	PacketHandlerMaster(int socket, AbstractPlayer* player);
	void handle (Selector* selector, int socket);
	void sendPacket(unsigned char* buf, int len);

private:

	unsigned char* buffer;
	int bytesInBuffer;
	AbstractPlayer* player;
	int socket;
	MasterDecoder* decoder;
};

#endif