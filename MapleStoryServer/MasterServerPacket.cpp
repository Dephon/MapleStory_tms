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

#include "MasterServerPacket.h"
#include "PacketCreator.h"

void MasterServerPacket::sendChannelInfo(MasterServer* masterServer, int channelid){
	Packet packet = Packet();
	packet.addHeader(0x00);
	packet.addByte(channelid);
	packet.packetSendMasterServer(masterServer);
}

void MasterServerPacket::addPlayer(MasterServer* masterServer, int playerid){
	Packet packet = Packet();
	packet.addHeader(0x01);
	packet.addInt(playerid);
	packet.packetSendMasterServer(masterServer);
}
void MasterServerPacket::removePlayer(MasterServer* masterServer, int playerid){
	Packet packet = Packet();
	packet.addHeader(0x02);
	packet.addInt(playerid);
	packet.packetSendMasterServer(masterServer);
}
void MasterServerPacket::changeChannel(MasterServer* masterServer, int playerid, char channelid){
	Packet packet = Packet();
	packet.addHeader(0x03);
	packet.addInt(playerid);
	packet.addByte(channelid);
	packet.packetSendMasterServer(masterServer);
}