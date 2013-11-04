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

#ifndef MASTERSERVERPACK_H
#define MASTERSERVERPACK_H

class MasterServer;

class MasterServerPacket {
public:
	static void sendChannelInfo(MasterServer* masterServer, int channelid);
	static void addPlayer(MasterServer* masterServer, int playerid);
	static void removePlayer(MasterServer* masterServer, int playerid);
	static void changeChannel(MasterServer* masterServer, int playerid, char channelid);
};

#endif