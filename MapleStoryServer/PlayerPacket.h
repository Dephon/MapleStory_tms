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

#ifndef PLAYERPACK_H
#define PLAYERPACK_H

class Player;

class PlayerPacket {
public:
	static void connectData(Player* player);
	static void newHP(Player* player, short hp);
	static void showKeys(Player* player, int keys[90]);
	static void newEXP(Player* player, int exp);
	static void setSP(Player* player);
	static void setJob(Player* player);
	static void newMP(Player* player, short mp, bool is);
	static void newHair(Player* player);
	static void newEyes(Player* player);
	static void newSkin(Player* player);
};

#endif