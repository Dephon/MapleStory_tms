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

#ifndef LEVELS_H
#define LEVELS_H

class Player;

class Levels {
public:
	static int exps[200];
	static void giveEXP(Player* player, int exp, char type=0);
	static void addStat(Player* player, unsigned char* packet);
	static void setLevel(Player* player, int level);
	static void setJob(Player* player, int job);
};

#endif