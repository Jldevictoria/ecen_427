/*
 * renderer.c
 *
 * Taylor Simons + Joseph DeVictoria
 * ECEN 425 Lab 3 aliens source.
 */

#include <stdio.h>
#include "globals.h"
#include "bitmap.h"
#include "letters.h"
#include <stdio.h>


void printLetters(char* letters,int color,int printX,int printY){
	int stringLength = 0;
	int i,row,col;
	int * tempBitMap;
	for (i = 0; letters[i] != '\0'; i++){
		stringLength = i + 1;
	}
	for (row = 0; row < LETTER_HEIGHT;row++ ){
		for (col = 0; col < (LETTER_WIDTH*stringLength); col ++){
			switch(letters[(col/12)]){
			case'0':
				tempBitMap = number0;
				break;
			case'1':
				tempBitMap = number1;
				break;
			case'2':
				tempBitMap = number2;
				break;
			case'3':
				tempBitMap = number3;
				break;
			case'4':
				tempBitMap = number4;
				break;
			case'5':
				tempBitMap = number5;
				break;
			case'6':
				tempBitMap = number6;
				break;
			case'7':
				tempBitMap = number7;
				break;
			case'8':
				tempBitMap = number8;
				break;
			case'9':
				tempBitMap = number9;
				break;
			case'S':
				tempBitMap = capitalS;
				break;
			case'C':
				tempBitMap = capitalC;
				break;
			case'O':
				tempBitMap = capitalO;
				break;
			case'R':
				tempBitMap = capitalR;
				break;
			case'E':
				tempBitMap = capitalE;
				break;
			case'L':
				tempBitMap = capitalL;
				break;
			case'I':
				tempBitMap = capitalI;
				break;
			case'V':
				tempBitMap = capitalV;
				break;
			case'G':
				tempBitMap = capitalG;
				break;
			case'A':
				tempBitMap = capitalA;
				break;
			case'M':
				tempBitMap = capitalM;
				break;
			default:
				tempBitMap = space;
				break;
			}
			if (tempBitMap[row] & (1 << (31-col%12))){
				framePointer[(printY+row)*640+printX+col] = color;
			}

		}
	}
}

void clearBullet(int sel){
	int tempPixel;
	int tempY = 0;
	int tempX = 0;
	switch(sel){
	case 0:
		tempY = aBulletY[0];
		tempX = aBulletX[0];
		break;
	case 1:
		tempY = aBulletY[1];
		tempX = aBulletX[1];
		break;
	case 2:
		tempY = aBulletY[2];
		tempX = aBulletX[2];
		break;
	case 3:
		tempY = aBulletY[3];
		tempX = aBulletX[3];
		break;
	case 4:
		tempY = tBulletY;
		tempX = tBulletX;
		break;
	}
	int row,col;
	for (row = 0; row < (21+10); row ++){
		for (col = 0; col < 8; col ++){
			tempPixel = (tempY+row-10)*640+tempX+col;
			if(framePointer[tempPixel] == BULLET_COLOR){
				framePointer[tempPixel] = BLACK;
			}
		}
	}
}

void clearAliens(){
	int row,col;
	for (row = MOTHERSHIP_Y_POS; row < 480; row++){
		for (col = 0; col < 640; col++){
			if ((framePointer[((row*640)+col)] == ALIEN_COLOR) || (framePointer[((row*640)+col)] == WHITE)){
				framePointer[((row*640)+col)] = BLACK;
			}
		}
	}
}

void clearAllBunkers(){
	int row,col;
	for (row = MOTHERSHIP_Y_POS; row < (TANK_ROW-4); row++){
		for (col = 0; col < 640; col++){
			if (framePointer[((row*640)+col)] == GREEN){
				framePointer[((row*640)+col)] = BLACK;
			}
		}
	}
}


void clearAlien(int alienNum){
	int aRow,aCol,row,col,tempPix;
	int alienGridX = alienNum%11;
	int alienGridY = alienNum/11;

	aRow = (aBlockY+(alienGridY*INV_VERT));
	aCol = (aBlockX+(alienGridX*32));

	if(lastDebrisRow != 0){
		clearDebris();
	}

	lastDebrisRow = aRow;
	lastDebrisCol = aCol;

	for(row = 0; row < 20; row++){
		for(col = 0; col < 32; col++){
			tempPix = (aRow+row)*640+aCol+col-4;
			if (alienExplosionSymbol[row] & (1 << (31-col))){
				framePointer[tempPix] = BULLET_COLOR;
			}
			if(framePointer[tempPix] == ALIEN_COLOR){
				if (!(alienExplosionSymbol[row] & (1 << (31-col)))){
					framePointer[tempPix] = BLACK;
				}
			}
		}
	}
}

