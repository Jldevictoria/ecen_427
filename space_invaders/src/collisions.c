/*
 * collisions.c
 *
 * Taylor Simons + Joseph DeVictoria
 * ECEN 425 Lab 3 aliens source.
 */

#include "globals.h"
#include <stdio.h>
#include <stdlib.h>

void tankCollision(int pixelHit){
	if (tankState == TANK_ALIVE){
		playerLives--;
	}
	clearLives(playerLives);
	tankState = TANK_DEAD_ONE;
	if(playerLives == 0){
		gameStatus = GAME_OVER;
	}
}

void bunkerCollision(int pixelHit){

	//find which bunker was hit
	int whichBunker = 0;
	int whichBlock = 0;
	int bunkGridX = 0;
	int bunkGridY = 0;
	if((pixelHit % 640) > (BUNK_SPACE*1+ BUNK_SHIFT- BUNKER_COLLISION_BUFFER)){
		whichBunker = 1;
	}
	if((pixelHit % 640) > (BUNK_SPACE*2+ BUNK_SHIFT - BUNKER_COLLISION_BUFFER)){
		whichBunker = 2;
	}
	if((pixelHit % 640) > (BUNK_SPACE*3+ BUNK_SHIFT - BUNKER_COLLISION_BUFFER)){
		whichBunker = 3;
	}

	//Find which block
	bunkGridX = ((pixelHit%640)-((BUNK_SPACE*whichBunker)+BUNK_SHIFT))/12;
	bunkGridY = ((pixelHit/640)-BUNKER_ROW)/12;

	whichBlock = bunkGridX+(bunkGridY*4);
	if(whichBlock == 11){
		whichBlock = 9;
	}
	bErosion[whichBunker][whichBlock]++;
	drawBunkerBlock(whichBlock, whichBunker);
}

void alienBunkerCollision(int pixelHit){


	//find which bunker was hit
	int whichBunker = 0;
	int whichBlock = 0;
	int bunkGridX = 0;
	int bunkGridY = 0;
	if((pixelHit % 640) > (BUNK_SPACE*1+ BUNK_SHIFT)){
		whichBunker = 1;
	}
	if((pixelHit % 640) > (BUNK_SPACE*2+ BUNK_SHIFT)){
		whichBunker = 2;
	}
	if((pixelHit % 640) > (BUNK_SPACE*3+ BUNK_SHIFT)){
		whichBunker = 3;
	}

	//Find which block
	bunkGridX = ((pixelHit%640)-((BUNK_SPACE*whichBunker)+BUNK_SHIFT))/12;
	bunkGridY = ((pixelHit/640)-BUNKER_ROW)/12;

	whichBlock = bunkGridX+(bunkGridY*4);
	if(whichBlock == 11){
		whichBlock = 9;
	}
	bErosion[whichBunker][whichBlock] = 3;
}

void alienCollision(int pixelHit){
	int whichAlien;
	int alienGridX = 0;
	int alienGridY = 0;
	alienGridX = ((pixelHit%640)- aBlockX)/32;
	alienGridY = ((pixelHit/640)- aBlockY)/INV_VERT;
	whichAlien = alienGridX + (alienGridY*11);
	alien_life[whichAlien] = 0;
	// Decrement bottomAlien for corresponding column.
	if ((whichAlien/11) == bottomAlien[(whichAlien%11)]){
		bottomAlien[(whichAlien%11)] = (bottomAlien[(whichAlien%11)] - 1);
		updateBlockBlank();
		if (11 < whichAlien){
			if (alien_life[whichAlien-11] != 1){
				bottomAlien[(whichAlien%11)] = (bottomAlien[(whichAlien%11)] - 1);
				updateBlockBlank();
				if (22 < whichAlien){
					if (alien_life[whichAlien-22] != 1){
						bottomAlien[(whichAlien%11)] = (bottomAlien[(whichAlien%11)] - 1);
						updateBlockBlank();
						if (33 < whichAlien){
							if (alien_life[whichAlien-33] != 1){
								bottomAlien[(whichAlien%11)] = (bottomAlien[(whichAlien%11)] - 1);
								updateBlockBlank();
								if (44 < whichAlien){
									if (alien_life[whichAlien-44] != 1){
										bottomAlien[(whichAlien%11)] = (bottomAlien[(whichAlien%11)] - 1);
										updateBlockBlank();
									}
								}
							}
						}
					}
				}
			}
		}
	}
	alienMarchSpeed--;
	clearAlien(whichAlien);
	debrisTimer = alienMarchSpeed;
	// Update player score.
	if (whichAlien < 11){
		playerScore+=40;
	}
	if ((10 < whichAlien) && (whichAlien < 33)){
		playerScore+=20;
	}
	if ((32 < whichAlien) && (whichAlien < 55)){
		playerScore+=10;
	}
	clearScore();
	scoreToString();
	printLetters(playerScoreChars,GREEN,SCORE_X_POS,TOP_MARGINE);
	int i,allDead;
	allDead = 1;
	for(i = 0; i < 55; i++){
		if(alien_life[i] == 1){
			allDead = 0;
		}
	}
	if(allDead){
		nextLevel();
	}
}

void mothershipCollision(){
	int randScore;
	mothershipScoreX = mothershipX;
	mothershipScoreY = mothershipY;

	clearMothership();
	sFlags[5] = 0;
	sFlags[6] = 0;
	mothershipSpawned =0;
	randScore = ((rand()%7)+1)*50;
	playerScore += randScore;
	clearScore();
	scoreToString();
	printLetters(playerScoreChars,GREEN,SCORE_X_POS,TOP_MARGINE);
	char* tempString = "";
	switch(randScore){
	case 50:
		tempString = "50";
		break;
	case 100:
		tempString = "100";
		break;
	case 150:
		tempString = "150";
		break;
	case 200:
		tempString = "200";
		break;
	case 250:
		tempString = "250";
		break;
	case 300:
		tempString = "300";
		break;
	case 350:
		tempString = "350";
		break;
	}
	printLetters(tempString,SCORE_RED,mothershipScoreX,mothershipScoreY);
	mothershipScoreTimer = MOTHERSHIP_SCORE_TIMER_INIT;
	mothershipScoreFlag = 1;
}

