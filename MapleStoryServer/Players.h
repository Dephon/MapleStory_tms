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

#ifndef PLAYERS_H
#define PLAYERS_H

#include <hash_map>

using namespace std;
using namespace stdext;

class Player;

struct Pos;

class Players {
public:
	static hash_map <int, Player*> players;
	static hash_map <char*, Player*> names;
	static void addPlayer(Player* player);
	static void deletePlayer(Player* player);
	static void handleMoving(Player* player, unsigned char* packet, int size);
	static void damagePlayer(Player* player, unsigned char* packet);
	static void faceExperiment(Player* player, unsigned char* packet);
	static void chatHandler(Player* player, unsigned char* packet);
	static void healPlayer(Player* player, unsigned char* packet);
	static void getPlayerInfo(Player* player, unsigned char* packet);
	static void searchPlayer(Player* player, unsigned char* packet);
	static void findResponse(unsigned char* packet);
	static void changeChannel(unsigned char* packet);
};

#endif