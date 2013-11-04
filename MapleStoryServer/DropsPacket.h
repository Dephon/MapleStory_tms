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

#ifndef DROPPACK_H
#define DROPPACK_H

#include <vector>

using namespace std;

class Player;
class Drop;
struct Dropped;

short getShort(unsigned char* buf);
int getInt(unsigned char* buf);
void getString(unsigned char* buf, int len, char* out);

class DropsPacket {
public:
	static void drop(vector <Player*> players, Drop* drop, Dropped dropper);
	static void dropForPlayer(Player* player, Drop* drop, Dropped dropper);
	static void showDrop(Player* player, Drop* drop);
	static void takeNote(Player* player, int id, bool ismesos, short amount);
	static void takeDrop(Player* player, vector <Player*> players, Drop* drop);
	static void dontTake(Player* player);
	static void removeDrop(vector <Player*> players, Drop* drop);
	static void explodeDrop(vector <Player*> players, Drop* drop);
};

#endif