void clearDebris(){
	int row,col,tempPix;
	for(row = 0; row < 20; row++){
		for(col = 0; col < 32; col++){
			tempPix = (lastDebrisRow+row)*640+lastDebrisCol+col-4;
			if(framePointer[tempPix] == BULLET_COLOR){
				framePointer[tempPix] = BLACK;
			}
		}
	}
	lastDebrisRow = 0;
	lastDebrisCol = 0;
}

void clearScore(){
	int row,col;
	for (row = TOP_MARGINE; row < (TOP_MARGINE+12); row++){
		for (col = 190; col < 340; col++){
			framePointer[((row*640)+col)] = BLACK;
		}
	}
}

void clearLives(int tank_life){
	int row,col,toErase;
	_Bool eb = 0;
	if (tank_life == 0){
		toErase = LIFE_ONE_POSITION;
		eb = 1;
	}else if (tank_life == 1){
		toErase = LIFE_TWO_POSITION;
		eb = 1;
	}else if (tank_life == 2){
		toErase = LIFE_THREE_POSITION;
		eb = 1;
	}
	if (eb == 1){
		for (row = (TOP_MARGINE-6); row < TOP_MARGINE+13; row++){
			for (col = toErase; col < (toErase+TANK_WIDTH); col++){
				framePointer[((row*640)+col)] = BLACK;
			}
		}
	}
}

void renderTankBlank(){
	int row,col,curPix;
	for (row = 0; row < 18; row++){
		for (col = 0; col < 32; col++){
			curPix = (tankY+row)*640+tankX+col;
			if(framePointer[curPix] == GREEN)
			{
				framePointer[curPix] = BLACK;
			}
		}
	}
}

void clearMothership(){
	int row,col;
	for (row = 0; row < ALIEN_HEIGHT; row++){
		for (col = 0; col < (32+(2*MOTHERSHIP_MOVE)); col++){
			framePointer[(((mothershipY+row)*640)+(mothershipX-(MOTHERSHIP_MOVE)+col))] = BLACK;
		}
	}
}

void clearMothershipScore(){
	int row,col;
	for (row = 0; row < ALIEN_HEIGHT; row++){
		for (col = 0; col < (32+(2*MOTHERSHIP_MOVE)+6); col++){
			framePointer[(((mothershipScoreY+row)*640)+(mothershipScoreX-(MOTHERSHIP_MOVE+3)+col))] = BLACK;
		}
	}
}

void renderMothership(){
	int row,col;
	for (row = 0; row < ALIEN_HEIGHT; row++){
		for (col = 0; col < (32+(2*MOTHERSHIP_MOVE)); col++){
			framePointer[(((mothershipY+row)*640)+(mothershipX-(MOTHERSHIP_MOVE)+col))] = BLACK;
		}
	}
	for (row = 0; row < ALIEN_HEIGHT; row++){
		for (col = 0; col < 32; col++){
			if (mothershipSymbol[row] & (1 << (31 - col))){
				if(((mothershipX+col) > (X_BOUND_LEFT)) && ((mothershipX+col) < (X_BOUND_RIGHT))){
					framePointer[(((mothershipY+row)*640)+(mothershipX+col))] = RED;
				}
			}
		}
	}
}

void renderTankFlicker(){
	int row,col,curPix;
	for (row = 0; row < 18; row++){
		for (col = 0; col < 32; col++){
			curPix = (tankY+row)*640+tankX+col;
			if(framePointer[curPix] == GREEN)
			{
				framePointer[curPix] = BLACK;
			}
		}
	}
	for (row = 0; row < 18; row++){
		for (col = 0; col < 32; col++){
			curPix = (tankY+row)*640+tankX+col;
			if(tankState == 1){
				if (tankDestoyedOutSymbol[row] & (1 << (31-col))){
					framePointer[curPix] = GREEN;
				}
			}else{
				if (tankDestoyedInSymbol[row] & (1 << (31-col))){
					framePointer[curPix] = GREEN;
				}
			}
		}
	}
}

