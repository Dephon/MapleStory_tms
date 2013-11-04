#include "NPCs.h"
#include "NPCsScripts.h"
#include "Player.h"
#include "Levels.h"
#include "Players.h"
/* +Skin=Care NPCs - MapleStory
		+Party of Goofy's Cosmetic NPCs Mega Package
				+Written by Goofy (Of OdinMS)
						+TitanMS Source
								+Please at least give me credits for putting my time into this
										-No one likes a thief :D*/


/*Gina, Ludibrium Skin-Care*/
//Written by Goofy of OdinMS
//Please give me credits if you use this. Nobody likes a thief.
void NPCsScripts::npc_2041013(NPC* npc){
	int skins[] = {0, 1, 2, 3, 4};
	int state = npc->getState();
	if(state == 0){
		npc->addText("Oh, hello! Welcome to the Ludibrium Skin-Care! Are you interested in getting tanned and looking sexy? How about a beautiful, snow-white skin? ");
		npc->addText("If you have the #bLudibrium Skin Care Coupon#k, you can let us take care of the rest and have the kind of skin you've always dreamed of!");
		npc->sendNext();
	}
	if(state == 1){
		npc->addText("With our specialized machine, you can see the way you'll look after the treatment PRIOR to the procedure. ");
		npc->addText("What kind of look are you looking for? Go ahead and choose a style of your liking ~");
			npc->sendStyle(skins, 5);
	}
	if(state == 2){
		if(npc->getItemNum(5153002) >= 1){
			npc->giveItem(5153002, -1);
			npc->setStyle(skins[npc->getSelected()]);
			npc->end();
		}
		else{
			npc->addText("Hmm.. I don't think you have our skin-care coupon with you. ");
			npc->addText("Without the coupon, I'm afraid I can't do it for you.");
			npc->sendNext();
			npc->end();
		}
	}
}

//Ms. Tan - Henesys Skin-Care 
/*Written by Goofy
of OdinMS*/
void NPCsScripts::npc_1012105(NPC* npc){
	int skins[] = {0, 1, 2, 3, 4};
	int state = npc->getState();
	if(state == 0){
		npc->addText("Hello there, darling. You might think you look good now, but would you like to be #bgorgeous#k like me? ");
		npc->addText("With the #bHenesys Skin Coupon#k, you can let me take care of the rest and have the kind of skin you've always wanted.");
		npc->sendNext();
	}
	if(state == 1){
		npc->addText("With our specialized machine, you can see the way you'll look after the treatment PRIOR to the procedure. ");
		npc->addText("What kind of look are you looking for? Go ahead and choose a style of your liking ~");
			npc->sendStyle(skins, 5);
	}
	if(state == 2){
		if(npc->getItemNum(5153000) >= 1){
			npc->giveItem(5153000, -1);
			npc->setStyle(skins[npc->getSelected()]);
			npc->end();
		}
		else{
			npc->addText("I'm sorry, darling, but I can't give you a tan unless you have our designated coupon.");
			npc->addText("Come back later if you ever do get your hands on one. I'll be waiting~");
			npc->sendOK();
			npc->end();
		}
	}
}
/* Romi - Orbis Skin Care Center
	Written by Goofy of OdinMS
			TitanMS source-by koolk*/
void NPCsScripts::npc_2012008(NPC* npc){
	int skins[] = {0, 1, 2, 3, 4};
	int state = npc->getState();
	if(state == 0){
		npc->addText("Well, hello! Welcome to the Orbis Skin-Care center~! Would you like to have tight, firm skin like mine?");
		npc->addText("With the #bOrbis Skin Coupon#k, you can let us take care of the rest and have the kind of skin you've always wanted~!");
		npc->sendNext();
	}
	if(state == 1){
		npc->addText("With our specialized machine, you can see the way you'll look in advance. ");
		npc->addText("What kind of skin-treatment are you looking for? Go ahead and choose a style of your liking ~");
			npc->sendStyle(skins, 5);
	}
	if(state == 2){
		if(npc->getItemNum(5153001) >= 1){
			npc->giveItem(5153001, -1);
			npc->setStyle(skins[npc->getSelected()]);
			npc->end();
		}
		else{
			npc->addText("I'm sorry, darling, but I can't give you a tan unless you have our designated coupon.");
			npc->addText("Come back later if you ever do get your hands on one. I'll be waiting~");
			npc->sendOK();
			npc->end();
		}
	}
}