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

#include "MasterServer.h"
#include "MasterServerPacket.h"
#include "Server.h"
#include "Players.h"
#include "Player.h"

int MasterServer::channelid;
MasterServer* MasterServer::masterServer;

MasterServer::MasterServer(char* ip, int port) : Connector(ip, port){
	masterServer = this;
}

void MasterServer::handlePacket(unsigned char *buf, int size){
	short header = buf[0] + buf[1]*0x100;
	switch(header){
		case 0x00: Players::changeChannel(buf+2); break;
		case 0x01: changeHeader(buf+2); break;
		case 0x02: Players::findResponse(buf+2); break;
	}
}

void MasterServer::setChannel(int channelid){
	MasterServer::channelid = channelid;
	MasterServerPacket::sendChannelInfo(masterServer, channelid);
}
void MasterServer::addPlayer(int playerid){
	MasterServerPacket::addPlayer(masterServer, playerid);
}
void MasterServer::removePlayer(int playerid){
	MasterServerPacket::removePlayer(masterServer, playerid);
}

void MasterServer::changeHeader(unsigned char* packet){
	short len = getShort(packet);
	char header[100];
	if(len>0){
		getString(packet+2, len, header);
		Server::changeScrollingHeader(header);
	}
	else{
		Server::disableScrollingHeader();
	}
}

void MasterServer::changeChannel(Player* player, unsigned char* packet){
	char channelid = packet[0];
	MasterServerPacket::changeChannel(masterServer, player->getPlayerid(), channelid);
}