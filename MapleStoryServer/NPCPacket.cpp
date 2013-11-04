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

#include "NPCPacket.h"
#include "PacketCreator.h"
#include "Player.h"
#include "NPCs.h"

void NPCPacket::showNPC(Player* player, NPCInfo npc, int i){
	Packet packet = Packet();
	packet.addHeader(0xA8);
	packet.addInt(i+0x64);
	packet.addInt(npc.id);
	packet.addShort(npc.x);
	packet.addShort(npc.cy);
	packet.addByte(1);
	packet.addShort(npc.fh);
	packet.addShort(npc.rx0);
	packet.addShort(npc.rx1);
	packet.packetSend(player);
	packet = Packet();
	packet.addHeader(0xAD);
	packet.addByte(1);
	packet.addInt(i+0x64);
	packet.addInt(npc.id);
	packet.addShort(npc.x);
	packet.addShort(npc.cy);
	packet.addByte(1);
	packet.addShort(npc.fh);
	packet.addShort(npc.rx0);
	packet.addShort(npc.rx1);
	packet.packetSend(player);
}