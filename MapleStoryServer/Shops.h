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

#ifndef SHOPS_H
#define SHOPS_H

#include <hash_map>
#include <vector>

using namespace std;
using namespace stdext;

class Player;

struct ShopItemInfo {
	int id;
	int price;
};

struct ShopInfo {
	int npc;
	vector <ShopItemInfo> items;
};

class Shops{
public:
	static hash_map <int, ShopInfo> shops;
	static void addShop(int id, ShopInfo shop){
		shops[id] = shop;
	}
	static void showShop(Player* player, int id);
	static int getPrice(Player* player, int itemid);
};

#endif