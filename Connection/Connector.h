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

#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "../Decoder/Decoder.h"
#include "../Decoder/MasterDecoder.h"
#include <Winsock2.h>
#include <windows.h>

class Connector {
public:
	Connector (char* ip, int port);
	void handle();
	virtual void handlePacket(unsigned char* buf, int size) = 0;
	void sendPacket(unsigned char* buf, int size);
private:
	SOCKET sock;
	MasterDecoder*  decoder;
};

#endif