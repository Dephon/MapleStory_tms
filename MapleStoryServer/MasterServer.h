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

#ifndef MASTERSERVER_H
#define MASTERSERVER_H

#include "../Connection/Connector.h"
class Player;

short getShort(unsigned char* buf);
int getInt(unsigned char* buf);
void getString(unsigned char* buf, int len, char* out);

class MasterServer: public Connector {
public:		
	MasterServer(char* ip, int port); 
	void handlePacket(unsigned char* buf, int size);
	static void setChannel(int channelid);
	static int getChannelID(){
		return channelid;
	}
	static void addPlayer(int playerid);
	static void removePlayer(int playerid);
	static void changeHeader(unsigned char* packet);
	static void changeChannel(Player* player, unsigned char* packet);
private:
	static int channelid;
	static MasterServer* masterServer;
};
#endif