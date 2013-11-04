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

#include "ChannelsPacket.h"
#include "PacketCreator.h"

void ChannelsPacket::findRequest(Channel* channel, int channelid, int playerid, char* name){
	Packet packet = Packet();
	packet.addHeader(0x02);
	packet.addInt(playerid);
	packet.addByte(channelid);
	packet.addShort(strlen(name));
	packet.addString(name, strlen(name));
	packet.packetSendChannel(channel);
}

void ChannelsPacket::changeHeader(Channel *channel, char *header, Channel *channels[]){
	Packet packet = Packet();
	packet.addHeader(0x01);
	packet.addShort(strlen(header));
	packet.addString(header, strlen(header));
	packet.sendToChannels(channel, channels, 0);
}
void ChannelsPacket::sendHeader(Channel *channel, char *header){
	Packet packet = Packet();
	packet.addHeader(0x01);
	packet.addShort(strlen(header));
	packet.addString(header, strlen(header));
	packet.packetSendChannel(channel);
}

void ChannelsPacket::changeChannel(Channel* channel, int playerid, short port, char channelid){
	Packet packet = Packet();
	packet.addHeader(0x00);
	packet.addInt(playerid);
	packet.addByte(channelid);
	// IP
	packet.addByte(5);
	packet.addByte(167);
	packet.addByte(207);
	packet.addByte(220);
	// 
	packet.addShort(port);
	packet.packetSendChannel(channel);
}