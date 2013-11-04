#ifndef SELECTOR_H
#define SELECTOR_H
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

#include <Winsock2.h>
#include <hash_map>

using namespace stdext;

class Selector {
public:

	class SelectHandler {
	public:
		virtual void handle (Selector* selector, int socket) = 0;
	};

	Selector ();
	~Selector();

	void registerSocket 
		(int socket, 
		bool selectRead, bool selectWrite, bool selectError, 
		SelectHandler* handler);

	void unregisterSocket (int socket);
	void selectThread();

private:
	bool terminate;
	fd_set readfds;
    fd_set writefds;
	fd_set errorfds;
	struct timeval timeout;
	hash_map<int, SelectHandler*> handlers;
};

#endif