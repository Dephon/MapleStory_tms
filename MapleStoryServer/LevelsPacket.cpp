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

#include "LevelsPacket.h"
#include "PacketCreator.h"
#include "Player.h"

void LevelsPacket::showEXP(Player* player, int exp, char type){
	Packet packet = Packet();
	packet.addHeader(0x32);
	packet.addByte(3);
	packet.addByte(1);
	packet.addInt(exp);
	packet.addInt(type);
	packet.addInt(0);
	packet.addInt(0);
	packet.addByte(0);
	packet.packetSend(player);
}

void LevelsPacket::levelUP(Player* player, vector <Player*> players){
	Packet packet = Packet();
	packet.addHeader(0x23);
	packet.addShort(0);
	packet.addShort(0x7C10);
	packet.addShort(1);
	packet.addByte(player->getLevel());
	packet.addShort(player->getHP());
	packet.addShort(player->getRMHP());
	packet.addShort(player->getMP());
	packet.addShort(player->getRMMP());
	packet.addShort(player->getAp());
	packet.addInt(player->getExp());
	packet.packetSend(player); // TODO
	packet = Packet();
	packet.addHeader(0x86);
	packet.addInt(player->getPlayerid());
	packet.addByte(0);
	packet.sendTo(player, players, 0);

}

void LevelsPacket::statOK(Player* player){
	Packet packet = Packet();
	packet.addHeader(0x23);
	packet.addShort(1);
	packet.addInt(0);
	packet.packetSend(player);
}
void LevelsPacket::changeStat(Player* player, int nam, short val){
	Packet packet = Packet();
	packet.addHeader(0x23);
	packet.addShort(1);
	packet.addInt(nam);
	packet.addShort(val);
	packet.addShort(player->getAp());
	packet.packetSend(player);
}

void LevelsPacket::jobChange(Player *player, std::vector<Player*> players){
	Packet packet = Packet();
	packet.addHeader(0x23);
	packet.addShort(0);
	packet.addInt(0x20);
	packet.addShort(player->getJob());
	packet.packetSend(player);
	packet = Packet();
	packet.addHeader(0x86);
	packet.addInt(player->getPlayerid());
	packet.addByte(8);
	packet.sendTo(player, players, 0);
}