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

#ifndef SERVER_H
#define SERVER_H

#include <hash_map>
#include <vector>

using namespace std;
using namespace stdext;

class Player;
class MasterServer;

class Server {
private: 
	static char msg[100];
	static int on;
public:
	static void showScrollingHeader(Player* player);
	static void changeScrollingHeader(char* msg);
	static void enableScrollingHeader();
	static void disableScrollingHeader();
	static void initialize();
	static __int64 getServerTime();
};

#endif