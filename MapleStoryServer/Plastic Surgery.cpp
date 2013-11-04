#include "NPCs.h"
#include "NPCsScripts.h"
#include "Player.h"
#include "Levels.h"
#include "Players.h"
/* +Plastic Surgery NPCs - MapleStory
		+Party of Goofy's Cosmetic NPCs Mega Package
				+Written by Goofy (Of OdinMS)
						+TitanMS Source
								+Please at least give me credits for putting my time into this
										-No one likes a thief :D*/

//Ellie, Ludibrium Plastic Surgeon.
//Written by Goofy of OdinMS
//Please give me credits if you use this. Nobody likes a thief.
void NPCsScripts::npc_2041010(NPC* npc){
	int eyes[] = {20000, 20001, 20002, 20004, 20005, 20006, 20007, 20008, 20012, 20014};
	int eyes2[] = {21000, 21001, 21002, 21004, 22005, 22006, 22007, 22008, 22012, 22014};
	int state = npc->getState();
	Player* player = npc->getPlayer();
	if(state == 0){
		npc->addText("Let's see.... I can totally transform your face into something new. Don't you want to try it? ");
		npc->addText("For the #bLudibrium Face Coupon (VIP)#k, you can get the face of your liking. Take your time in choosing the face of your preference.");
		npc->addText("....");
		if(player->getGender() == 0){
		npc->sendStyle(eyes, 10);
		} 
		else {
		npc->sendStyle(eyes2, 10);
			}
	}
	if(state == 1){
		if(npc->getItemNum(5152007) >= 1){
			npc->giveItem(5150007, -1);
			if(player->getGender() == 0){
			npc->setStyle(eyes[npc->getSelected()]);
			}
			else {
		npc->setStyle(eyes2[npc->getSelected()]);
			}
			npc->end();
		}
		else{
			npc->addText("Hmm ... it looks like you don't have the coupon specifically for this place...sorry to say this, but without the coupon, there's no plastic surgery for you.");
			npc->sendNext();
			npc->end();
		}
	}
}
//Everton - Ludibrium Plastic Surgeon (REG)
//Written by Goofy - Please give me credits if you use this. No one likes a thief. :v
//Unsure about hair color changing atm. Will implement when figured out
/*void NPCsScripts::npc_2040019(NPC* npc){
	int eyes[] = {20000, 20001, 20002, 20004, 20005, 20006, 20007, 20008, 20012, 20014};
	int eyes2[] = {21000, 21001, 21002, 21004, 21005, 21006, 21007, 21008, 21012, 21014};
	int state = npc->getState();
	Player* player = npc->getPlayer();
	if(state == 0){
		npc->addText("If you use the regular coupon, your face may transform into a random new look... ");
		npc->addText("Do you still want to use the #bLudibrium Face Coupon (REG)#k?");
		npc->sendYesNo();
	}
	if(state == 1){
	int eyes[] = {20000, 20001, 20002, 20004, 20005, 20006, 20007, 20008, 20012, 20014};
		if(npc->getSelected() == YES){
			if(npc->getItemNum(5152006) >= 1){
				npc->giveItem(5152006, -1);
				if(player->getGender() == 0){
			int random = rand()% 10 + 1;
			if(random == 1){
				npc->setStyle(eyes[20000]);}
			if(random == 2){
				npc->setStyle(eyes[20001]);}
			if(random == 3){
				npc->setStyle(eyes[20002]);}
			if(random == 4){
				npc->setStyle(eyes[20003]);}
			if(random == 5){
				npc->setStyle(eyes[20004]);}
			if(random == 6){
				npc->setStyle(eyes[20006]);}
			if(random == 7){
				npc->setStyle(eyes[20007]);}
			if(random == 8){
				npc->setStyle(eyes[20008]);}
			if(random == 9){
				npc->setStyle(eyes[20012]);}
			if(random == 10){
				npc->setStyle(eyes[20014]);}
			npc->end();
				}
				else
				{
			int random = rand()% 10 + 1;
			if(random == 1){
				npc->setStyle(eyes[21000]);}
			if(random == 2){
				npc->setStyle(eyes[21001]);}
			if(random == 3){
				npc->setStyle(eyes[21002]);}
			if(random == 4){
				npc->setStyle(eyes[21003]);}
			if(random == 5){
				npc->setStyle(eyes[21004]);}
			if(random == 6){
				npc->setStyle(eyes[21006]);}
			if(random == 7){
				npc->setStyle(eyes[21007]);}
			if(random == 8){
				npc->setStyle(eyes[21008]);}
			if(random == 9){
				npc->setStyle(eyes[21012]);}
			if(random == 10){
				npc->setStyle(eyes[21014]);}
			npc->end();
				}
			}
			else{
			npc->addText("Hmm ... it looks like you don't have the coupon specifically for this place...sorry to say this, but without the coupon, there's no plastic surgery for you.");
			npc->sendNext();
			npc->end();
			}
		}
		else{
			npc->addText("I see ... take your time, see if you really want it. Let me know when you make up your mind.");
			npc->sendNext();
			npc->end();
		}
	}
}*/



