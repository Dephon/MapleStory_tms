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

#ifndef QUESTSPACK_H
#define QUESTSPACK_H

#include <vector>

using namespace std;

class Player;

short getShort(unsigned char* buf);
int getInt(unsigned char* buf);
void getString(unsigned char* buf, int len, char* out);

struct Quest;

class QuestsPacket {
public:
	static void acceptQuest(Player* player, short questid, int npcid);
	static void updateQuest(Player* player, Quest quest);
	static void doneQuest(Player* player, int questid);
	static void questFinish(Player* player, vector <Player*> players, short questid, int npcid, short nextquest, __int64 time);
	static void giveItem(Player* player, int itemid, int amount);
	static void giveMesos(Player* player, int amount);
};

#endif