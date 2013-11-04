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

#include "Channel.h"
#include "Channels.h"
#include "ChannelsPlayers.h"
#include "ChannelsPacket.h"

int Channels::channeln;
Channel* Channels::channels[20];

void Channels::setChannels(int n){
	channeln = n;
	for(int i=0; i<20; i++){
		channels[i] = NULL;
	}
	strcpy_s(ChannelsPlayers::header, 100, "Welcome To MapleStory!");
}

void Channels::acceptChannel(Channel* channel, unsigned char* packet){
	int channelid = packet[0];
	channel->setChannelID(channelid);
	channels[channelid] = channel;
	ChannelsPacket::sendHeader(channel, ChannelsPlayers::header);

}

void Channels::removeChannel(Channel* channel){
	if(channel->getChannelID() != -1 && channels[channel->getChannelID()] == channel){
		channels[channel->getChannelID()] = NULL;
		ChannelsPlayers::removePlayersFromChannel(channel->getChannelID());
	}

}

void Channels::changeChannel(Channel *channel, unsigned char *packet){
	int playerid = getInt(packet);
	char channelid = packet[4];
	ChannelsPacket::changeChannel(channel, playerid, 8888+channelid, (getChannelStatus(channelid) != NULL));
}
