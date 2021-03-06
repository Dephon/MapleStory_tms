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

#ifndef ABSTRACTPLAYER_H
#define ABSTRACTPLAYER_H

class PacketHandler;
class AbstractPlayer {
public:
	virtual void setPacketHandler (PacketHandler* packetHandler) {
		this->packetHandler = packetHandler;
	}
	virtual void handleRequest (unsigned char* buf, int len) = 0;
	virtual ~AbstractPlayer(){}
protected:
	PacketHandler* packetHandler;
};

class AbstractPlayerFactory {
public:
	virtual AbstractPlayer* createPlayer () = 0;
};
#endif