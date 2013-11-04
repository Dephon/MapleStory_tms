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

#ifndef MAPS_H
#define MAPS_H

#include <hash_map>
#include <vector>

using namespace std;
using namespace stdext;

class Player;
class MapTimer;



struct PortalInfo {
	int id;
	char from[20];
	int toid;
	char to[20];
	int type;
	short x;
	short y;
};
typedef vector<PortalInfo> PortalsInfo;

struct MapInfo {
	int rm;
	PortalsInfo Portals;
	vector<Player*> Players;
};

class Maps {
public:
	static MapTimer* timer;
	static void startTimer();
	static hash_map <int, MapInfo> info;
	static void addMap(int id, MapInfo map);
	static void addPlayer(Player* player);
	static void moveMap(Player* player, unsigned char* packet);
	static void removePlayer(Player* player);
	static void changeMap(Player* player, int mapid, int pos);
	static void mapTimer(int mapid);
	static void newMap(Player* player);
};

#endif