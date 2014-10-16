/*
 * globals.h
 *
 *  Created on: Oct 13, 2014
 *      Author: superman
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_



// All define macros for this file.
//#define DEBUG void print(char *str);
#define WRD_WIDTH 32
#define FRAME_BUFFER_0_ADDR 0xC1000000  // Starting location in DDR where we will store the images that we display.
#define NUM_OF_PIXELS 307200
#define SIDE_MARGINE 56
#define TOP_MARGINE 44
#define X_BOUND_LEFT SIDE_MARGINE
#define X_BOUND_RIGHT 640 - SIDE_MARGINE
#define GREEN_LINE_ROW 480 - TOP_MARGINE - 16
#define TANK_ROW (GREEN_LINE_ROW - 32)
#define TOP_BULLET_END (TOP_MARGINE + 28)
#define A_BLOCK_WIDTH (11*32)
#define TANK_WIDTH  32
#define BUNKER_ROW (GREEN_LINE_ROW - 90)
#define BUNK_SHIFT (X_BOUND_LEFT + 74)
#define BLOCK_SHIFT 4
#define INV_VERT 28
#define A_B_MOVE 4
#define A_B_Y_INIT TOP_MARGINE + 64
#define A_B_X_OFF 9
#define BUNK_SPACE 108
#define ALIEN_FIRE_RATE 2000
#define ALIEN_BULLET_SPEED 2
#define ALIEN_COLOR 0x00FFFFFF
#define BULLET_COLOR 0x00FFFFFE
#define BLACK 0x00000000
#define GREEN 0x0000FF00
#define BUL_TOGGLE_SIZE 10
#define ALIEN_BULLET_HIGHT 10
#define TANK_ALIVE 0
#define TANK_DEAD_ONE 1
#define TANK_DEAD_TWO 2
#define FLICKER_SPEED 14
#define TANK_X_INIT X_BOUND_LEFT
#define FIT_COUNT_MAX 1000000
#define RUNNING 1
#define STOPPED 0
#define T_BULLET_HEIGHT 10
#define TANK_SPEED 2
#define NUM_OF_T_FLICKERS 10
#define GAME_OVER 2


// Declare Global Variables for game objects.
int tankX, tankY;
int tBulletX, tBulletY;
int aBlockX, aBlockY;
int oldABlockX, oldABlockY;
int playerScore;
_Bool aBlockT, aBlockD;
int aBulletX[4];
int aBulletY[4];
_Bool bDone;
_Bool bs[4];
_Bool ts;
_Bool aBulletT[4];
int bottomAlien[11];
_Bool abs_[4];
int bErosion[4][10];
_Bool alien_life[55];
int fit_counter, runtime;
int random;
int rando;
int randomT;
int randomRow;
int aBlockLeftBlank;
int aBlockRightBlank;
int playerLives;
int tankDestroyedFlicker;
int tankState;
int lastDebrisRow;
int lastDebrisCol;
int debrisTimer;
int gameStatus;
int  tankBulletSpeed;
int bNum;


int alienMarchSpeed;
// Pointer to the frame used by the hdmi controller.
unsigned int * framePointer;
int currentButtonState;

void drawScore();
void render(int caller);
void clearBullet(int sel);
void control();
void pollButtons();
void updateAliens();
void drawGreenLine();
void timer_interrupt_handler();
void interrupt_handler_dispatcher(void* ptr);
void drawInvaderBlock();
void bunkerCollision(int pixelHit);
void drawBunkerBlock(int block, int bunkerNum);
void drawAlienBullets();
void tankCollision(int pixelHit);
void tankFlicker();
void renderTankFlicker();
void alienCollision(int pixelHit);
void clearAlien(int alienNum);
void updateBlockBlank();
void renderTankFlicker();
void renderTankBlank();
void cleanDebris();
void clearDebris();
void clearConsole();
void updateBullets();
void nextLevel();
void spawnBullets();
void initilizeGame();
#endif /* GLOBALS_H_ */
