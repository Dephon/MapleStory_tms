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

#include "../Connection/Acceptor.h"
#include "../Connection/Connector.h"
#include "PlayerLogin.h"
#include "Channel.h"
#include "Player.h"
#include "MySQLM.h"
#include <stdlib.h>
#include "Initializing.h"
#include "Timer.h"
#include "Skills.h"
#include "Maps.h"
#include "Server.h"
#include "Channels.h"
#include "MasterServer.h"

void main(){

	Initializing::initializing();
	printf("Initializing Timers... ");
	Timer::timer = new Timer();
	Skills::startTimer();
	Maps::startTimer();
	printf("DONE\n");
	printf("Initializing MySQL... ");
	if(MySQL::connectToMySQL())
		printf("DONE\n");
	else{
		printf("FAILED\n");
		exit(1);
	}
	Server::initialize();
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	if (iResult != NO_ERROR)  printf("Error at WSAStartup()\n");

	srand((unsigned char)time(0));

	Selector* selector = new Selector();
	// If LoginServer:
	Acceptor::Acceptor(8484, selector, new PlayerLoginFactory());
	Acceptor::Acceptor(8585, selector, new ChannelFactory(), true);
	Channels::setChannels(1);
	// If ChannelServer:
	MasterServer* connectMasterServer = new MasterServer("127.0.0.1", 8585);
	MasterServer::setChannel(0); // Set this channelid
	Acceptor::Acceptor(8888+MasterServer::getChannelID(), selector, new PlayerFactory());
	////////////////////

	while(getchar()){}
}