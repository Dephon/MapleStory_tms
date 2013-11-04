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
#include "MySQLM.h"

hash_map <int, int> ChannelsPlayers::players;
char ChannelsPlayers::header[100];

void ChannelsPlayers::addPlayer(Channel *channel, unsigned char *packet){
	int playerid = getInt(packet);
	players[playerid] = channel->getChannelID();
}

void ChannelsPlayers::removePlayer(Channel *channel, unsigned char *packet){
	int playerid = getInt(packet);
	if(players.find(playerid) != players.end()){
		players.erase(playerid);
	}

}

void ChannelsPlayers::removePlayersFromChannel(int n){
	for (hash_map<int, int>::iterator iter = players.begin();
		 iter != players.end(); iter++){
		if(iter->second == n){
			players.erase(iter);
			break;
		}
	}
}

void ChannelsPlayers::findRequest(Channel *channel, unsigned char *packet){
	int player = getInt(packet);
	short namelen = getShort(packet+4);
	if(namelen>15)
		return;
	char name[15];
	getString(packet+6, namelen, name);
	int playerid = MySQL::getIntEx("characters", "name", name, "id");
	int channelid = -1;
	if(players.find(playerid) != players.end()){
		channelid = players[playerid];
		MySQL::getStringI("characters", "id", playerid, "name", name);
	}
	ChannelsPacket::findRequest(channel, channelid, player, name);	
}
void ChannelsPlayers::changeHeader(Channel *channel, unsigned char *packet){
	short headerlen = getShort(packet);
	if(headerlen>99)
		return;
	getString(packet+2, headerlen, header);
	ChannelsPacket::changeHeader(channel, header, Channels::channels);
}

bool ChannelsPlayers::isPlayerConnected(int charid){
	if(players.find(charid) != players.end())
		return 1;
	else
		return 0;
}