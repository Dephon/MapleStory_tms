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

#include "ServerPacket.h"
#include "PacketCreator.h"
#include "Player.h"
#include "Players.h"

void ServerPacket::showScrollingHeader(Player* player, char* msg){
	Packet packet = Packet();
	packet.addHeader(0x2D);
	packet.addByte(4);
	packet.addByte(1);
	packet.addShort(strlen(msg));
	packet.addString(msg, strlen(msg));
	packet.packetSend(player);
}
void ServerPacket::changeScrollingHeader(char* msg){
	Packet packet = Packet();
	packet.addHeader(0x2D);
	packet.addByte(4);
	packet.addByte(1);
	packet.addShort(strlen(msg));
	packet.addString(msg, strlen(msg));
	for (hash_map<int,Player*>::iterator iter = Players::players.begin();
		 iter != Players::players.end(); iter++){
			 packet.packetSend(iter->second);
	}
}

void ServerPacket::scrollingHeaderOff(){
	Packet packet = Packet();
	packet.addHeader(0x2D);
	packet.addByte(4);
	packet.addByte(0);
	for (hash_map<int,Player*>::iterator iter = Players::players.begin();
		 iter != Players::players.end(); iter++){
			 packet.packetSend(iter->second);
	}
}