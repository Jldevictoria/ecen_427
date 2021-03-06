/*
 * globals.h
 *
 * Taylor Simons + Joseph DeVictoria
 * ECEN 425 Lab 3 aliens source.
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

// All define macros for this file.
//#define DEBUG void print(char *str);
#define WRD_WIDTH 32
#define FRAME_BUFFER_0_ADDR 0xC1000000  // Starting location in DDR where we will store the images that we display.
#define SCREENSHOT_BUFFER_0_ADDR 0xC5000000  //Starting location in DDR where we will store the screenshot image.
#define BUFFER_FULL_SIZE 1228800
#define NUM_OF_DMA_TRANSFERS (640*480)
#define NUM_OF_PIXELS 307200
#define SIDE_MARGINE 56
#define TOP_MARGINE 44
#define X_BOUND_LEFT SIDE_MARGINE
#define X_BOUND_RIGHT 640 - SIDE_MARGINE
#define GREEN_LINE_ROW 480 - TOP_MARGINE - 16
#define TANK_ROW (GREEN_LINE_ROW - 32)
#define TOP_BULLET_END (TOP_MARGINE + 35)
#define A_BLOCK_WIDTH (11*32)
#define TANK_WIDTH  32
#define BUNKER_ROW (GREEN_LINE_ROW - 90)
#define BUNK_SHIFT (X_BOUND_LEFT + 74)
#define BLOCK_SHIFT 4
#define BLOCK_SHIFT_VERT 16
#define INV_VERT 28
#define A_B_MOVE 4
#define A_B_Y_INIT  TOP_MARGINE + 64
#define A_B_X_OFF 9
#define BUNK_SPACE 108
#define ALIEN_FIRE_RATE 700
#define ALIEN_BULLET_SPEED 2
#define ALIEN_COLOR 0x00FFFFFF
#define BULLET_COLOR 0x00FFFFFE
#define WHITE 0x00FFFFFE
#define BLACK 0x00000000
#define GREEN 0x0000FF00
#define RED   0x00FF0000
#define SCORE_RED 0x00FE0000
#define BUL_TOGGLE_SIZE 30
#define BUL_TOGGLE_TWO (BUL_TOGGLE_SIZE/2)
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
#define LETTER_HEIGHT 10
#define LETTER_WIDTH 12
#define LIFE_ONE_POSITION 420
#define LIFE_TWO_POSITION (LIFE_ONE_POSITION+TANK_WIDTH+5)
#define LIFE_THREE_POSITION (LIFE_TWO_POSITION+TANK_WIDTH+5)
#define SCORE_TEXT_X_POS (X_BOUND_LEFT+60)
#define LIVES_X_POS (((X_BOUND_RIGHT-X_BOUND_LEFT)/2)+80)
#define SCORE_X_POS (X_BOUND_LEFT+140)
#define GAME_OVER_X_POS (((X_BOUND_RIGHT-X_BOUND_LEFT)/2))
#define GAME_OVER_Y_POS 200
#define TOP_TEXT_Y 10
#define MOTHERSHIP_SPAWN_RATE 15000
#define MOTHERSHIP_Y_POS (TOP_MARGINE+28)
#define MOTHERSHIP_SPEED 2
#define MOTHERSHIP_MOVE 2
#define MOTHERSHIP_SCORE_TIMER_INIT 50
#define NEXT_LEVEL_BLOCK_INC 50
#define A_BLOCK_Y_LOWER_LIMIT TANK_ROW - 24
#define ALIEN_BULLET_END TANK_ROW+15
#define BUNKER_WIDTH 12
#define BUNKER_COLLISION_BUFFER 10
#define FIFO_SIZE 256
#define NUM_OF_SOUNDS 10
#define FRAME_CUT 0
#define A_MOVE_AMP 1
#define DELAY_CHANGE 0x00008000
#define DELAY_MAX 0x00400000
#define DELAY_MIN 0x00004000


// Declare Global Variables for game objects.
int tankX, tankY;
int mothershipX, mothershipY;
_Bool mothershipD;
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
int tankBulletSpeed;
int bNum;
_Bool finalFlicker;
char playerScoreChars[20];
_Bool mothershipSpawned;
int mothershipScoreTimer;
_Bool mothershipScoreFlag;
int mothershipScoreX, mothershipScoreY;
int alienMarchSpeed;
int level;
_Bool reachedBottom;
// Pointer to the frame used by the hdmi controller.
unsigned int * framePointer;
int currentButtonState;
int ctlrButtons;
int atlysButtons;
int atlysSwitches;
int idleTime;
int runTimeN, runTimeO, deltaRunTime;
_Bool sFlags[10];
char alienMarchSoundTurn;
char mothershipSoundTurn;
_Bool ss_status, hw_ss_flag;

//Sound files.
extern int fastinvader4_soundData[1098];
extern int fastinvader4_numberOfSamples;
extern int fastinvader4_sampleRate;
int fastinvader4_count;
extern int fastinvader3_soundData[1054];
extern int fastinvader3_numberOfSamples;
extern int fastinvader3_sampleRate;
int fastinvader3_count;
extern int fastinvader2_soundData[1042];
extern int fastinvader2_numberOfSamples;
extern int fastinvader2_sampleRate;
int fastinvader2_count;
extern int fastinvader1_soundData[982];
extern int fastinvader1_numberOfSamples;
extern int fastinvader1_sampleRate;
int fastinvader1_count;
extern int explosion_soundData[8731];
extern int explosion_numberOfSamples;
extern int explosion_sampleRate;
int explosion_count;
extern int shoot_soundData[4080];
extern int shoot_numberOfSamples;
extern int shoot_sampleRate;
int shoot_count;
extern int invaderkilled_soundData[3377];
extern int invaderkilled_numberOfSamples;
extern int invaderkilled_sampleRate;
int invaderkilled_count;
extern int ufo_highpitch_soundData[1802];
extern int ufo_highpitch_numberOfSamples;
extern int ufo_highpitch_sampleRate;
int ufo_highpitch_count;
extern int ufo_lowpitch_soundData[25805];
extern int ufo_lowpitch_numberOfSamples;
extern int ufo_lowpitch_sampleRate;
int ufo_lowpitch_count;
int masterVolume;

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
void drawLives();
void drawAlienBullets();
void tankCollision(int pixelHit);
void tankFlicker();
void renderTankFlicker();
void renderMothership();
void alienCollision(int pixelHit);
void mothershipCollision();
void clearAliens();
void clearAlien(int alienNum);
void clearAllBunkers();
void updateBlockBlank();
void updateMothership();
void renderTankFlicker();
void renderTankBlank();
void cleanDebris();
void clearDebris();
void clearConsole();
void clearScore();
void scoreToString();
void clearLives(int tank_life);
void updateBullets();
void nextLevel();
void spawnBullets();
void spawnMothership();
void initilizeGame();
void printLetters(char* letters,int color,int printX,int printY);
void clearMothership();
void AC97_interrupt_handler();
void play_sound(int s);
void clearMotherScoreTimer();
void clearMothershipScore();
void alienBunkerCollision(int pixelHit);
#endif /* GLOBALS_H_ */
