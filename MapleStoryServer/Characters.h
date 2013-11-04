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

#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <vector>

using namespace std;

struct CharEquip {
	char type;
	int id;
};

struct Character {
	int id;
	char name[15];
	char gender;
	char skin;
	int eyes;
	int hair;
	char level;
	short job;
	short str;
	short dex;
	short intt;
	short luk;
	short hp;
	short mhp;
	short mp;
	short mmp;
	short ap;
	short sp;
	short exp;
	short fame;
	int map;
	char pos;
	vector <CharEquip> equips;
};

class PlayerLogin;

class Characters {
private:
	static void showEquips(int id, vector <CharEquip> &vec);
	static void createEquip(int equipid, int type, int charid);
public:
	static void connectGame(PlayerLogin* player, unsigned char* packet);
	static void checkCharacterName(PlayerLogin* player, unsigned char* packet);
	static void createCharacter(PlayerLogin* player, unsigned char* packet);
	static void deleteCharacter(PlayerLogin* player, unsigned char* packet);
	static void showCharacters(PlayerLogin* player);
};

#endif