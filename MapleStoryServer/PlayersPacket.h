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

#ifndef PLAYERSPACK_H
#define PLAYERSPACK_H

class Player;
class Packet;

class PlayersPacket {
public:
	static void showMoving(Player* player, vector <Player*> players, unsigned char* packet, int size);
	static void faceExperiment(Player* player, vector <Player*> players, int face);
	static void showChat(Player* player, vector <Player*> players, char* msg);
	static void damagePlayer(Player* player, vector <Player*> players, int dmg, int mob);
	static void showMassage(char* msg, char type);
	static void showInfo(Player* player, Player* getinfo);
	static void findPlayer(Player* player, char* name, int map);
	static void changeChannel(Player* player, char channelid, short port, unsigned char a, unsigned char b, unsigned char c, unsigned char d);
};

#endif