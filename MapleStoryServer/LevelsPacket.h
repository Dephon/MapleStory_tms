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

#ifndef LEVELPACK_H
#define LEVELPACK_H

#include <vector>
using namespace std;

short getShort(unsigned char* buf);
int getInt(unsigned char* buf);
void getString(unsigned char* buf, int len, char* out);

class Player;

class LevelsPacket {
public:
	static void showEXP(Player* player, int exp, char type);
	static void levelUP(Player* player, vector <Player*> players);
	static void jobChange(Player* player, vector <Player*> players);
	static void statOK(Player* player);
	static void changeStat(Player* player, int nam, short val);
};

#endif