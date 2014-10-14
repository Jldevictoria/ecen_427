/*
 * globals.h
 *
 *  Created on: Oct 13, 2014
 *      Author: superman
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

// All define macros for this file.
#define DEBUG void print(char *str);
#define WRD_WIDTH 32
#define FRAME_BUFFER_0_ADDR 0xC1000000  // Starting location in DDR where we will store the images that we display.
#define NUM_OF_PIXELS 307200
#define SIDE_MARGINE 56
#define TOP_MARGINE 44
#define X_BOUND_RIGHT SIDE_MARGINE
#define X_BOUND_LEFT 640 - SIDE_MARGINE
#define GREEN_LINE_ROW 480 - TOP_MARGINE - 16
#define TANK_ROW GREEN_LINE_ROW - 32
#define TOP_BULLET_END TOP_MARGINE + 28
#define A_BLOCK_WIDTH 11*32
#define TANK_WIDTH  32
#define BUNKER_ROW GREEN_LINE_ROW - 90
#define BUNK_SHIFT X_BOUND_RIGHT + 74
#define BLOCK_SHIFT 4
#define INV_VERT 28
#define A_B_MOVE 14
#define A_B_Y_INIT TOP_MARGINE + 64
#define A_B_X_OFF 9
#define BUNK_SPACE 108
#define BULLET_MOVE_SPEED 8


// Declare Global Variables for game objects.
int tankX, tankY;
int tBulletX, tBulletY;
int aBlockX, aBlockY;
int oldABlockX, oldABlockY;

_Bool aBlockT, aBlockD;
int aBullet0X, aBullet0Y;
int aBullet1X, aBullet1Y;
int aBullet2X, aBullet2Y;
int aBullet3X, aBullet3Y;
_Bool bDone;
extern _Bool bs[4];
_Bool ts;
_Bool aBullet0T, aBullet1T, aBullet2T, aBullet3T;
_Bool abs0, abs1, abs2, abs3;
int bErosion[4][10];
_Bool alien_life[55];
int fit_counter, runtime;
int random;
int randomT;
extern int alienMarchSpeed;
// Pointer to the frame used by the hdmi controller.
unsigned int * framePointer;
int currentButtonState;

void render(int caller);
void clearBullet(int sel);
void control();
void pollButtons();
void updatePositions();
void drawGreenLine();
void timer_interrupt_handler();
void interrupt_handler_dispatcher(void* ptr);
void drawInvaderBlock();

#endif /* GLOBALS_H_ */