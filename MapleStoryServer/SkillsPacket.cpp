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

#include "SkillsPacket.h"
#include "Player.h"
#include "PacketCreator.h"
#include "Skills.h"

void SkillsPacket::addSkill(Player* player, int skillid, int level){
	Packet packet = Packet();
	packet.addHeader(0x2f);
	packet.addByte(1);
	packet.addShort(1);
	packet.addInt(skillid);
	packet.addInt(level);
	packet.addInt(0);
	packet.addByte(1);
	packet.packetSend(player);
	packet.packetSend(player);
}

void SkillsPacket::showSkill(Player* player, vector <Player*> players, int skillid){
	Packet packet = Packet();
	packet.addHeader(0x86);
	packet.addInt(player->getPlayerid());
	packet.addByte(1);
	packet.addInt(skillid);
	packet.addByte(1); //TODO
	packet.sendTo(player, players, 0);
}


void SkillsPacket::useSkill(Player* player, vector <Player*> players, int skillid, int time, SkillActiveInfo pskill, SkillActiveInfo mskill){
	Packet packet = Packet();
	packet.addHeader(0x3b);
	packet.addByte(pskill.types[0]);
	packet.addByte(pskill.types[1]);
	packet.addByte(pskill.types[2]);
	packet.addByte(pskill.types[3]);
	packet.addByte(pskill.types[4]);
	packet.addByte(pskill.types[5]);
	packet.addByte(pskill.types[6]);
	packet.addByte(pskill.types[7]);
	for(unsigned int i=0; i<pskill.vals.size(); i++){
		packet.addShort(pskill.vals[i]);
		packet.addInt(skillid);
		packet.addInt(time);
	}
	packet.addShort(0);
	packet.addByte(0);
	packet.packetSend(player);
	if(mskill.vals.size()>0){
		packet = Packet();
		packet.addHeader(0x87);
		packet.addInt(player->getPlayerid());
		packet.addByte(mskill.types[0]);
		packet.addByte(mskill.types[1]);
		packet.addByte(mskill.types[2]);
		packet.addByte(mskill.types[3]);
		packet.addByte(mskill.types[4]);
		packet.addByte(mskill.types[5]);
		packet.addByte(mskill.types[6]);
		packet.addByte(mskill.types[7]);
		for(unsigned int i=0; i<mskill.vals.size(); i++){
			packet.addShort(mskill.vals[i]);
		}
		packet.addByte(0);
		packet.sendTo(player, players, 0);
	}
}

void SkillsPacket::healHP(Player* player, short hp){
	Packet packet = Packet();
	packet.addHeader(0x68);
	packet.addByte(0xA);
	packet.addShort(hp);
	packet.packetSend(player);
}

void SkillsPacket::endSkill(Player* player, vector <Player*> players, SkillActiveInfo pskill, SkillActiveInfo mskill){
	Packet packet = Packet();
	packet.addHeader(0x24);
	packet.addByte(pskill.types[0]);
	packet.addByte(pskill.types[1]);
	packet.addByte(pskill.types[2]);
	packet.addByte(pskill.types[3]);
	packet.addByte(pskill.types[4]);
	packet.addByte(pskill.types[5]);
	packet.addByte(pskill.types[6]);
	packet.addByte(pskill.types[7]);
	packet.addByte(0);
	packet.packetSend(player);
	if(mskill.vals.size()>0){
		packet = Packet();
		packet.addHeader(0x8B);
		packet.addInt(player->getPlayerid());
		packet.addByte(mskill.types[0]);
		packet.addByte(mskill.types[1]);
		packet.addByte(mskill.types[2]);
		packet.addByte(mskill.types[3]);
		packet.addByte(mskill.types[4]);
		packet.addByte(mskill.types[5]);
		packet.addByte(mskill.types[6]);
		packet.addByte(mskill.types[7]);
		packet.sendTo(player, players, 0);

	}
}