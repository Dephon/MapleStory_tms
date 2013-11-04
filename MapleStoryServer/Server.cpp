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

#include "Server.h"
#include "ServerPacket.h"
#include "Player.h"
#include "Channels.h"
#include <windows.h>

char Server::msg[100];
int Server::on;

void Server::showScrollingHeader(Player* player){
	if(on)
		ServerPacket::showScrollingHeader(player, msg);

}
void Server::changeScrollingHeader(char* msg){
	strcpy_s(Server::msg, 100, msg);
	ServerPacket::changeScrollingHeader(Server::msg);
	
}
void Server::enableScrollingHeader(){
	on=1;
	ServerPacket::changeScrollingHeader(msg);

}
void Server::disableScrollingHeader(){
	on=0;
	ServerPacket::scrollingHeaderOff();
}

void Server::initialize(){
	strcpy_s(msg, 100, "Welcome to MapleStory!");
	on = 1;
}

__int64 Server::getServerTime(){
	SYSTEMTIME systemTime;
	GetSystemTime( &systemTime );
	FILETIME fileTime; 
	SystemTimeToFileTime( &systemTime, &fileTime );
	ULARGE_INTEGER uli;
	uli.LowPart = fileTime.dwLowDateTime; 
	uli.HighPart = fileTime.dwHighDateTime;
	return uli.QuadPart;
}