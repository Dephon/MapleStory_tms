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

#include "LoginPacket.h"
#include <string.h>
#include "PlayerLogin.h"
#include "PacketCreator.h"
#include "Worlds.h"
#include "Characters.h" 

short getShort(unsigned char* buf){
	return buf[0] + buf[1]*0x100;
}

int getInt(unsigned char* buf){
	return buf[0] + buf[1]*0x100 + buf[2]*0x100*0x100 + buf[3]*0x100*0x100*0x100;
}

void getString(unsigned char* buf, int len, char* out){
	strncpy_s(out, len+1, (const char*)buf, len); 
}

void LoginPacket::loginError(PlayerLogin* player, short errorid){
	Packet packet;
	packet.addHeader(0x00);
	packet.addShort(errorid);
	packet.addInt(0);
	packet.send(player);
}

void LoginPacket::loginConnect(PlayerLogin* player, char* username, int size){
	Packet packet;
	packet.addHeader(0x00);
	packet.addInt(0);
	packet.addShort(0);
	packet.addBytes("2A7949");
	packet.addByte(0);
	if(player->getStatus() == 1)
		packet.addByte(0x0A);
	else
		packet.addByte(player->getGender());
	packet.addBytes("0465");
	packet.addShort(size);
	packet.addString(username, size);
	packet.addInt(0);
	packet.addInt(0);
	packet.addBytes("000000A6B89C2B4CC701");
    packet.addInt(0);
	packet.send(player);
}

void LoginPacket::loginProcess(PlayerLogin* player, char id){
	Packet packet;
	packet.addHeader(0x0d);
	packet.addByte(id);
	packet.send(player);
}

void LoginPacket::processOk(PlayerLogin* player){
	Packet packet;
	packet.addHeader(0x06);
	packet.addByte(0);
	packet.send(player);

}

void LoginPacket::showWorld(PlayerLogin* player, World world){
	Packet packet;
	packet.addHeader(0x05);
	packet.addByte(world.id);
	packet.addShort(strlen(world.name));
	packet.addString(world.name, strlen(world.name));
	packet.addByte(0); //Type 2-new
	packet.addShort(0);
	packet.addShort(100);
	packet.addByte(100);
	packet.addShort(0);
	packet.addByte(world.channels);
	for(int i=0; i<world.channels; i++){
		char channelname[15];
		strcpy_s(channelname, 15, world.name);
		strcat_s(channelname, 15, "-");
		char cid[15]={0};
		cid[0] = i+'1';
		strcat_s(channelname, 15, cid);
		packet.addShort(strlen(channelname));
		packet.addString(channelname, strlen(channelname));
		packet.addInt(0x0); // Pop
		packet.addByte(world.id);
		packet.addShort(i);
	}
	packet.send(player);
}

void LoginPacket::worldEnd(PlayerLogin* player){
	Packet packet;
	packet.addHeader(0x05);
	packet.addByte(0xFF);
	packet.send(player);
}

void LoginPacket::showChannels(PlayerLogin* player){
	Packet packet;
	packet.addHeader(0x12);
	packet.addShort(0x00);
	packet.send(player);
}

void LoginPacket::channelSelect(PlayerLogin* player){
	Packet packet;
	/*
	packet.addHeader(0x10);
	packet.addBytes("000500001040008612340097227400");
	packet.addInt(4);
	packet.addBytes("9F227400"); 
	packet.addInt(4);
	packet.addBytes("AC227400544D0500F073790028BC0000");
	packet.send(player);
	*/
}

