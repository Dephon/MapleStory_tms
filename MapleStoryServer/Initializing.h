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

#ifndef INITIALIZE_H
#define INITIALIZE_H

class Initializing {
public:
	static void initializing();
	static void initializeMobs();
	static void initializeNPCs();
	static void initializeDrops();
	static void initializeMaps();
	static void initializeEquips();
	static void initializeShops();
	static void initializeItems();
	static void initializeQuests();
	static void initializeSkills();
	static void initializeDrop(char* name);
	static void initializeMap(char* name);
	static void initializeNPC(char* name);
	static void initializeMob(char* name);
	static void initializeEquip(char* name);
	static void initializeShop(char* name);
	static void initializeItem(char* name);
	static void initializeQuest(char* name);
	static void initializeSkill(char* name);
};

#endif