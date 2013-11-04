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

#include "Worlds.h"
#include "LoginPacket.h"
#include <string.h>
#include "PlayerLogin.h"
#include "Characters.h"
#include "Channels.h"

void Worlds::showWorld(PlayerLogin* player){
	if(player->getStatus() != 4){
		// hacking
		return;
	}
	World world;
	strcpy_s(world.name, 15, "Scania");
	world.channels = Channels::getChannels();;
	world.id = 0;
	LoginPacket::showWorld(player, world);
	LoginPacket::worldEnd(player);
}

void Worlds::selectWorld(PlayerLogin* player, unsigned char* packet){
	player->setServer(packet[0]);
	LoginPacket::showChannels(player);
}

void Worlds::channelSelect(PlayerLogin* player, unsigned char* packet){
	player->setChannel(packet[1]); 
	if(Channels::getChannelStatus(player->getChannel()) != NULL){
		LoginPacket::channelSelect(player);
		Characters::showCharacters(player);
	}
	else{
		LoginPacket::loginError(player, 6);
	}
}