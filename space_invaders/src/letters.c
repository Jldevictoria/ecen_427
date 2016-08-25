/*
 * letters.c
 *
 * Taylor Simons + Joseph DeVictoria
 * ECEN 425 Lab 3 aliens source.
 */

#include "letters.h"

int number0[12] =
{
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
};

int number1[12] =
{
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
	packWord12(0,0,0,0,0,1,1,1,0,0,0,0),
	packWord12(0,0,0,0,1,1,1,1,0,0,0,0),
	packWord12(0,0,0,1,1,0,1,1,0,0,0,0),
	packWord12(0,0,1,1,0,0,1,1,0,0,0,0),
	packWord12(0,0,1,0,0,0,1,1,0,0,0,0),
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
};

int number2[12] =
{
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
};

int number3[12] =
{
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
};

int number4[12] =
{
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
};

int number5[12] =
{
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
};

int number6[12] =
{
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
};

int number7[12] =
{
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,1,1,0,0),
	packWord12(0,0,0,0,0,0,0,0,1,1,0,0),
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,0,0,0,0,0,0),
};

int number8[12] =
{
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
};

int number9[12] =
{
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
};

int capitalS[10] =
{
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
};

int capitalC[10] =
{
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
};

int capitalO[10] =
{
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
};

int capitalR[10] =
{
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
};

int capitalE[10] =
{
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
};

int capitalL[10] =
{
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
};

int capitalI[10] =
{
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
};

int capitalV[10] =
{
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,1,1,0,0,1,1,0,0),
	packWord12(0,0,0,0,1,1,0,0,1,1,0,0),
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
	packWord12(0,0,0,0,0,0,1,1,0,0,0,0),
};
int capitalG[10] =
{
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,0,0),
	packWord12(0,0,1,1,0,0,1,1,1,1,1,1),
	packWord12(0,0,1,1,0,0,1,1,1,1,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
	packWord12(0,0,0,0,1,1,1,1,1,1,1,1),
};
int capitalA[10] =
{
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,0,0,1,1,1,1,1,1,0,0),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,1,1,1,1,1,1,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
	packWord12(0,0,1,1,0,0,0,0,0,0,1,1),
};
int capitalM[10] =
{
	packWord12(0,0,1,1,1,1,0,0,1,1,0,0),
	packWord12(0,0,1,1,1,1,0,0,1,1,0,0),
	packWord12(0,0,1,1,0,0,1,1,0,0,1,1),
	packWord12(0,0,1,1,0,0,1,1,0,0,1,1),
	packWord12(0,0,1,1,0,0,1,1,0,0,1,1),
	packWord12(0,0,1,1,0,0,1,1,0,0,1,1),
	packWord12(0,0,1,1,0,0,1,1,0,0,1,1),
	packWord12(0,0,1,1,0,0,1,1,0,0,1,1),
	packWord12(0,0,1,1,0,0,1,1,0,0,1,1),
	packWord12(0,0,1,1,0,0,1,1,0,0,1,1),
};
int space[10] =
{
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
	packWord12(0,0,0,0,0,0,0,0,0,0,0,0),
};




