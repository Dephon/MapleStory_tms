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

#ifndef LOGINPACKET_H
#define LOGINPACKET_H

#define MAX_FIELD_SIZE 15

#include <vector>

using namespace std;

class PlayerLogin;
struct World;
struct Character;

short getShort(unsigned char* buf);
int getInt(unsigned char* buf);
void getString(unsigned char* buf, int len, char* out);
class LoginPacket {
public:
	static void loginError(PlayerLogin* player, short errorid);
	static void loginProcess(PlayerLogin* player, char id);
	static void loginConnect(PlayerLogin* player, char* username, int size);
	static void processOk(PlayerLogin* player);
	static void showWorld(PlayerLogin* player, World world);
	static void worldEnd(PlayerLogin* player);
	static void showChannels(PlayerLogin* player);
	static void channelSelect(PlayerLogin* player);
	static void showCharacters(PlayerLogin* player, vector <Character> chars);
	static void showCharacter(PlayerLogin* player, Character charc);
	static void checkName(PlayerLogin* player, char is, char* name);
	static void deleteCharacter(PlayerLogin* player, int ID);
	static void connectIP(PlayerLogin* player, int charid);
	static void logBack(PlayerLogin* player);
};

#endif