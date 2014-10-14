/*
 * renderer.c
 *
 *  Created on: Oct 13, 2014
 *      Author: superman
 */

#include <stdio.h>
#include "globals.h"
#include "bitmap.h"


void drawInvaderBlock(){
	int row, col,invader,curPixel,oldPixel;

	for(invader = 0; invader < 55; invader++){
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				oldPixel = (oldABlockY+((invader/11)*INV_VERT)+row)*640+oldABlockX+((invader%11)*32)+col;
				if(invader < 11){
					if(!aBlockT){
						if ((topInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
							framePointer[oldPixel] = 0x00000000;
						}
					}
					else{
						if ((topOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
							framePointer[oldPixel] = 0x00000000;
						}
					}
				}
				else if(invader < 33){
					if(!aBlockT){
						if ((midInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
							framePointer[oldPixel] = 0x00000000;
						}
					}
					else{
						if ((midOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
							framePointer[oldPixel] = 0x00000000;
						}
					}
				}
				else{
					if(!aBlockT){
						if ((bottomInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
							framePointer[oldPixel] = 0x00000000;
						}
					}
					else{
						if ((bottomOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
							framePointer[oldPixel] = 0x00000000;
						}
					}
				}
			}
		}
	}

	oldABlockX = aBlockX;
	oldABlockY = aBlockY;
	for(invader = 0; invader < 55; invader++){
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				curPixel = (aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col;
				if(invader < 11){
					if(aBlockT){
						if ((topInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
							framePointer[curPixel] = 0x00FFFFFF;
						}
					}
					else{
						if ((topOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
							framePointer[curPixel] = 0x00FFFFFF;
						}
					}
				}
				else if(invader < 33){
					if(aBlockT){
						if ((midInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
							framePointer[curPixel] = 0x00FFFFFF;
						}
					}
					else{
						if ((midOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
							framePointer[curPixel] = 0x00FFFFFF;
						}
					}
				}
				else{
					if(aBlockT){
						if ((bottomInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
							framePointer[curPixel] = 0x00FFFFFF;
						}
					}
					else{
						if ((bottomOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
							framePointer[curPixel] = 0x00FFFFFF;
						}
					}
				}
			}
		}
	}
}


void render(int caller){
	int row, col,invader;
	int bunkerNum;
	int block;
	int bar;
	int bsc;
	// Choose what to update depending on calling function.
	switch (caller){
	case 0:
		break;
	case 2:
		//Draw Invader
		for(invader = 0; invader < 55; invader++){
			for (row = 0; row < 16; row ++){
				for (col = 0; col < 32; col ++){
					if(invader < 11){
						if(aBlockT){
							if ((topInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
						else{
							if ((topOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
					}
					else if(invader < 33){
						if(aBlockT){
							if ((midInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
						else{
							if ((midOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
					}
					else{
						if(aBlockT){
							if ((bottomInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
						else{
							if ((bottomOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
					}
				}
			}
		}
		break;
	case 3:
		// Spawn aliens bullets.
		for(bsc = 0; bsc < 4; bsc++){
			for (row = 0; row < 14; row ++){
				for (col = 0; col < 8; col ++){
					switch (bsc){
					case 0:
						if (bs[bsc] == 0){
							if (aBullet0T == 0){
								if (abs0){
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet0Y-A_B_MOVE+row)*640+aBullet0X+col] = 0x00000000;
									}
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet0Y+row)*640+aBullet0X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet0Y-A_B_MOVE+row)*640+aBullet0X+col] = 0x00000000;
									}
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet0Y+row)*640+aBullet0X+col] = 0x00FFFFFF;
									}
								}
							}else{
								if (abs0){
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet0Y-A_B_MOVE+row)*640+aBullet0X+col] = 0x00000000;
									}
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet0Y+row)*640+aBullet0X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet0Y-A_B_MOVE+row)*640+aBullet0X+col] = 0x00000000;
									}
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet0Y+row)*640+aBullet0X+col] = 0x00FFFFFF;
									}
								}
							}
						}
						break;
					case 1:
						if (bs[bsc] == 0){
							if (aBullet1T == 0){
								if (abs1){
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet1Y-A_B_MOVE+row)*640+aBullet1X+col] = 0x00000000;
									}
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet1Y+row)*640+aBullet1X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet1Y-A_B_MOVE+row)*640+aBullet1X+col] = 0x00000000;
									}
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet1Y+row)*640+aBullet1X+col] = 0x00FFFFFF;
									}
								}
							}else{
								if (abs1){
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet1Y-A_B_MOVE+row)*640+aBullet1X+col] = 0x00000000;
									}
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet1Y+row)*640+aBullet1X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet1Y-A_B_MOVE+row)*640+aBullet1X+col] = 0x00000000;
									}
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet1Y+row)*640+aBullet1X+col] = 0x00FFFFFF;
									}
								}
							}
						}
						break;
					case 2:
						if (bs[bsc] == 0){
							if (aBullet2T == 0){
								if (abs2){
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet2Y-A_B_MOVE+row)*640+aBullet2X+col] = 0x00000000;
									}
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet2Y+row)*640+aBullet2X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet2Y-A_B_MOVE+row)*640+aBullet2X+col] = 0x00000000;
									}
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet2Y+row)*640+aBullet2X+col] = 0x00FFFFFF;
									}
								}
							}else{
								if (abs2){
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet2Y-A_B_MOVE+row)*640+aBullet2X+col] = 0x00000000;
									}
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet2Y+row)*640+aBullet2X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet2Y-A_B_MOVE+row)*640+aBullet2X+col] = 0x00000000;
									}
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet2Y+row)*640+aBullet2X+col] = 0x00FFFFFF;
									}
								}
							}
						}

						break;
					case 3:
						if (bs[bsc] == 0){
							if (aBullet3T == 0){
								if (abs3){
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet3Y-A_B_MOVE+row)*640+aBullet3X+col] = 0x00000000;
									}
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet3Y+row)*640+aBullet3X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet3Y-A_B_MOVE+row)*640+aBullet3X+col] = 0x00000000;
									}
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet3Y+row)*640+aBullet3X+col] = 0x00FFFFFF;
									}
								}
							}else{
								if (abs3){
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet3Y-A_B_MOVE+row)*640+aBullet3X+col] = 0x00000000;
									}
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet3Y+row)*640+aBullet3X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet3Y-A_B_MOVE+row)*640+aBullet3X+col] = 0x00000000;
									}
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet3Y+row)*640+aBullet3X+col] = 0x00FFFFFF;
									}
								}
							}
						}
						break;
					default:
						break;
					}
				}
			}
		}
		break;
	case 4:
		// Move tank left.
		// Cleanup
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				if (tankSymbol[row] & (1 << (31-col))){
					framePointer[(tankY+row)*640+tankX+4+col] = 0x00000000;
				}
			}
		}
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				if (tankSymbol[row] & (1 << (31-col))){
					framePointer[(tankY+row)*640+tankX+col] = 0x0000FF00;
				}
			}
		}

		break;
	case 5:
		for (row = 0; row < 14; row ++){
			for (col = 0; col < 2; col ++){
				framePointer[(tBulletY+row)*640+tBulletX+col] = 0x00FFFFFF;
			}
		}
		break;
	case 6:
		// Move tank right.
		// Cleanup
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				if (tankSymbol[row] & (1 << (31-col))){
					framePointer[(tankY+row)*640+tankX-4+col] = 0x00000000;
				}
			}
		}
		for (row = 0; row < 16; row ++){
			for (col = 0; col < 32; col ++){
				if (tankSymbol[row] & (1 << (31-col))){
					framePointer[(tankY+row)*640+tankX+col] = 0x0000FF00;
				}
			}
		}
		break;
	case 7:
		for(bunkerNum = 0; bunkerNum < 4; bunkerNum++){
			for(block = 0; block < 10; block ++){
				switch(block){
				case 0:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker0[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD10[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD20[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD30[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 1:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 2:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 3:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD13[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD23[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD33[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row)*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 4:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(32*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 5:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker5[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD15[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD25[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD35[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*1)] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 6:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker6[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD16[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD26[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD36[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*2)] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 7:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*1))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 8:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*0)] = 0x00000000;
								}
								break;
							default:
								break;
							}
						}
					}
					break;
				case 9:
					for(row = 0; row < 12; row++){
						for(col = 0; col < 12; col++){
							switch(bErosion[bunkerNum][block]){
							case 0:
								if (bunker[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 1:
								if (bunkerD1[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 2:
								if (bunkerD2[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 3:
								if (bunkerD3[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
								}
								break;
							case 4:
								if (bunkerBlank[row] & (1 << (31-col))){
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x0000FF00;
								}
								else{
									framePointer[(BUNKER_ROW+row+(12*2))*640+(BUNK_SPACE*bunkerNum)+col+BUNK_SHIFT+(12*3)] = 0x00000000;
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
		//Draw Invader
		if ((aBlockD == 0) && (aBlockX >= X_BOUND_LEFT - A_BLOCK_WIDTH - BLOCK_SHIFT)){
			for(bar = 0; bar < 5; bar++){
				for (row = 0; row < 16; row ++){
					for (col = 0; col < 32*11; col ++){
						framePointer[(aBlockY+((bar)*INV_VERT)-16+row)*640+aBlockX+col] = 0x00000000;
					}
				}
			}
		}else if ((aBlockD == 1) && (aBlockX <= X_BOUND_RIGHT + BLOCK_SHIFT)){
			for(bar = 0; bar < 5; bar++){
				for (row = 0; row < 16; row ++){
					for (col = 0; col < 32*11; col ++){
						framePointer[(aBlockY+((bar)*INV_VERT)-16+row)*640+aBlockX+col] = 0x00000000;
					}
				}
			}
		}else if (aBlockD == 1){
			for (row = 0; row < INV_VERT * 5; row ++){
				for (col = 0; col < 32; col ++){
					framePointer[(aBlockY+row)*640+aBlockX-32+col] = 0x00000000;
				}
			}
		}else if (aBlockD == 0){
			for (row = 0; row < INV_VERT * 5; row ++){
				for (col = 0; col < 32; col ++){
					framePointer[(aBlockY+row)*640+aBlockX+32+col+(32*10)] = 0x00000000;
				}
			}
		}
		for(invader = 0; invader < 55; invader++){
			for (row = 0; row < 16; row ++){
				for (col = 0; col < 32; col ++){
					if(invader < 11){
						if(aBlockT){
							if ((topInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
						else{
							if ((topOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
					}
					else if(invader < 33){
						if(aBlockT){
							if ((midInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
						else{
							if ((midOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
					}
					else{
						if(aBlockT){
							if ((bottomInAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
						else{
							if ((bottomOutAlienSymbol[row] & (1 << (31-col))) && alien_life[invader]){
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00FFFFFF;
							}else{
								framePointer[(aBlockY+((invader/11)*INV_VERT)+row)*640+aBlockX+((invader%11)*32)+col] = 0x00000000;
							}
						}
					}
				}
			}
		}
		break;
	case 9:
		// Move bullets
		// Cleanup tank bullet.
		if(!ts){
			for (row = 0; row < 14; row ++){
				for (col = 0; col < 2; col ++){
					framePointer[(tBulletY+row+14)*640+tBulletX+col] = 0x00000000;
				}
			}
			// Move tank bullet.
			for (row = 0; row < 14; row ++){
				for (col = 0; col < 2; col ++){
					framePointer[(tBulletY+row)*640+tBulletX+col] = 0x00FFFFFF;
				}
			}
		}
		// Cleanup Alien Bullets
		for(bsc = 0; bsc < 4; bsc++){
			for (row = 0; row < 14; row ++){
				for (col = 0; col < 8; col ++){
					switch (bsc){
					case 0:
						if (bs[bsc] == 0){
							if (aBullet0T == 0){
								if (abs0){
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet0Y-A_B_MOVE+row)*640+aBullet0X+col] = 0x00000000;
									}
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet0Y+row)*640+aBullet0X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet0Y-A_B_MOVE+row)*640+aBullet0X+col] = 0x00000000;
									}
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet0Y+row)*640+aBullet0X+col] = 0x00FFFFFF;
									}
								}
							}else{
								if (abs0){
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet0Y-A_B_MOVE+row)*640+aBullet0X+col] = 0x00000000;
									}
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet0Y+row)*640+aBullet0X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet0Y-A_B_MOVE+row)*640+aBullet0X+col] = 0x00000000;
									}
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet0Y+row)*640+aBullet0X+col] = 0x00FFFFFF;
									}
								}
							}
						}
						break;
					case 1:
						if (bs[bsc] == 0){
							if (aBullet1T == 0){
								if (abs1){
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet1Y-A_B_MOVE+row)*640+aBullet1X+col] = 0x00000000;
									}
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet1Y+row)*640+aBullet1X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet1Y-A_B_MOVE+row)*640+aBullet1X+col] = 0x00000000;
									}
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet1Y+row)*640+aBullet1X+col] = 0x00FFFFFF;
									}
								}
							}else{
								if (abs1){
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet1Y-A_B_MOVE+row)*640+aBullet1X+col] = 0x00000000;
									}
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet1Y+row)*640+aBullet1X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet1Y-A_B_MOVE+row)*640+aBullet1X+col] = 0x00000000;
									}
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet1Y+row)*640+aBullet1X+col] = 0x00FFFFFF;
									}
								}
							}
						}
						break;
					case 2:
						if (bs[bsc] == 0){
							if (aBullet2T == 0){
								if (abs2){
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet2Y-A_B_MOVE+row)*640+aBullet2X+col] = 0x00000000;
									}
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet2Y+row)*640+aBullet2X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet2Y-A_B_MOVE+row)*640+aBullet2X+col] = 0x00000000;
									}
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet2Y+row)*640+aBullet2X+col] = 0x00FFFFFF;
									}
								}
							}else{
								if (abs2){
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet2Y-A_B_MOVE+row)*640+aBullet2X+col] = 0x00000000;
									}
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet2Y+row)*640+aBullet2X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet2Y-A_B_MOVE+row)*640+aBullet2X+col] = 0x00000000;
									}
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet2Y+row)*640+aBullet2X+col] = 0x00FFFFFF;
									}
								}
							}
						}

						break;
					case 3:
						if (bs[bsc] == 0){
							if (aBullet3T == 0){
								if (abs3){
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet3Y-A_B_MOVE+row)*640+aBullet3X+col] = 0x00000000;
									}
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet3Y+row)*640+aBullet3X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType10[row] & (1 << (31-col))){
										framePointer[(aBullet3Y-A_B_MOVE+row)*640+aBullet3X+col] = 0x00000000;
									}
									if (bulletType00[row] & (1 << (31-col))){
										framePointer[(aBullet3Y+row)*640+aBullet3X+col] = 0x00FFFFFF;
									}
								}
							}else{
								if (abs3){
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet3Y-A_B_MOVE+row)*640+aBullet3X+col] = 0x00000000;
									}
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet3Y+row)*640+aBullet3X+col] = 0x00FFFFFF;
									}

								}else{
									if (bulletType11[row] & (1 << (31-col))){
										framePointer[(aBullet3Y-A_B_MOVE+row)*640+aBullet3X+col] = 0x00000000;
									}
									if (bulletType01[row] & (1 << (31-col))){
										framePointer[(aBullet3Y+row)*640+aBullet3X+col] = 0x00FFFFFF;
									}
								}
							}
						}
						break;
					default:
						break;
					}
				}
			}
		}
		break;
	default:
		break;
		}
	return;
}