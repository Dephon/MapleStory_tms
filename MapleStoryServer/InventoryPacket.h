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

#ifndef INVPACK_H
#define INVPACK_H

#include <vector>

using namespace std;

class Player;
struct Equip;
struct Item;
short getShort(unsigned char* buf);
int getInt(unsigned char* buf);
void getString(unsigned char* buf, int len, char* out);

class InventoryPacket {
public:
	static void moveItem(Player* player, char inv, short slot1, short slot2);
	static void updatePlayer(Player* player);
	static void addEquip(Player* player, Equip* equip, bool is);
	static void bought(Player* player);
	static void newMesos(Player* player, int mesos, bool is);
	static void addItem(Player* player, Item* item, bool is);
	static void addNewItem(Player* player, Item* item, bool is);
	static void moveItemS(Player* player, char inv, short slot, short amount);
	static void moveItemS2(Player* player, char inv, short slot1, short amount1, short slot2, short amount2);
	static void sitChair(Player* player, vector <Player*> players, int chairid);
	static void stopChair(Player* player, vector <Player*> players);
	static void useScroll(Player* player, vector <Player*> players, char s);
	static void useItemEffect(Player* player, vector <Player*> players, int itemid);
};

#endif