void LoginPacket::showCharacters(PlayerLogin* player, vector <Character> chars){
	Packet packet;
	packet.addHeader(0x13);
	packet.addByte(0);
	packet.addByte(chars.size());
	for(int i=0; i<(int)chars.size(); i++){
		packet.addInt(chars[i].id);
		packet.addString(chars[i].name, 12);
		packet.addByte(0);
		packet.addByte(chars[i].gender);
		packet.addByte(chars[i].skin);
		packet.addInt(chars[i].eyes);
		packet.addInt(chars[i].hair);
		packet.addInt(0);
		packet.addInt(0);
		packet.addInt(0);
		packet.addInt(0);
		packet.addInt(0);
		packet.addInt(0);
		packet.addByte(chars[i].level);
		packet.addShort(chars[i].job);
		packet.addShort(chars[i].str);
		packet.addShort(chars[i].dex);
		packet.addShort(chars[i].intt);
		packet.addShort(chars[i].luk);
		packet.addShort(chars[i].hp);
		packet.addShort(chars[i].mhp);
		packet.addShort(chars[i].mp);
		packet.addShort(chars[i].mmp);
		packet.addShort(chars[i].ap);
		packet.addShort(chars[i].sp);
		packet.addInt(chars[i].exp);
		packet.addShort(chars[i].fame);
		packet.addInt(chars[i].map);
		packet.addByte(chars[i].pos);
		packet.addByte(chars[i].gender);
		packet.addByte(chars[i].skin);
		packet.addInt(chars[i].eyes);
		packet.addByte(1);
		packet.addInt(chars[i].hair);
		for(int j=0; j<(int)chars[i].equips.size(); j++){
			packet.addByte(chars[i].equips[j].type);
			packet.addInt(chars[i].equips[j].id);
		}
		packet.addShort(-1);
		packet.addInt(0);
		packet.addInt(0);
		packet.addInt(0);
		packet.addInt(0);
		packet.addByte(0);
	}
	packet.send(player);
}

void LoginPacket::checkName(PlayerLogin* player, char is, char* name){
	Packet packet;
	packet.addHeader(0x06);
	packet.addShort(strlen(name));
	packet.addString(name, strlen(name));
	packet.addByte(is);
	packet.send(player);
}

void LoginPacket::showCharacter(PlayerLogin* player, Character charc){
	Packet packet;
	packet.addHeader(0x07);
	packet.addByte(0);
	packet.addInt(charc.id);
	packet.addString(charc.name, 12);
	packet.addByte(0);
	packet.addByte(charc.gender);
	packet.addByte(charc.skin);
	packet.addInt(charc.eyes);
	packet.addInt(charc.hair);
	packet.addInt(0);
	packet.addInt(0);
	packet.addInt(0);
	packet.addInt(0);
	packet.addInt(0);
	packet.addInt(0);
	packet.addByte(charc.level);
	packet.addShort(charc.job);
	packet.addShort(charc.str);
	packet.addShort(charc.dex);
	packet.addShort(charc.intt);
	packet.addShort(charc.luk);
	packet.addShort(charc.hp);
	packet.addShort(charc.mhp);
	packet.addShort(charc.mp);
	packet.addShort(charc.mmp);
	packet.addShort(charc.ap);
	packet.addShort(charc.sp);
	packet.addInt(charc.exp);
	packet.addShort(charc.fame);
	packet.addInt(charc.map);
	packet.addByte(charc.pos);
	packet.addByte(charc.gender);
	packet.addByte(charc.skin);
	packet.addInt(charc.eyes);
	packet.addByte(1);
	packet.addInt(charc.hair);
	for(int j=0; j<(int)charc.equips.size(); j++){
		packet.addByte(charc.equips[j].type);
		packet.addInt(charc.equips[j].id);
	}
	packet.addShort(-1);
	packet.addInt(0);
	packet.addInt(0);
	packet.addInt(0);
	packet.addInt(0);
	packet.addInt(0);
	packet.addInt(0);
	packet.addByte(0);
	packet.send(player);	
}

void LoginPacket::deleteCharacter(PlayerLogin* player, int ID){
	Packet packet;
	packet.addHeader(0x08);
	packet.addInt(ID);
	packet.addByte(0);
	packet.send(player);
}

void LoginPacket::connectIP(PlayerLogin* player, int charid){
	Packet packet;
	packet.addHeader(0x04);
	packet.addShort(0); // IP
	
	packet.addByte(127); // IP
	packet.addByte(0);
	packet.addByte(0);
	packet.addByte(1);

	packet.addShort(8888 + player->getChannel());
	packet.addInt(charid);
	packet.addInt(0);
	packet.addByte(0);
	packet.send(player);
}


void LoginPacket::logBack(PlayerLogin* player){
	Packet packet;
	packet.addHeader(0x13);
	packet.addByte(1);
	packet.send(player);
}