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

#include "PacketCreator.h"
#include "Player.h"
#include "Players.h"
#include "PlayersPacket.h"


void PlayersPacket::showMoving(Player* player, vector <Player*> players, unsigned char* packett, int size){
	Packet packet = Packet();
	packet.addHeader(0x85);
	packet.addInt(player->getPlayerid());
	packet.addInt(0);
	packet.addBytesHex(packett+5, size);
	packet.sendTo(player, players, 0);
}	

void PlayersPacket::faceExperiment(Player* player, vector <Player*> players, int face){
	Packet packet = Packet();
	packet.addHeader(0x8d);
	packet.addInt(player->getPlayerid());
	packet.addInt(face);
	packet.sendTo(player, players, 0);
}

void PlayersPacket::showChat(Player* player, vector <Player*> players, char* msg){
	Packet packet = Packet();
	packet.addHeader(0x72);
	packet.addInt(player->getPlayerid());
	packet.addByte(0);
	packet.addShort(strlen(msg));
	packet.addString(msg, strlen(msg));
	packet.sendTo(player, players, 1);
}

void PlayersPacket::damagePlayer(Player* player, vector <Player*> players, int dmg, int mob){
	Packet packet = Packet();
	packet.addHeader(0x8A);
	packet.addInt(player->getPlayerid());
	packet.addByte(-1);
	packet.addInt(dmg);
	packet.addInt(mob);
	packet.addShort(1);
	packet.addByte(0);
	packet.addInt(dmg);
	packet.sendTo(player, players, 1);
}

void PlayersPacket::showMassage(char* msg, char type){
	Packet packet = Packet();
	packet.addHeader(0x2D); 
	packet.addByte(type);
	packet.addShort(strlen(msg));
	packet.addString(msg, strlen(msg));
	for (hash_map<int,Player*>::iterator iter = Players::players.begin();
		 iter != Players::players.end(); iter++){
			 packet.packetSend(iter->second);
	}
}

void PlayersPacket::showInfo(Player* player, Player* getinfo){
	Packet packet = Packet();
	packet.addHeader(0x2A);
	packet.addInt(getinfo->getPlayerid());
	packet.addByte(getinfo->getLevel());
	packet.addShort(getinfo->getJob());
	packet.addShort(getinfo->getFame());
	packet.addByte(0); // Married
	packet.addShort(1); // Guild Name Len
	packet.addByte(0x2D); // Guild Name
	packet.addShort(0);
	packet.addByte(0);
	packet.packetSend(player);
}

void PlayersPacket::findPlayer(Player* player, char* name, int map){
	Packet packet = Packet();
	packet.addHeader(0x5F);
	if(map == -1){
		packet.addByte(0xA);
	}
	else{
		packet.addByte(9);
	}
	packet.addShort(strlen(name));
	packet.addString(name, strlen(name));
	if(map == -1){
		packet.addByte(0);
	}
	else if(map < -1){
		packet.addByte(3);
		packet.addInt(-map-2);
	}
	else {
		packet.addByte(1);
		packet.addInt(map);
		packet.addInt(0);
		packet.addInt(-54);
	}
	packet.packetSend(player);

}

void PlayersPacket::changeChannel(Player* player, char channelid, short port, unsigned char a, unsigned char b, unsigned char c, unsigned char d){
	Packet packet = Packet();
	packet.addHeader(0x03);
	packet.addByte(channelid);
	packet.addByte(a);
	packet.addByte(b);
	packet.addByte(c);
	packet.addByte(d);
	packet.addShort(port);
	printf("%d.%d.%d.%d:%d\n", a,b,c,d,port);
	packet.packetSend(player);
}