void drawLives(){
	int row,col,curPix,k;
	int tankLives[3] = { LIFE_ONE_POSITION, LIFE_TWO_POSITION, LIFE_THREE_POSITION };
	for (k = 0; k < 3; k++){
		for (row = 0; row < 16; row++){
			for (col = 0; col < TANK_WIDTH; col++){
				curPix = (((row+(TOP_MARGINE-4))*640)+tankLives[k]+col);
				if (tankSymbol[row] & (1 << (31-col))){
					framePointer[curPix] = GREEN;
				}
			}
		}
	}
}

void drawAlienBullets(){
	int bsc,row,col,pixTemp;
	//Clear alien bullet
	for(bsc = 0; bsc < 4; bsc++){
		for (row = 0; row < ALIEN_BULLET_HIGHT; row ++){
			for (col = 0; col < 8; col ++){
				pixTemp = (aBulletY[bsc]-A_B_MOVE+row)*640+aBulletX[bsc]+col;
				if(framePointer[pixTemp] == BULLET_COLOR){
					framePointer[pixTemp] = BLACK;
				}
			}
		}
	}


	//Draw alien bullets
	for(bsc = 0; bsc < 4; bsc++){
		for (row = 0; row < ALIEN_BULLET_HIGHT; row ++){
			for (col = 0; col < 8; col ++){
				if (bs[bsc] == 0){
					if (aBulletT[bsc]){
						if ((aBulletY[bsc]/BUL_TOGGLE_SIZE)%2){
							if ((aBulletY[bsc]/BUL_TOGGLE_TWO)%2){
								if (bulletType10[row] & (1 << (31-col))){
									framePointer[(aBulletY[bsc]+row)*640+aBulletX[bsc]+col] = BULLET_COLOR;
								}
							}else{
								if (bulletType20[row] & (1 << (31-col))){
									framePointer[(aBulletY[bsc]+row)*640+aBulletX[bsc]+col] = BULLET_COLOR;
								}
							}
						}else{
							if ((aBulletY[bsc]/BUL_TOGGLE_TWO)%2){
								if (bulletType00[row] & (1 << (31-col))){
									framePointer[(aBulletY[bsc]+row)*640+aBulletX[bsc]+col] = BULLET_COLOR;
								}
							}else{
								if (bulletType30[row] & (1 << (31-col))){
									framePointer[(aBulletY[bsc]+row)*640+aBulletX[bsc]+col] = BULLET_COLOR;
								}
							}
						}
					}else{
						if ((aBulletY[bsc]/BUL_TOGGLE_SIZE)%2){
							if (bulletType11[row] & (1 << (31-col))){
								framePointer[(aBulletY[bsc]+row)*640+aBulletX[bsc]+col] = BULLET_COLOR;
							}
						}else{
							if (bulletType01[row] & (1 << (31-col))){
								framePointer[(aBulletY[bsc]+row)*640+aBulletX[bsc]+col] = BULLET_COLOR;
							}
						}
					}
				}
			}
		}
	}
}

