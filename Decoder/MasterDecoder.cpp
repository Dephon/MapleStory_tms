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

#include "MasterDecoder.h"
#include "string.h"

void MasterDecoder::encrypt(unsigned char *buffer, int size){
	char key[] = "password";
	int j=0;
	for(int i=0; i<size; i++){
		buffer[i] ^= key[j%strlen(key)];
	}
} 

void MasterDecoder::decrypt(unsigned char *buffer, int size){
	encrypt(buffer, size);
}

void MasterDecoder::createHeader (unsigned char* header, short size) {
	(*(short*)header) = size;
}