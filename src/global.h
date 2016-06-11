using namespace std;

/* Window dimensions */
int WIDTH = 350;
int HEIGHT = 560;

/* Possition of the current object falling */
int indexCol=120, indexRow=520;
int indexCol2 = 120+390, indexRow2=520;

/* Score will be updated everytime */
long int SCORE = 0, SCORE2=0;

int next, next2;
int GAMEOVER=0, GAMEOVER2=0;
int randNum=0, randNum2=0, END=0, END2=0, PLAYING=0, PLAYING2=0;

/* Image dimensions 40x40 */
int ROW=40, COL=40;

/* Arrays for the images */
GLubyte paper[40][40];
GLubyte rock[40][40];
GLubyte scissors[40][40];
GLubyte bomb[40][40];
GLubyte red[40][40];
GLubyte blue[40][40];

#include "object.h"
object V[13][6];
queue<object> myQ;

object V2[13][6];
queue<object> myQ2;

int nextRow;
int nextCol;
int countEaten=0;

int nextRow2;
int nextCol2;
int countEaten2=0;

int PAUSE=0;
int playerNum = 0; // number of players
int textEffectX, textEffectY;
int textEffectX2, textEffectY2;