void drawBunkerBlock(int block, int bunkerNum){
	int col,row;
	switch(block){
		case 0:
			for(row = 0; row < BUNKER_WIDTH; row++){
				for(col = 0; col < BUNKER_WIDTH; col++){
					switch(bErosion[bunkerNum][block]){
					case 0:
						if (bunker0[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
						}
						break;
					case 1:
						if (bunkerD10[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
						}
						break;
					case 2:
						if (bunkerD20[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
						}
						break;
					case 3:
						if (bunkerD30[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
						}
						break;
					default:
						break;
					}
				}
			}
			break;
		case 1:
			for(row = 0; row < BUNKER_WIDTH; row++){
				for(col = 0; col < BUNKER_WIDTH; col++){
					switch(bErosion[bunkerNum][block]){
					case 0:
						if (bunker[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
						}
						break;
					case 1:
						if (bunkerD1[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
						}
						break;
					case 2:
						if (bunkerD2[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
						}
						break;
					case 3:
						if (bunkerD3[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
						}
						break;
					default:
						break;
					}
				}
			}
			break;
		case 2:
			for(row = 0; row < BUNKER_WIDTH; row++){
				for(col = 0; col < BUNKER_WIDTH; col++){
					switch(bErosion[bunkerNum][block]){
					case 0:
						if (bunker[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
						}
						break;
					case 1:
						if (bunkerD1[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
						}
						break;
					case 2:
						if (bunkerD2[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
						}
						break;
					case 3:
						if (bunkerD3[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
						}
						break;
					default:
						break;
					}
				}
			}
			break;
		case 3:
			for(row = 0; row < BUNKER_WIDTH; row++){
				for(col = 0; col < BUNKER_WIDTH; col++){
					switch(bErosion[bunkerNum][block]){
					case 0:
						if (bunker3[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
						}
						break;
					case 1:
						if (bunkerD13[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
						}
						break;
					case 2:
						if (bunkerD23[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
						}
						break;
					case 3:
						if (bunkerD33[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
						}
						break;
					default:
						break;
					}
				}
			}
			break;
		case 4:
			for(row = 0; row < BUNKER_WIDTH; row++){
				for(col = 0; col < BUNKER_WIDTH; col++){
					switch(bErosion[bunkerNum][block]){
					case 0:
						if (bunker[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
						}
						break;
					case 1:
						if (bunkerD1[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
						}
						break;
					case 2:
						if (bunkerD2[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
						}
						break;
					case 3:
						if (bunkerD3[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
						}
						break;
					default:
						break;
					}
				}
			}
			break;
		case 5:
			for(row = 0; row < BUNKER_WIDTH; row++){
				for(col = 0; col < BUNKER_WIDTH; col++){
					switch(bErosion[bunkerNum][block]){
					case 0:
						if (bunker5[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
						}
						break;
					case 1:
						if (bunkerD15[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
						}
						break;
					case 2:
						if (bunkerD25[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
						}
						break;
					case 3:
						if (bunkerD35[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
						}
						break;
					default:
						break;
					}
				}
			}
			break;
		case 6:
			for(row = 0; row < BUNKER_WIDTH; row++){
				for(col = 0; col < BUNKER_WIDTH; col++){
					switch(bErosion[bunkerNum][block]){
					case 0:
						if (bunker6[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
						}
						break;
					case 1:
						if (bunkerD16[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
						}
						break;
					case 2:
						if (bunkerD26[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
						}
						break;
					case 3:
						if (bunkerD36[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
						}
						break;
					default:
						break;
					}
				}
			}
			break;
		case 7:
			for(row = 0; row < BUNKER_WIDTH; row++){
				for(col = 0; col < BUNKER_WIDTH; col++){
					switch(bErosion[bunkerNum][block]){
					case 0:
						if (bunker[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
						}
						break;
					case 1:
						if (bunkerD1[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
						}
						break;
					case 2:
						if (bunkerD2[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
						}
						break;
					case 3:
						if (bunkerD3[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
						}
						break;
					default:
						break;
					}
				}
			}
			break;
		case 8:
			for(row = 0; row < BUNKER_WIDTH; row++){
				for(col = 0; col < BUNKER_WIDTH; col++){
					switch(bErosion[bunkerNum][block]){
					case 0:
						if (bunker[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
						}
						break;
					case 1:
						if (bunkerD1[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
						}
						break;
					case 2:
						if (bunkerD2[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
						}
						break;
					case 3:
						if (bunkerD3[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
						}
						break;
					default:
						break;
					}
				}
			}
			break;
		case 9:
			for(row = 0; row < BUNKER_WIDTH; row++){
				for(col = 0; col < BUNKER_WIDTH; col++){
					switch(bErosion[bunkerNum][block]){
					case 0:
						if (bunker[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
						}
						break;
					case 1:
						if (bunkerD1[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
						}
						break;
					case 2:
						if (bunkerD2[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
						}
						break;
					case 3:
						if (bunkerD3[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
						}
						break;
					case 4:
						if (bunkerBlank[row] & (1 << (31-col))){
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
						}
						else{
							framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
						}
						break;
					default:
						break;
					}
				}
			}
			break;
		default:
			break;
		}
}

void render(int caller){
	int row, col,invader;
	int bunkerNum;
	int block;
	int bar;
	int curPix;
	// Choose what to update depending on calling function.
	switch (caller){
	case 0:
		break;
	case 2:
		//Draw Invader
		for(invader = 0; invader < 55; invader++){
			for (row = 0; row < 16; row ++){
				for (col = 0; col < 32; col ++){
					curPix = (aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col;
					if(invader < 11){
						if(aBlockT){
							if ((topInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[curPix] = ALIEN_COLOR;
							}else{
								framePointer[curPix] = BLACK;
							}
						}
						else{
							if ((topOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[curPix] = ALIEN_COLOR;
							}else{
								framePointer[curPix] = BLACK;
							}
						}
					}
					else if(invader < 33){
						if(aBlockT){
							if ((midInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[curPix] = ALIEN_COLOR;
							}else{
								framePointer[curPix] = BLACK;
							}
						}
						else{
							if ((midOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[curPix] = ALIEN_COLOR;
							}else{
								framePointer[curPix] = BLACK;
							}
						}
					}
					else{
						if(aBlockT){
							if ((bottomInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[curPix] = ALIEN_COLOR;
							}else{
								framePointer[curPix] = BLACK;
							}
						}
						else{
							if ((bottomOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[curPix] = ALIEN_COLOR;
							}else{
								framePointer[curPix] = BLACK;
							}
						}
					}
				}
			}
		}
		break;
	case 3:
		// Spawn aliens bullets.
		drawAlienBullets();
		break;
	case 4:
		// Move tank left.
		// Cleanup
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				if (tankSymbol[row] & (1 << (31-col))){
					framePointer[(tankY+row)*640+tankX+4+col] = BLACK;
				}
			}
		}
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				if (tankSymbol[row] & (1 << (31-col))){
					framePointer[(tankY+row)*640+tankX+col] = GREEN;
				}
			}
		}

		break;
	case 5:
		for (row = 0; row < T_BULLET_HEIGHT; row ++){
			for (col = 0; col < 2; col ++){
				framePointer[(tBulletY+row)*640+tBulletX+col] = BULLET_COLOR;
			}
		}
		break;
	case 6:
		// Move tank right.
		// Cleanup
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				if (tankSymbol[row] & (1 << (31-col))){
					framePointer[(tankY+row)*640+tankX-4+col] = BLACK;
				}
			}
		}
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				if (tankSymbol[row] & (1 << (31-col))){
					framePointer[(tankY+row)*640+tankX+col] = GREEN;
				}
			}
		}
		break;
	case 7:
		for(bunkerNum = 0; bunkerNum < 4; bunkerNum++){
			for(block = 0; block < 10; block ++){
				switch(block){
				case 0:
					for(row = 0; row < BUNKER_WIDTH; row++){
						for(col = 0; col < BUNKER_WIDTH; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker0[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
								}
								break;
							case 1:
								if (bunkerD10[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
								}
								break;
							case 2:
								if (bunkerD20[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
								}
								break;
							case 3:
								if (bunkerD30[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = BLACK;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 1:
					for(row = 0; row < BUNKER_WIDTH; row++){
						for(col = 0; col < BUNKER_WIDTH; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 2:
					for(row = 0; row < BUNKER_WIDTH; row++){
						for(col = 0; col < BUNKER_WIDTH; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 3:
					for(row = 0; row < BUNKER_WIDTH; row++){
						for(col = 0; col < BUNKER_WIDTH; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
								}
								break;
							case 1:
								if (bunkerD13[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
								}
								break;
							case 2:
								if (bunkerD23[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
								}
								break;
							case 3:
								if (bunkerD33[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 4:
					for(row = 0; row < BUNKER_WIDTH; row++){
						for(col = 0; col < BUNKER_WIDTH; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(32*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 5:
					for(row = 0; row < BUNKER_WIDTH; row++){
						for(col = 0; col < BUNKER_WIDTH; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker5[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
								}
								break;
							case 1:
								if (bunkerD15[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
								}
								break;
							case 2:
								if (bunkerD25[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
								}
								break;
							case 3:
								if (bunkerD35[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*1)] = BLACK;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 6:
					for(row = 0; row < BUNKER_WIDTH; row++){
						for(col = 0; col < BUNKER_WIDTH; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker6[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
								}
								break;
							case 1:
								if (bunkerD16[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
								}
								break;
							case 2:
								if (bunkerD26[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
								}
								break;
							case 3:
								if (bunkerD36[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*2)] = BLACK;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 7:
					for(row = 0; row < BUNKER_WIDTH; row++){
						for(col = 0; col < BUNKER_WIDTH; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 8:
					for(row = 0; row < BUNKER_WIDTH; row++){
						for(col = 0; col < BUNKER_WIDTH; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*0)] = BLACK;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 9:
					for(row = 0; row < BUNKER_WIDTH; row++){
						for(col = 0; col < BUNKER_WIDTH; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = BLACK;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(BUNKER_WIDTH*3)] = GREEN;
								}
								else{
									framePointer[(BUNKER_ROW+row+(BUNKER_WIDTH*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = BLACK;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				default:
					break;
				}
			}
		}
		break;
	case 8:
		//Draw Black
		if ((aBlockD == 0) && (aBlockX >= X_BOUND_RIGHT - (A_BLOCK_WIDTH-aBlockRightBlank*32) - BLOCK_SHIFT)){
			for(bar = 0; bar < 5; bar++){
				for (row = 0; row < 16; row ++){
					for (col = 0; col < (32*11); col ++){
						if(framePointer[(aBlockY+((bar)*INV_VERT)-16+row)*640+aBlockX+col] == ALIEN_COLOR){
							framePointer[(aBlockY+((bar)*INV_VERT)-16+row)*640+aBlockX+col] = BLACK;
						}
					}
				}
			}
		}else if ((aBlockD == 1) && (aBlockX <= X_BOUND_LEFT-aBlockLeftBlank*32 + BLOCK_SHIFT)){
			for(bar = 0; bar < 5; bar++){
				for (row = 0; row < 16; row ++){
					for (col = 0; col < (32*11); col ++){
						if(framePointer[(aBlockY+((bar)*INV_VERT)-16+row)*640+aBlockX+col] == ALIEN_COLOR){
							framePointer[(aBlockY+((bar)*INV_VERT)-16+row)*640+aBlockX+col] = BLACK;
						}
					}
				}
			}
		}else if (aBlockD == 1){
			for (row = 0; row < ((INV_VERT * 5)-12); row ++){
				for (col = 0; col < 32; col ++){
					if(framePointer[(aBlockY+row)*640+aBlockX-32+col] == ALIEN_COLOR){
						framePointer[(aBlockY+row)*640+aBlockX-32+col] = BLACK;
					}
				}
			}
		}else if (aBlockD == 0){
			for (row = 0; row < ((INV_VERT * 5)-12); row ++){
				for (col = 0; col < 32; col ++){
					if(framePointer[(aBlockY+row)*640+aBlockX+32+col+(32*10)] == ALIEN_COLOR){
						framePointer[(aBlockY+row)*640+aBlockX+32+col+(32*10)] = BLACK;
					}
				}
			}
		}

		//Draw invaders

		int * tempMap;
		for(invader = 0; invader < 55; invader++){
			for (row = 0; row < 16; row ++){
				for (col = 0; col < 32; col ++){
					curPix = (aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col;
					if(invader < 11){
						if(aBlockT){
							tempMap = topInAlienSymbol;
						}
						else{
							tempMap = topOutAlienSymbol;
						}
					}
					else if(invader < 33){
						if(aBlockT){
							tempMap = midInAlienSymbol;
						}
						else{
							tempMap = midOutAlienSymbol;
						}
					}
					else{
						if(aBlockT){
							tempMap = bottomInAlienSymbol;
						}
						else{
							tempMap = bottomOutAlienSymbol;
						}
					}
					if ((tempMap[row] & (1 << (31-col))) && alien_life[invader]){
						if(framePointer[curPix] == GREEN){
							alienBunkerCollision(curPix);
						}
						if (alien_life[invader] == 1){
							if((aBlockY+((invader/11)*INV_VERT)+row) > A_BLOCK_Y_LOWER_LIMIT){
								reachedBottom = 1;
								gameStatus = GAME_OVER;
							}
						}
						framePointer[curPix] = ALIEN_COLOR;
					}else if (framePointer[curPix] ==  ALIEN_COLOR){
						framePointer[curPix] = BLACK;
					}
				}
			}
			for (row = 16; row < 20; row ++){
				for (col = 0; col < 32; col ++){
					curPix = (aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col;
					if(framePointer[curPix] == ALIEN_COLOR){
						framePointer[curPix] = BLACK;
					}
				}
			}

		}



			// Clean up bottom for explosion
		break;
	case 9:
		// Move bullets
		// Cleanup tank bullet.
		if(!ts){
			for (row = 0; row < T_BULLET_HEIGHT; row ++){
				for (col = 0; col < 2; col ++){
					framePointer[(tBulletY+row+7)*640+tBulletX+col] = BLACK;
				}
			}
			// Move tank bullet.
			for (row = 0; row < T_BULLET_HEIGHT; row ++){
				for (col = 0; col < 2; col ++){
					framePointer[(tBulletY+row)*640+tBulletX+col] = BULLET_COLOR;
				}
			}
		}
		// Cleanup Alien Bullets
		drawAlienBullets();
		break;
	default:
		break;
		}
	return;
}