/*Denma the Owner - Henesys Plastic Surgeon (VIP)*/
//Written by Goofy of OdinMS. If you use it, please give me credit.
//Nobody likes a thief.			*/
void NPCsScripts::npc_1052004(NPC* npc){
	int eyes[] = {20000, 20001, 20002, 20003, 20004, 20006, 20007, 20008, 20012, 20013};
	int eyes2[] = {21000, 21001, 21002, 21003, 21004, 21006, 21007, 21008, 21012, 21013};
	int state = npc->getState();
	Player* player = npc->getPlayer();
	if(state == 0){
		npc->addText("Let's see.... I can totally transform your face into something new. Don't you want to try it? ");
		npc->addText("For the #bHenesys Face Coupon (VIP)#k, you can get the face of your liking. Take your time in choosing the face of your preference.");
		npc->addText("....");
		if(player->getGender() == 0){
		npc->sendStyle(eyes, 10);
		} 
		else {
		npc->sendStyle(eyes2, 10);
			}
	}
	if(state == 1){
		if(npc->getItemNum(5152001) >= 1){
			npc->giveItem(5152001, -1);
			if(player->getGender() == 0){
			npc->setStyle(eyes[npc->getSelected()]);
			}
			else {
		npc->setStyle(eyes2[npc->getSelected()]);
			}
			npc->end();
		}
		else{
			npc->addText("Hmm ... it looks like you don't have the coupon specifically for this place...sorry to say this, but without the coupon, there's no plastic surgery for you.");
			npc->sendNext();
			npc->end();
		}
	}
}
/*Dr. Feeble - Henesys Plastic Surgeon (REG)*/
//Written by Goofy of OdinMS. If you use it, please give me credit.
//Nobody likes a thief.

void NPCsScripts::npc_1052005(NPC* npc){
 int eyes[] = {20000, 20001, 20002, 20003, 20004, 20006, 20007, 20008, 20012, 20013};
 int eyes2[] = {21000, 21001, 21002, 21003, 21004, 21006, 21007, 21008, 21012, 21013};
 int state = npc->getState();
 Player* player = npc->getPlayer();
 if(state == 0){
  npc->addText("If you use the regular coupon, your face may transform into a random new look. ");
  npc->addText("Do you still want to use the #bHenesys Face Coupon (REG)#k?");
  npc->sendYesNo();
 }
 if(state == 1){
  if(npc->getSelected() == YES){
   if(npc->getItemNum(5152000) >= 1){
    npc->giveItem(5152000, -1);
	if(player->getGender() == 0){
   int random = rand()% 10 + 1;
    npc->setStyle(eyes[random-1]);
	}
	else {
	   int random = rand()% 10 + 1;
    npc->setStyle(eyes2[random-1]);
	}
   npc->end();
   }
   else {
   npc->addText("Hmm ... it looks like you don't have the coupon specifically for this place...sorry to say this, but without the coupon, there's no plastic surgery for you.");
   npc->sendNext();
   npc->end();
   }
  }
   else{
   npc->addText("Hmm ... it looks like you don't have the coupon specifically for this place...sorry to say this, but without the coupon, there's no plastic surgery for you.");
   npc->sendNext();
   npc->end();
   }
 }

}


