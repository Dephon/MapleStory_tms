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

#ifndef MAPPACK_H
#define MAPPACK_H

class Player;
class Packet;

class MapPacket {
public:
	static Packet playerPacket(Player* player);
	static void showPlayer(Player* player, vector <Player*> players);
	static void showPlayers(Player* player, vector <Player*> players);
	static void removePlayer(Player* player, vector <Player*> players);
	static void changeMap(Player* player);
	static void makeApple(Player* player);
};

#endif