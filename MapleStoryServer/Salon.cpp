#include "NPCs.h"
#include "NPCsScripts.h"
#include "Player.h"
#include "Levels.h"
#include "Players.h"
/* Hair Stylist NPCs - MapleStory
		Party of Goofy's Cosmetic NPCs Mega Package
				Written by Goofy
						TitanMS Source
								Please at least give me credits for putting my time into this
										No one likes a thief :D*/

/* Begin Henesys Hair Stylist NPCs*/
//Brittany - Henesys Random Hair Stylist, Natalie's Assistant.
void NPCsScripts::npc_1012104(NPC* npc){
	int hairs[] = {30030, 30020, 30000, 30480, 30310, 30330, 30060, 30150, 30410, 30210, 30140, 30120, 30200, 30560, 30510};
	int hairs2[] = {31050, 31040, 31000, 31150, 31310, 31300, 31160, 31100, 31410, 31030, 31080, 31070, 31610, 31350, 31510};
	int hairscolor[] = {8, 1, 8, 8, 8, 8, 8, 1, 1, 1, 5, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
	int state = npc->getState();
		if(state == 0){
			Player* player = npc->getPlayer();
			npc->addText("I'm Brittany the assistant. If you have the #bHenesys Hair Style Coupon (EXP)#k ");
			npc->addText("or the #bHenesys Hair Color Coupon (REG)#k by any chance, then how about you let me change your hairdo?");
			npc->sendYesNo();
		}
	else if(state == 1){
		if(npc->getSelected() == YES){
			npc->addText("Great! Just tell me what you'd like done and I'll get right on it!\r\n");
			npc->addText("#L0##bHaircut (REG Coupon)#k#l\r\n");
			npc->addText("#L1##bDye your hair (REG Coupon)#k#l");
			npc->sendSimple();
		}
		else{
			npc->addText("I understand... Come back to me if you decide you want your hair changed!");
			npc->sendOK();
			npc->end();
		}
	}
		int type = npc->getSelected();
		Player* player = npc->getPlayer();
		npc->setVariable("type", type);
		if(state == 2 && type == 0){
			if(npc->getItemNum(5150010) >= 1){
				npc->giveItem(5150010, -1);
				if(player->getGender() == 0){
				npc->addText("Enjoy your new hairstyle! It looks great on you!");
				int random = rand()% 11 + 1;
				if(random == 1){
					npc->setStyle(30510);}
				if(random == 2){
					npc->setStyle(30140);}
				if(random == 3){
					npc->setStyle(30480);}
				if(random == 4){
					npc->setStyle(30020);}
				if(random == 5){
					npc->setStyle(30200);}
				if(random == 6){
					npc->setStyle(30120);}
				if(random == 7){
					npc->setStyle(30410);}
				if(random == 8){
					npc->setStyle(30060);}
				if(random == 9){
					npc->setStyle(30210);}
				if(random == 10){
					npc->setStyle(30030);}
				if(random == 11){
					npc->setStyle(30150);}
				npc->sendOK();
				}
			else{
				npc->addText("Enjoy your new hairstyle! It looks great on you!");
				int random = rand()% 11 + 1;
				if(random == 1){
					npc->setStyle(31050);}
				if(random == 2){
					npc->setStyle(31040);}
				if(random == 3){
					npc->setStyle(31000);}
				if(random == 4){
					npc->setStyle(31150);}
				if(random == 5){
					npc->setStyle(31310);}
				if(random == 6){
					npc->setStyle(31300);}
				if(random == 7){
					npc->setStyle(31160);}
				if(random == 8){
					npc->setStyle(31100);}
				if(random == 9){
					npc->setStyle(31610);}
				if(random == 10){
					npc->setStyle(31350);}
				if(random == 11){
					npc->setStyle(31510);}
				npc->sendOK();
				}
			}
			else{
			npc->addText("Hmmm.... it looks like you don't have our designated coupon. ");
			npc->addText("I'm afraid I can't give you a haircut without it. I'm sorry.");
			npc->sendNext();
			}
			npc->end();
		}
		if(state == 2 && type == 1){
			if(npc->getItemNum(5151000) >= 1){
				npc->addText("Enjoy your new hairstyle! It looks wonderful on you!");
				npc->giveItem(5151000, -1);
				int random = rand()% 4 + 1;
				if(random == 1){
					npc->setStyle(npc->getPlayerHair()/10*10);}
				if(random == 2 ){
					npc->setStyle(npc->getPlayerHair()/10*10);}
				if(random == 3){
					npc->setStyle(npc->getPlayerHair()/10*10);}
				if(random == 4){
					npc->setStyle(npc->getPlayerHair()/10*10);}
				npc->sendNext();
			}
			else{
			npc->addText("Hmmm.... it looks like you don't have our designated coupon. ");
			npc->addText("I'm afraid I can't give you a haircut without it. I'm sorry.");
				npc->sendOK();
			}
			npc->end();
		}
}
//Natalie - Henesys Hair Salon VIP Hair Stylist.
void NPCsScripts::npc_1012103(NPC* npc){
	Player* player = npc->getPlayer();
	int state = npc->getState();
	int hairs[] = {30030, 30020, 30000, 30480, 30310, 30330, 30060, 30150, 30410, 30210, 30140, 30120, 30200};
	int hairs2[] = {31050, 31040, 31000, 31150, 31310, 31300, 31160, 31100, 31410, 31030, 31080, 31070, 31610, 31350, 31510};
	int hairscolor[] = {8, 1, 8, 8, 8, 8, 8, 1, 1, 1, 5, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
	if(state == 0){
		npc->addText("I'm the head of this hair salon, Natalie. If you have a #bHenesys Hair Style Coupon(VIP)#k or a ");
		npc->addText("#bHenesys Hair Color Coupon(VIP)#k, allow me to take care of your hairdo. Please choose the one you want.\r\n");
		npc->addText("#L0##bHaircut (VIP Coupon)#k\r\n#l");
		npc->addText("#L1##bDye your hair (VIP Coupon)#k#l");
		npc->sendSimple();
	}
	else if(state == 1){
		int type = npc->getSelected();
		npc->setVariable("type", type);
		if(type == 0){
			if(npc->getItemNum(5150001) >= 1){
				if(player->getGender() == 0){
			npc->sendStyle(hairs, 13);
				}
				else{
					npc->sendStyle(hairs2, 12);
				}
			}
		else{
			npc->addText("Hmmm.... it looks like you don't have our designated coupon. ");
			npc->addText("I'm afraid I can't give you a haircut without it. I'm sorry.");
			npc->sendNext();
			npc->end();
		}
		}
		else if(type == 1){
			if(npc->getItemNum(5151001) >= 1){
			int cur = npc->getPlayerHair()/10*10;
			int colors[] = {cur, cur+1, cur+2, cur+3, cur+4, cur+5, cur+6, cur+7};
			npc->sendStyle(colors, hairscolor[npc->getPlayerHair()%1000/10]);
			}
			else{
			npc->addText("Hmmm.... it looks like you don't have our designated coupon. I'm afraid I can't give you a haircut without it. I'm sorry.");
			npc->sendNext();
			npc->end();
			}
		}
	}
	else if(state == 2){
		npc->end();
		int type = npc->getVariable("type");
		if(type == 0){
			npc->giveItem(5150001, -1);
			if(player->getGender() == 0){
			npc->setStyle(hairs[npc->getSelected()]);
			}
			else {
				npc->setStyle(hairs2[npc->getSelected()]);
			}
		}
		else if(type == 1){
			npc->giveItem(5151001, -1);
			npc->setStyle(npc->getPlayerHair()/10*10+ npc->getSelected());
		}
	}
}
/*End Henesys Hair Stylist NPCs*/
/*Begin Kerning City Hair Stylist NPCs*/
//Don Giovanni - Kerning City Salon VIP Hair Stylist~
void NPCsScripts::npc_1052100(NPC* npc){
	int state = npc->getState();
	Player* player = npc->getPlayer();
	int hairs[] = {30030, 30020, 30000, 30130, 30350, 30190, 30110, 30180, 30050, 30040, 30160, 30520, 30550, 30620};
	int hairs2[] = {31050, 31040, 31000, 31060, 31090, 31020, 31130, 31120, 31140, 31330, 31010, 31520, 31620, 31440};
	int hairscolor[] = {8, 1, 8, 8, 8, 8, 8, 1, 1, 1, 5, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
	if(state == 0){
		npc->addText("Hello! I'm Don Giovanni, head of the beauty salon! If you have either the #bKerning City Hair Style Coupon (VIP)#k, ");
		npc->addText("#bKerning City Hair Color Coupon (VIP)#k, why don't you let me take care of the rest? Decide what you want to do with your hair....\r\n");
		npc->addText("#L0##bChange Hairstyle (VIP Coupon)#k\r\n#l");
		npc->addText("#L1##bDye your hair (VIP Coupon)#k#l");
		npc->sendSimple();
	}
	else if(state == 1){
		int type = npc->getSelected();
		npc->setVariable("type", type);
		if(type == 0){
			if(npc->getItemNum(5150003) >= 1){
				if(player->getGender() == 0){
			npc->sendStyle(hairs, 11);
				}
				else{
					npc->sendStyle(hairs2, 11);
				}
			}
		else{
			npc->addText("Hmmm.... it looks like you don't have our designated coupon. ");
			npc->addText("I'm afraid I can't give you a haircut without it. ");
			npc->addText("Can't give you a haircut without it. Sorry, bud.");
			npc->sendNext();
			npc->end();
		}
		}
		else if(type == 1){
			if(npc->getItemNum(5151003) >= 1){
			int cur = npc->getPlayerHair()/10*10;
			int colors[] = {cur, cur+1, cur+2, cur+3, cur+4, cur+5, cur+6, cur+7};
			npc->sendStyle(colors, hairscolor[npc->getPlayerHair()%1000/10]);
			}
			else{
			npc->addText("Hmmm.... it looks like you don't have our designated coupon. I'm afraid I can't dye your hair without it. Sorry, bud.");
			npc->sendNext();
			npc->end();
			}
		}
	}
	else if(state == 2){
		npc->end();
		int type = npc->getVariable("type");
		if(type == 0){
			npc->giveItem(5150003, -1);
			if(player->getGender() == 0){
			npc->setStyle(hairs[npc->getSelected()]);
			}
			else {
				npc->setStyle(hairs2[npc->getSelected()]);
			}
		}
		else if(type == 1){
			npc->giveItem(5151003, -1);
			npc->setStyle(npc->getPlayerHair()/10*10+ npc->getSelected());
		}
	}
}
//Andres - Kerning City Salon Assistant/ Random Hairstylist
void NPCsScripts::npc_1052101(NPC* npc){
	Player* player = npc->getPlayer();
	int state = npc->getState();
	int hairs[] = {30030, 30020, 30000, 30130, 30350, 30190, 30110, 30180, 30050, 30040, 30160, 30520, 30550, 30620};
	int hairs2[] = {31050, 31040, 31000, 31060, 31090, 31020, 31130, 31120, 31140, 31330, 31010, 31520, 31620, 31440};
	int hairscolor[] = {8, 1, 8, 8, 8, 8, 8, 1, 1, 1, 5, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
	if(state == 0){
			Player* player = npc->getPlayer();
			npc->addText("I'm Andres, Don's assistant. Everyone calls me Andre, though. ");
			npc->addText("If you have the #bKerning City Hair Style Coupon (EXP)#k or the #bKerning City Hair Color Coupon (REG)#k ");
			npc->addText(", then I must ask if you'd like me to give you a new hairdo?");
			npc->sendYesNo();
		}
	else if(state == 1){
		if(npc->getSelected() == YES){
			npc->addText("Great! Just tell me what you'd like done and I'll get right on it!\r\n");
			npc->addText("#L0##bHaircut (EXP Coupon)#k#l\r\n");
			npc->addText("#L1##bDye your hair (REG Coupon)#k#l");
			npc->sendSimple();
		}
		else{
			npc->addText("I see....think about it a little more and if you want to do it, come talk to me.");
			npc->sendNext();
			npc->end();
		}
	}
		int type = npc->getSelected();
		npc->setVariable("type", type);
		if(state == 2 && type == 0){
			if(npc->getItemNum(5150011) >= 1){
				npc->giveItem(5150011, -1);
				npc->addText("Enjoy your new hairstyle! It looks great on you!");
				if(player->getGender() ==  0){
				int random = rand()% 11 + 1;
				if(random == 1){
					npc->setStyle(30030);}
				if(random == 2){
					npc->setStyle(30040);}
				if(random == 3){
					npc->setStyle(30620);}
				if(random == 4){
					npc->setStyle(30520);}
				if(random == 5){
					npc->setStyle(30350);}
				if(random == 6){
					npc->setStyle(30520);}
				if(random == 7){
					npc->setStyle(30350);}
				if(random == 8){
					npc->setStyle(30130);}
				if(random == 9){
					npc->setStyle(30050);}
				if(random == 10){
					npc->setStyle(30020);}
				if(random == 11){
					npc->setStyle(30000);}
				npc->sendOK();
				}
							else{
			int random = rand()% 11 + 1;
				if(random == 1){
					npc->setStyle(31050);}
				if(random == 2){
					npc->setStyle(31040);}
				if(random == 3){
					npc->setStyle(31520);}
				if(random == 4){
					npc->setStyle(31620);}
				if(random == 5){
					npc->setStyle(31440);}
				if(random == 6){
					npc->setStyle(31010);}
				if(random == 7){
					npc->setStyle(31120);}
				if(random == 8){
					npc->setStyle(31020);}
				if(random == 9){
					npc->setStyle(30050);}
				if(random == 10){
					npc->setStyle(31000);}
				if(random == 11){
					npc->setStyle(31060);}
				npc->sendOK();
							}
				
			}
			else{
			npc->addText("Hmmm....are you sure you have our designated coupon? ");
			npc->addText("Sorry but no haircut without it.");
			npc->sendNext();
			}
			npc->end();
		}
		if(state == 2 && type == 1){
			if(npc->getItemNum(5151002) >= 1){
				npc->addText("Enjoy your new hairstyle! It looks wonderful on you!");
				npc->giveItem(5151002, -1);
				int random = rand()% 4 + 1;
				if(random == 1){
					npc->setStyle(npc->getPlayerHair()/10*10);}
				if(random == 2 ){
					npc->setStyle(npc->getPlayerHair()/10*10);}
				if(random == 3){
					npc->setStyle(npc->getPlayerHair()/10*10);}
				if(random == 4){
					npc->setStyle(npc->getPlayerHair()/10*10);}
				npc->sendNext();
			}
			else{
			npc->addText("Hmmm....are you sure you have our designated coupon? ");
			npc->addText("Sorry but no haircut without it.");
			npc->sendNext();
			}
			npc->end();
		}
}
/*End Kerning CityHair Stylist NPCs*/
/*Begin Ludibrium Hair Stylist NPCs*/
//Miyu - Ludibrium VIP Hair Stylist
void NPCsScripts::npc_2041007(NPC* npc){
	int state = npc->getState();
	Player* player = npc->getPlayer();
	int hairs[] = {30030, 30020, 30000, 30660, 30250, 30190, 30150, 30050, 30280, 30240, 30300, 30160, 30540, 30640, 30650};
	int hairs2[] = {31030, 31040, 31000, 31150, 31280, 31160, 31120, 31290, 31270, 31230, 31010, 31680, 31540, 31640, 31650};
	int hairscolor[] = {8, 1, 8, 8, 8, 8, 8, 1, 1, 1, 5, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
	if(state == 0){
		npc->addText("Welcome, welcome, welcome to the Ludibrium Hair Salon!");
		npc->addText("Do you, by any chance, have the #bLudibrium Hair Style Coupon (VIP)#k, or #bLudibrium Hair Color Coupon (VIP)#k? ");
		npc->addText("If so, how about letting me take care of your hair? Please choose what you want me to do with it.\r\n");
		npc->addText("#L0##bChange hair style (VIP Coupon)#k\r\n#l");
		npc->addText("#L1##bDye your hair (VIP Coupon)#k#l");
		npc->sendSimple();
	}
	else if(state == 1){
		int type = npc->getSelected();
		npc->setVariable("type", type);
		if(type == 0){
			if(npc->getItemNum(5150007) >= 1){
				if(player->getGender() == 0){
			npc->sendStyle(hairs, 12);
				}
				else{
					npc->sendStyle(hairs2, 12);
				}
			}
		else{
			npc->addText("Hmmm.... it looks like you don't have our designated coupon. ");
			npc->addText("I'm afraid I can't give you a haircut without it. I'm sorry.");
			npc->sendNext();
			npc->end();
		}
		}
		else if(type == 1){
			if(npc->getItemNum(5151007) >= 1){
				npc->giveItem(5151007, -1);
			int cur = npc->getPlayerHair()/10*10;
			int colors[] = {cur, cur+1, cur+2, cur+3, cur+4, cur+5, cur+6, cur+7};
			npc->sendStyle(colors, hairscolor[npc->getPlayerHair()%1000/10]);
			}
			else{
			npc->addText("Hmmm.... it looks like you don't have our designated coupon. I'm afraid I can't give you a haircut without it.");
			npc->addText("I'm sorry.");
			npc->sendNext();
			npc->end();
			}
		}
	}
	else if(state == 2){
		npc->end();
		int type = npc->getVariable("type");
		if(type == 0){
			npc->giveItem(5150007, -1);
				if(player->getGender() == 0){
			npc->setStyle(hairs[npc->getSelected()]);
			}
			else {
				npc->setStyle(hairs2[npc->getSelected()]);
			}
		}
		else if(type == 1){
			npc->giveItem(5151007, -1);
			npc->setStyle(npc->getPlayerHair()/10*10+ npc->getSelected());
		}
	}
}


//Mini - Ludibrium Hair Salon Random Hair Stylist
void NPCsScripts::npc_2041009(NPC* npc){
	int hairs[] = {30030, 30020, 30000, 30660, 30250, 30190, 30150, 30050, 30280, 30240, 30300, 30160, 30540, 30640, 30650};
	int hairs2[] = {31030, 31040, 31000, 31150, 31280, 31160, 31120, 31290, 31270, 31230, 31010, 31680, 31540, 31640, 31650};
	int hairscolor[] = {8, 1, 8, 8, 8, 8, 8, 1, 1, 1, 5, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
	int state = npc->getState();
		if(state == 0){
			Player* player = npc->getPlayer();
			npc->addText("Hi, I'm the assistant here. Don't worry, I'm plenty good enough for this. ");
			npc->addText("If you have the #bLudibrium Hairstyle Coupon (EXP)#k or the #bLudibrium Hair Color Coupon (REG)#k ");
			npc->addText("by any chance, how about you let me take care of the rest, alright?");
			npc->sendYesNo();
		}
	else if(state == 1){
		if(npc->getSelected() == YES){
			npc->addText("Good now just tell me what you want and I'll do the job!\r\n");
			npc->addText("#L0##bHaircut (EXP Coupon)#k#l\r\n");
			npc->addText("#L1##bDye your hair (REG Coupon)#k#l");
			npc->sendSimple();
		}
		else{
			npc->addText("I see. Please think through it carefully, and if you still want it, then feel free to come talk to me.");
			npc->sendNext();
			npc->end();
		}
	}
		int type = npc->getSelected();
		npc->setVariable("type", type);
		Player* player = npc->getPlayer();
		if(state == 2 && type == 0){
			if(npc->getItemNum(5150012) >= 1){
				npc->giveItem(5150012, -1);
				if(player->getGender() == 0){
				npc->addText("Enjoy your new hairstyle! It looks great on you!");
				int random = rand()% 11 + 1;
				if(random == 1){
					npc->setStyle(30510);}
				if(random == 2){
					npc->setStyle(30140);}
				if(random == 3){
					npc->setStyle(30480);}
				if(random == 4){
					npc->setStyle(30020);}
				if(random == 5){
					npc->setStyle(30200);}
				if(random == 6){
					npc->setStyle(30120);}
				if(random == 7){
					npc->setStyle(30410);}
				if(random == 8){
					npc->setStyle(30060);}
				if(random == 9){
					npc->setStyle(30210);}
				if(random == 10){
					npc->setStyle(30030);}
				if(random == 11){
					npc->setStyle(30150);}
				npc->sendOK();
				} else {
									npc->addText("Enjoy your new hairstyle! It looks great on you!");
				int random = rand()% 13 + 1;
				if(random == 1){
					npc->setStyle(31030);}
				if(random == 2){
					npc->setStyle(31040);}
				if(random == 3){
					npc->setStyle(31000);}
				if(random == 4){
					npc->setStyle(31150);}
				if(random == 5){
					npc->setStyle(31280);}
				if(random == 6){
					npc->setStyle(31160);}
				if(random == 7){
					npc->setStyle(31120);}
				if(random == 8){
					npc->setStyle(31290);}
				if(random == 9){
					npc->setStyle(31270);}
				if(random == 10){
					npc->setStyle(31230);}
				if(random == 11){
					npc->setStyle(31010);}
				if(random == 12){
					npc->setStyle(31550);}
				if(random == 13){
					npc->setStyle(31600);}
				}
			}
			else{
			npc->addText("Hmmm.... it looks like you don't have our designated coupon. ");
			npc->addText("I'm afraid I can't give you a haircut without it. I'm sorry.");
			npc->sendNext();
			}
			npc->end();
		}
		if(state == 2 && type == 1){
			if(npc->getItemNum(5151006) >= 1){
				npc->addText("Enjoy your new hairstyle! It looks wonderful on you!");
				npc->giveItem(5151006, -1);
				int random = rand()% 4 + 1;
				if(random == 1){
					npc->setStyle(npc->getPlayerHair()/10*10);}
				if(random == 2 ){
					npc->setStyle(npc->getPlayerHair()/10*10);}
				if(random == 3){
					npc->setStyle(npc->getPlayerHair()/10*10);}
				if(random == 4){
					npc->setStyle(npc->getPlayerHair()/10*10);}
				npc->sendNext();
			}
			else{
			npc->addText("Hmmm.... it looks like you don't have our designated coupon. ");
			npc->addText("I'm afraid I can't give you a haircut without it. I'm sorry.");
				npc->sendOK();
			}
			npc->end();
		}
}/*End Ludibrium Hair Stylist NPCs*/

void NPCsScripts::npc_2010001(NPC* npc){
	int state = npc->getState();
	int hairs[] = {30030, 30020, 30000, 30230, 30260, 30280, 30240, 30290, 30270, 30340, 30530, 30630, 30370, 31220};
	int hairs2[] = {31030, 31020, 31000, 31230, 31260, 31280, 31240, 31290, 31270, 31340, 31530, 31630, 31370, 31220};
	int hairscolor[] = {8, 1, 8, 8, 8, 8, 8, 1, 1, 1, 5, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
	if(state == 0){
		npc->addText("Hello. I'm Mino, the owner of this salon.  If you have either an #bOrbis Hair Style Coupon(VIP)#k or an ");
		npc->addText("#bOrbis Hair Color Coupon(VIP)#k, then please allow me to take care of your hair. Choose what you want to do with it.\r\n");
		npc->addText("#L0##bHaircut (VIP Coupon)#k\r\n#l");
		npc->addText("#L1##bDye your hair (VIP Coupon)#k#l");
		npc->sendSimple();
	}
	else if(state == 1){
		int type = npc->getSelected();
		Player* player = npc->getPlayer();
		npc->setVariable("type", type);
		if(type == 0){
			if(npc->getItemNum(5150005) >= 1){
				if(player->getGender() == 0){
			npc->sendStyle(hairs, 11);
				}
				else{
					npc->sendStyle(hairs2, 11);
				}
			}
		else{
			npc->addText("Hmmm.... it looks like you don't have our designated coupon. ");
			npc->addText("I'm afraid I can't give you a haircut without it. I'm sorry.");
			npc->sendNext();
			npc->end();
		}
		}
		else if(type == 1){
			if(npc->getItemNum(5151005) >= 1){
			int cur = npc->getPlayerHair()/10*10;
			int colors[] = {cur, cur+1, cur+2, cur+3, cur+4, cur+5, cur+6, cur+7};
			npc->sendStyle(colors, hairscolor[npc->getPlayerHair()%1000/10]);
			}
			else{
			npc->addText("Hmmm.... it looks like you don't have our designated coupon. I'm afraid I can't give you a haircut without it. I'm sorry.");
			npc->sendNext();
			npc->end();
			}
		}
	}
	else if(state == 2){
		npc->end();
		int type = npc->getVariable("type");
		Player* player = npc->getPlayer();
		if(type == 0){
			npc->giveItem(5150005, -1);
						if(player->getGender() == 0){
			npc->setStyle(hairs[npc->getSelected()]);
			}
			else {
				npc->setStyle(hairs2[npc->getSelected()]);
			}
		}
		else if(type == 1){
			npc->giveItem(5151005, -1);
			npc->setStyle(npc->getPlayerHair()/10*10+ npc->getSelected());
		}
	}
}


//Rinz The Assistant - Orbis Hair Stylist (REG)
void NPCsScripts::npc_2012007(NPC* npc){
	int state = npc->getState();
	int hairs[] = {30030, 30020, 30000, 30230, 30260, 30280, 30240, 30290, 30270, 30340, 30530, 30630, 30370};
	int hairs2[] = {31030, 31020, 31000, 31230, 31260, 31280, 31240, 31290, 31270, 31340, 31530, 31630, 31370};
	int hairscolor[] = {8, 1, 8, 8, 8, 8, 8, 1, 1, 1, 5, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
	if(state == 0){
		npc->addText("I'm Rinz, the assistant here at the Orbis Hair Salon. Do you have an #bOrbis Hairstyle Coupon#k or #bOrbis Hair Color Coupon#k with you?  ");
			npc->addText("If you have the #bLudibrium Hairstyle Coupon (EXP)#k or the #bLudibrium Hair Color Coupon (REG)#k ");
			npc->addText("If so, what do you think about letting me take care of your hairdo?");
			npc->sendYesNo();
		}
	else if(state == 1){
		if(npc->getSelected() == YES){
			npc->addText("Good now just tell me what you want and I'll do the job!\r\n");
			npc->addText("#L0##bHaircut (EXP Coupon)#k#l\r\n");
			npc->addText("#L1##bDye your hair (REG Coupon)#k#l");
			npc->sendSimple();
		}
		else{
			npc->addText("I understand...think about it, and if you still feel like changing, please come talk to me.");
			npc->sendNext();
			npc->end();
		}
	}
		int type = npc->getSelected();
		npc->setVariable("type", type);
		Player* player = npc->getPlayer();
		if(state == 2 && type == 0){
			if(npc->getItemNum(5150004) >= 1){
				npc->giveItem(5150004, -1);
				if(player->getGender() == 0){
				npc->addText("Enjoy your new hairstyle! It looks great on you!");
				int random = rand()% 12 + 1;
				if(random == 1){
					npc->setStyle(30230);}
				if(random == 2){
					npc->setStyle(30140);}
				if(random == 3){
					npc->setStyle(30280);}
				if(random == 4){
					npc->setStyle(30020);}
				if(random == 5){
					npc->setStyle(30270);}
				if(random == 6){
					npc->setStyle(30120);}
				if(random == 7){
					npc->setStyle(30410);}
				if(random == 8){
					npc->setStyle(30060);}
				if(random == 9){
					npc->setStyle(30210);}
				if(random == 10){
					npc->setStyle(30030);}
				if(random == 11){
					npc->setStyle(30280);}
				if(random == 12){
					npc->setStyle(31220);}
				npc->sendOK();
				} else {
				npc->addText("Enjoy your new hairstyle! It looks great on you!");
				int random = rand()% 12 + 1;
				if(random == 1){
					npc->setStyle(31230);}
				if(random == 2){
					npc->setStyle(32140);}
				if(random == 3){
					npc->setStyle(31280);}
				if(random == 4){
					npc->setStyle(31020);}
				if(random == 5){
					npc->setStyle(31270);}
				if(random == 6){
					npc->setStyle(31120);}
				if(random == 7){
					npc->setStyle(31410);}
				if(random == 8){
					npc->setStyle(31060);}
				if(random == 9){
					npc->setStyle(31210);}
				if(random == 10){
					npc->setStyle(31030);}
				if(random == 11){
					npc->setStyle(31280);}
				if(random == 12){
					npc->setStyle(31220);}
				npc->sendOK();
				}
			}
			else{
			npc->addText("Hmmm.... it looks like you don't have our designated coupon. ");
			npc->addText("I'm afraid I can't give you a haircut without it. I'm sorry.");
			npc->sendNext();
			}
			npc->end();
		}
		if(state == 2 && type == 1){
			if(npc->getItemNum(5151004) >= 1){
				npc->addText("Enjoy your new hairstyle! It looks wonderful on you!");
				npc->giveItem(5151004, -1);
				int random = rand()% 4 + 1;
				if(random == 1){
					npc->setStyle(npc->getPlayerHair()/10*10);}
				if(random == 2 ){
					npc->setStyle(npc->getPlayerHair()/10*10);}
				if(random == 3){
					npc->setStyle(npc->getPlayerHair()/10*10);}
				if(random == 4){
					npc->setStyle(npc->getPlayerHair()/10*10);}
				npc->sendNext();
			}
			else{
			npc->addText("Hmmm.... it looks like you don't have our designated coupon. ");
			npc->addText("I'm afraid I can't give you a haircut without it. I'm sorry.");
				npc->sendOK();
			}
			npc->end();
		}
}