//Franz the owner
//Written by Goofy of OdinMS
//Please give me credits if you use this. Nobody likes a thief.
void NPCsScripts::npc_2010002(NPC* npc){
	int eyes[] = {20000, 20001, 20002, 20004, 20005, 20006, 20007, 20008, 20009, 20010};
	int eyes2[] = {21000, 21001, 21002, 21004, 21005, 21006, 20007, 21008, 21009, 21010};
	int state = npc->getState();
	Player* player = npc->getPlayer();
	if(state == 0){
		npc->addText("Well well well, welcome!! I can totally transform your face into something new.... How about giving us a try? ");
		npc->addText("For the #bOrbis Face Coupon (VIP)#k, you can get the face of your liking. Take your time in choosing the face of your preference.");
		npc->addText("....");
		if(player->getGender() == 0){
		npc->sendStyle(eyes, 10);
		}
		else {
		npc->sendStyle(eyes2, 10);
		}
	}
	if(state == 1){
		if(npc->getItemNum(5152005) >= 1){
			npc->giveItem(5152005, -1);
						if(player->getGender() == 0){
			npc->setStyle(eyes[npc->getSelected()]);
			}
			else {
		npc->setStyle(eyes2[npc->getSelected()]);
			}
			npc->end();
		}
		else{
			npc->addText("Hmm ... it looks like you don't have the coupon specifically for this place...sorry to say this, but without the coupon, there's no plastic surgery for you.");
			npc->sendNext();
			npc->end();
		}
	}
}

void NPCsScripts::npc_9200100(NPC* npc){  // Henesys VIP EYE
	int state = npc->getState();
	Player* player = npc->getPlayer();
	int eyes[] = {20000, 20001, 20002, 20003, 20004, 20005, 20006, 20007, 20008, 20009, 20010, 20011, 20012, 20013, 20014, 20016, 20017, 20018, 20019, 20020, 20021, 20022, 20023};
	int eyes2[] = {21000, 21001, 21002, 21003, 21004, 21005, 21006, 21007, 21008, 21009, 21010, 21011, 21012, 21013, 21014, 21016, 21017, 21018, 21019, 21020, 21022};
	if(state == 0){
		npc->addText("Welcome, welcome, welcome to the Henesys Cosmetic Lens Department!");
		npc->addText("Do you, by any chance, have the #bHenesys Cosmetic Lens Coupon (VIP)#k? ");
		npc->addText("If so, how about letting me take care of your eyes? I can make you as sexy as any anime character.\r\n");
		npc->addText("#L0#Use a Cosmetic Lens (VIP Coupon)#l");
		npc->sendSimple();
	}
	else if(state == 1){
					int type = npc->getSelected();
		npc->setVariable("type", type);
		if(type == 0){
			if(npc->getItemNum(5152013) >= 1){
				if(player->getGender() == 0){
			int cur = npc->getPlayerEyes()%100+20000;
			int colors[] = {cur, cur+100, cur+200, cur+300, cur+400, cur+500, cur+600, cur+700};
			npc->sendStyle(colors, 8);
				} else {
			int cur2 = npc->getPlayerEyes()%100+21000;
			int colors2[] = {cur2, cur2+100, cur2+200, cur2+300, cur2+400, cur2+500, cur2+600, cur2+700};
			npc->sendStyle(colors2, 8);
				}
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
			
			npc->giveItem(5152013, -1);
			if(player->getGender() == 0){
			npc->setStyle(20000+npc->getPlayerEyes()%100 + npc->getSelected()*100);
			} else {
			npc->setStyle(21000+npc->getPlayerEyes()%100 + npc->getSelected()*100);
			}
		}
			else
			if(player->getGender() == 0){
			npc->setStyle(eyes[npc->getSelected()]);
			} else {
				npc->setStyle(eyes2[npc->getSelected()]);
			}
	}
}