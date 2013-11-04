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

#include "Decoder.h"
#include "AESEncryption.h"
#include "MapleEncryption.h"

void Decoder::encrypt(unsigned char *buffer, int size){
	MapleEncryption::mapleEncrypt(buffer, size);
	int pos=0,first=1;
	while(size > pos){
		if(size>pos+1460-first*4){
			decryptofb(buffer+pos, Decoder::ivSend, 1460 - first*4);
		}
		else
			decryptofb(buffer+pos, Decoder::ivSend, size-pos);
		pos+=1460-first*4;
		if(first)
			first=0;
	}
} 
 
void Decoder::next(){
	MapleEncryption::nextIV(Decoder::ivSend);
}

void Decoder::decrypt(unsigned char *buffer, int size){
	decryptofb(buffer, Decoder::ivRecv, size);
	MapleEncryption::nextIV(Decoder::ivRecv); 
	MapleEncryption::mapleDecrypt(buffer, size);
}

void Decoder::createHeader (unsigned char* header, short size) {
	short a = ivSend[3]*0x100 + ivSend[2];
	a = a ^ -56;
	short b = a ^ size; 
	header[0] = a%0x100;
	header[1] = (a-header[0])/0x100;
	header[2] = b%0x100;
	header[3] = (b-header[2])/0x100;
}