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

#ifndef CHANNEL_H
#define CHANNEL_G

#include "../Connection/AbstractPlayer.h"
#include "../Connection/PacketHandler.h"

class Channel:public AbstractPlayer {
public:
	Channel () {
		channelid=-1;
	}

	~Channel();
	void handleRequest(unsigned char* buf, int len);
	void sendPacket(unsigned char* buf, int len){ packetHandler->sendPacket(buf,len); }
	void setChannelID(int n){
		channelid = n;
	}
	int getChannelID(){
		return channelid;
	}
private:
	int channelid;
	
};

class ChannelFactory:public AbstractPlayerFactory {
public:
	AbstractPlayer* createPlayer() {
		return new Channel();
	}
};

#endif