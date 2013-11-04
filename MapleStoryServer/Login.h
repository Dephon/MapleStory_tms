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

#ifndef LOGIN_H
#define LOGIN_H

class PlayerLogin;

class Login {
private:
	static int checkLogin(char *username, char *password);
	static void checkPin(PlayerLogin* player, unsigned char* packet);
public:
	static void loginUser(PlayerLogin* player, unsigned char* packet);
	static void setGender(PlayerLogin* player, unsigned char* packet){}
	static void handleLogin(PlayerLogin* player, unsigned char* packet);
	static void registerPIN(PlayerLogin* player, unsigned char* packet);
	static void loginBack(PlayerLogin* player);
};

#endif