#if defined (__WIN32__)
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

/* C++ */
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <ostream>
#include <iomanip>

/* C */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/* Music */
//#include <irrKlang.h>

/* MyLib */
#include <queue>
#include "global.h"
#include "actions.h"
#include "display.h"
#include "loadImages.h"
#include "moves.h"


using namespace std;

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);	// background color to white
	glMatrixMode(GL_PROJECTION);		// prameter provolhs
	gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
}

void keyboardFunc(GLubyte key, GLint xMouse, GLint yMouse) {
	
	switch (key) {
		case 27: // Esc
				exit(EXIT_SUCCESS);
			break;
		case 'b':
			PLAYING=1;
			PLAYING2=1;
			glutTimerFunc(25, moveDown, 0);
			if( (GAMEOVER == 0) && (GAMEOVER2 == 0) ) {	// game in progress
				moveDown(10);
			}else {			// game ended
				restartGame();
			}
			break;
		case 's':
			if( (PLAYING==1) && (PAUSE == 0) && (GAMEOVER==0) ) {		
				moveLeft();
			}
			break;
		case 'd':
			if( (PLAYING==1) && (PAUSE == 0) ) {
				moveRight();
			}
			break;
		case 'B':
			PLAYING=1;
			glutTimerFunc(25, moveDown, 0);
			if(GAMEOVER == 0 ) {	// game in progress
				moveDown(10);
			}else {			// game ended
				restartGame();
			}
			break;
		case 'S':
			if( (PLAYING==1) && (PAUSE == 0) ) {	
				moveLeft();
			}
			break;
		case 'D':
			if( (PLAYING==1) && (PAUSE == 0) ) {	
				moveRight();
			}
			break;
		case 32:
			if( (PLAYING==1) && (PAUSE == 0) ) {
				moveFast(indexCol);
			}
			break;
		case 'p':
			if(PAUSE == 0){
				PAUSE = 1;
			}else{
				PAUSE = 0;
			}
			break;
		case 'P':
			if(PAUSE == 0){
				PAUSE = 1;
			}else{
				PAUSE = 0;
			}
			break;
		case '4':
			if( (PLAYING==1) && (PAUSE == 0) ) {	
				moveLeft2();
			}
			break;
		case '5':
			if( (PLAYING==1) && (PAUSE == 0) ) {
				moveRight2();
			}
			break;
		case '1':
			if( (PLAYING==1) && (PAUSE == 0) ) {	
				moveFast2(indexCol2);
			}
			break;
		default:
			break;
	}
	glFlush ( );
}

/* All about the display */
void displayFunc(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	// Display colours at the left panel
	displayLeftLayer();

	// Display all the lines in the game
	displayLine();
	
	// If game is still in progress
	if(GAMEOVER == 0) {
		displayNext();		// shows the next to fall image		
		displayImage();		// shows the current image
	}

	// Displays the already fallen images 
	displayObj();

	// Upadte and displays the score
	string s=updateScore(SCORE);
	displayScore(s);

	// Displays all the text at the left panel 
	displaySideText();

	// Displays the gameover status
	if(GAMEOVER == 1)
		displayGameOver();

	if( playerNum == 2) {
		displayLeftLayer2();
		displayLine2();
		displaySideText2();
		displayMiddleLine();
		string s2 = updateScore(SCORE2);
		displayScore2(s2);
		
		displayObj2();
		if(GAMEOVER2 == 1)
			displayGameOver2();
		
		if(GAMEOVER2 == 0) {
			displayNext2();		// shows the next to fall image		
			displayImage2();		// shows the current image
	}
	}

	if( countEaten > 0 ) {
		string str3;
		ostringstream str2;
		str2 << countEaten;
		str3 = str2.str().c_str();
		int n = str3.length();
		string temp="x";
		glColor3f(0.0, 0.1, 1);
		glRasterPos2i(textEffectY, textEffectX);
		for(int i=0; i<1; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, temp[i]);
		for(int i=0; i<n; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str3[i]);
	}
	if( countEaten2 > 0 ) {
		string str4;
		ostringstream str22;
		str22 << countEaten2;
		str4 = str22.str().c_str();
		int n2 = str4.length();
		string temp2="x";
		glColor3f(0.0, 0.1, 1);
		glRasterPos2i(textEffectY2, textEffectX2);
		for(int i=0; i<1; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, temp2[i]);
		for(int i=0; i<n2; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str4[i]);
	}
	glutSwapBuffers ( );
	glFlush();
	if(countEaten > 0) {
		usleep(300000);
		countEaten = 0;
	}
	if(countEaten2 > 0) {
		usleep(300000);
		countEaten2 = 0;
	}
}

int main(int argc, char* argv[]) {
	/****************************************
	Initialize a variable for the sound. The
	library was taken from the link below
	from http://www.ambiera.com/irrklang/
	****************************************/
	//irrklang::ISoundEngine* engine;
	//engine = irrklang::createIrrKlangDevice();

	if( argc != 2 ) {
		cerr << "You forgot the number of players!\neg. ./a.out 2 for two players" << endl;
		exit(EXIT_SUCCESS);
	}
	playerNum = atoi(argv[1]);

	if( playerNum == 1 ) {
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); 
		glutInitWindowSize(WIDTH, HEIGHT); 
		glutInitWindowPosition(500, 200);
		glutCreateWindow ("Rock-Paper-Scissors");

		/* Play the sound in a loop */
		//if (!engine)
		//	cout << "Could not startup engine" << endl;
		//engine->play2D("sound/classicTetris.wav", true);
	
		/* Load the images into the program */
		loadImage();

		/* Initialize the window */
		init();

		glutDisplayFunc(displayFunc);
		glutKeyboardFunc(keyboardFunc);
	}else if(playerNum == 2 ) {
		WIDTH = WIDTH+WIDTH+40;
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); 
		glutInitWindowSize(WIDTH, HEIGHT); 
		glutInitWindowPosition(500, 200);
		glutCreateWindow ("Rock-Paper-Scissors");

		/* Play the sound in a loop */
		/*if (!engine)
			cout << "Could not startup engine" << endl;
		engine->play2D("sound/classicTetris.wav", true);
		*/
		/* Load the images into the program */
		loadImage();

		/* Initialize the window */
		init();

		glutDisplayFunc(displayFunc);
		glutKeyboardFunc(keyboardFunc);
	}
	glutMainLoop();
return 0;
}
