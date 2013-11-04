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

#ifndef MOBSPACK_H
#define MOBSPACK_H

class Player;
class Mob;

short getShort(unsigned char* buf);
int getInt(unsigned char* buf);
void getString(unsigned char* buf, int len, char* out);

class MobsPacket {
public:
	static void controlMob(Player* player, Mob* mob);
	static void endControlMob(Player* player, Mob* mob);
	static void spawnMob(Player* player, Mob* mob, vector <Player*> players, bool isspawn);
	static void showMob(Player* player, Mob* mob);
	static void moveMob(Player* player, Mob* mob ,vector <Player*> players, unsigned char* pack, int pla);
	static void damageMob(Player* player, vector <Player*> players, unsigned char* pack);
	static void showHP(Player* player, int mobid, char per);
	static void dieMob(Player* player, vector<Player*> players, Mob* mob, int mobid);
	static void damageMobSkill(Player* player, vector <Player*> players, unsigned char* pack);
	static void damageMobS(Player* player, vector <Player*> players, unsigned char* pack, int itemid);
};

#endif