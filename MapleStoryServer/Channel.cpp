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


void Channel::handleRequest(unsigned char* buf, int len){
	short header = buf[0] + buf[1]*0x100;
	switch(header){
		case 0x00: Channels::acceptChannel(this, buf+2); break;
		case 0x01: ChannelsPlayers::addPlayer(this, buf+2); break;
		case 0x02: ChannelsPlayers::removePlayer(this, buf+2); break;
		case 0x03: Channels::changeChannel(this, buf+2); break;
		case 0x04: ChannelsPlayers::changeHeader(this, buf+2); break;
		case 0x05: ChannelsPlayers::findRequest(this, buf+2); break;
	}
}


Channel::~Channel(){
	Channels::removeChannel(this);
}