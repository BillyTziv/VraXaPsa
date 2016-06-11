/**================= Functions =====================
- displayLine
- displayScore
- displaySideText
- displayGameOver
- displayImage
- displayNext
- displayObj
- displayMiddleLine
==================================================**/

using namespace std;

/**************************************************
Displays a double horizontal and verical line in
the window
**************************************************/
void displayLine() {
	/* Select colour to WHITE */
	glColor3f(0, 0.8, 0);

	/* WHITE horizontal line */
	glBegin(GL_LINES);
		glVertex2i(0, 36);
		glVertex2i(350, 36);
		glVertex2i(0, 37);
		glVertex2i(350, 37);
	glEnd();

	/* WHITE vertical line */
	glBegin(GL_LINES);
		glVertex2i(243, 39);
		glVertex2i(243, 560);
		glVertex2i(244, 39);
		glVertex2i(244, 560);
	
	glEnd();

	/* Set colour to BLACK */
	glColor3f(0, 0, 0);

	/* BLACK horizontal line */
	glBegin(GL_LINES);
		glVertex2i(0, 38);
		glVertex2i(240, 38);
		glVertex2i(0, 39);
		glVertex2i(240, 39);
	glEnd();
	
	/* BLACK vertical line */
	glBegin(GL_LINES);
		glVertex2i(241, 40);
		glVertex2i(241, 560);
		glVertex2i(242, 40);
		glVertex2i(242, 560);
	glEnd();

	/* Set colour to WHITE */
	glColor3f(0, 0.8, 0);

	/* BLACK horizontal line */
	glBegin(GL_LINES);
		glVertex2i(243, 170);
		glVertex2i(350, 170);
		glVertex2i(243, 171);
		glVertex2i(350, 171);
	glEnd();
}

void displayLine2() {
	/* Select colour to WHITE */
	glColor3f(0, 0.8, 0);

	/* GREEN horizontal line */
	glBegin(GL_LINES);
		glVertex2i(0+390, 36);
		glVertex2i(350+390, 36);
		glVertex2i(0+390, 37);
		glVertex2i(350+390, 37);
	glEnd();

	/* WHITE vertical line */
	glBegin(GL_LINES);
		glVertex2i(243+390, 39);
		glVertex2i(243+390, 560);
		glVertex2i(244+390, 39);
		glVertex2i(244+390, 560);
	glEnd();

	/* Set colour to BLACK */
	glColor3f(0, 0, 0);

	/* BLACK horizontal line */
	glBegin(GL_LINES);
		glVertex2i(0+390, 38);
		glVertex2i(240+390, 38);
		glVertex2i(0+390, 39);
		glVertex2i(240+390, 39);
	glEnd();
	
	/* BLACK vertical line */
	glBegin(GL_LINES);
		glVertex2i(241+390, 40);
		glVertex2i(241+390, 560);
		glVertex2i(242+390, 40);
		glVertex2i(242+390, 560);
	glEnd();

	/* Set colour to WHITE */
	glColor3f(0, 0.8, 0);

	/* BLACK horizontal line */
	glBegin(GL_LINES);
		glVertex2i(243+390, 170);
		glVertex2i(350+390, 170);
		glVertex2i(243+390, 171);
		glVertex2i(350+390, 171);
	glEnd();
}

/**************************************************
Displays the score
**************************************************/
void displayScore(string scoreNum) {
	int l1=0;
	string scoreText="SCORE";

		glColor3f(1, 1, 1);
		glBegin(GL_QUADS);				//Start drawing quads
			glVertex2f(244, 525);				//first coordinate
			glVertex2f(350, 525);				//second coordinate
			glVertex2f(350, 480);				//third coordinate (now blue)
			glVertex2f(244, 480);				//last coordinate
		glEnd();
		glColor3f(0, 0, 0);
		/* Get length - avoid trash output */
		l1 = scoreNum.length();
		glRasterPos2i(280, 490);
		for(int i=0; i<l1; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scoreNum[i]);

		glColor3f(0.10, 0.10, 0.10);
		glBegin(GL_QUADS);				//Start drawing quads
			glVertex2f(260, 540);				//first coordinate
			glVertex2f(335, 540);				//second coordinate
			glVertex2f(335, 510);				//third coordinate (now blue)
			glVertex2f(260, 510);				//last coordinate
		glEnd();

		glColor3f(0, 0.80, 0);
		glBegin(GL_LINES);
			glVertex2f(263, 511);
			glVertex2f(263, 540);
			glVertex2f(262, 510);
			glVertex2f(262, 541);
		
			glVertex2f(334, 511);
			glVertex2f(334, 540);
			glVertex2f(333, 510);
			glVertex2f(333, 541);
		
			glVertex2f(262, 540);
			glVertex2f(334, 540);
			glVertex2f(262, 512);
			glVertex2f(334, 512);
		
			glVertex2f(263, 541);
			glVertex2f(333, 541);
			glVertex2f(263, 511);
			glVertex2f(333, 511);
		glEnd();

		/* Set colour to print */
		glColor3f(0, 0.8, 0);

		/* Display the Score text */
		glRasterPos2i(265, 518);
		for(int i=0; i<5; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scoreText[i]);	
}

void displayScore2(string scoreNum) {
	int l1=0;
	string scoreText="SCORE";

		glColor3f(1, 1, 1);
		glBegin(GL_QUADS);				//Start drawing quads
			glVertex2f(244+390, 525);				//first coordinate
			glVertex2f(350+390, 525);				//second coordinate
			glVertex2f(350+390, 480);				//third coordinate (now blue)
			glVertex2f(244+390, 480);				//last coordinate
		glEnd();
	
		glColor3f(0, 0, 0);
		/* Get length - avoid trash output */
		l1 = scoreNum.length();
		glRasterPos2i(280+390, 490);
		for(int i=0; i<l1; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scoreNum[i]);

		glColor3f(0.10, 0.10, 0.10);
		glBegin(GL_QUADS);				//Start drawing quads
			glVertex2f(260+390, 540);				//first coordinate
			glVertex2f(335+390, 540);				//second coordinate
			glVertex2f(335+390, 510);				//third coordinate (now blue)
			glVertex2f(260+390, 510);				//last coordinate
		glEnd();

		glColor3f(0, 0.80, 0);
		glBegin(GL_LINES);
			glVertex2f(263+390, 511);
			glVertex2f(263+390, 540);
			glVertex2f(262+390, 510);
			glVertex2f(262+390, 541);
		
			glVertex2f(334+390, 511);
			glVertex2f(334+390, 540);
			glVertex2f(333+390, 510);
			glVertex2f(333+390, 541);
		
			glVertex2f(262+390, 540);
			glVertex2f(334+390, 540);
			glVertex2f(262+390, 512);
			glVertex2f(334+390, 512);
		
			glVertex2f(263+390, 541);
			glVertex2f(333+390, 541);
			glVertex2f(263+390, 511);
			glVertex2f(333+390, 511);
		glEnd();

		/* Set colour to print */
		glColor3f(0, 0.8, 0);

		/* Display the Score text */
		glRasterPos2i(265+390, 518);
		for(int i=0; i<5; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scoreText[i]);
}

/**************************************************
Display the side text
**************************************************/
void displaySideText() {
	string nextText="lines";
	string bText="b    :Start";
	string sText="s    :Left";
	string dText="d    :Right";
	string spaceText="space:Down";
	string escText="esc  :Exit";
	string pauseText="p    :Pause";
	int l2=0, l3=0, l4=0, l5=0, l6=0, l7=0, l8=0;

		l2 = nextText.length();
		l3 = bText.length();
		l4 = sText.length();
		l5 = dText.length();
		l6 = escText.length();
		l7 = spaceText.length();
		l8 = pauseText.length();

		/* Set colour to print */
		glColor3f(0.80, 0.80, 0.80);

		/* Set colour to print */
		glColor3f(1, 1, 1);

		/* Display the s text */
		glRasterPos2i(248, 150);
		for(int i=0; i<l3; i++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, bText[i]);

		/* Display the d text */
		glRasterPos2i(248, 130);
		for(int i=0; i<l4; i++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, sText[i]);
		
		/* Display the d text */
		glRasterPos2i(248, 110);
		for(int i=0; i<l5; i++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, dText[i]);
		
		/* Display the d text */
		glRasterPos2i(248, 90);
		for(int i=0; i<l7; i++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, spaceText[i]);
			
		/* Display the Esc text */
		glRasterPos2i(248, 70);
		for(int i=0; i<l6; i++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, escText[i]);
		
		/* Display the Esc text */
		glRasterPos2i(248, 50);
		for(int i=0; i<l8; i++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, pauseText[i]);
}

void displaySideText2() {
	string nextText="lines";
	string bText="b    :Start";
	string sText="4    :Left";
	string dText="5    :Right";
	string spaceText="1    :Down";
	string escText="esc  :Exit";
	string pauseText="p    :Pause";
	int l2=0, l3=0, l4=0, l5=0, l6=0, l7=0, l8=0;

		l2 = nextText.length();
		l3 = bText.length();
		l4 = sText.length();
		l5 = dText.length();
		l6 = escText.length();
		l7 = spaceText.length();
		l8 = pauseText.length();

		/* Set colour to print */
		glColor3f(0.80, 0.80, 0.80);

		/* Set colour to print */
		glColor3f(1, 1, 1);

		/* Display the s text */
		glRasterPos2i(248+390, 150);
		for(int i=0; i<l3; i++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, bText[i]);

		/* Display the d text */
		glRasterPos2i(248+390, 130);
		for(int i=0; i<l4; i++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, sText[i]);
		
		/* Display the d text */
		glRasterPos2i(248+390, 110);
		for(int i=0; i<l5; i++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, dText[i]);
		
		/* Display the d text */
		glRasterPos2i(248+390, 90);
		for(int i=0; i<l7; i++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, spaceText[i]);
			
		/* Display the Esc text */
		glRasterPos2i(248+390, 70);
		for(int i=0; i<l6; i++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, escText[i]);
		
		/* Display the Esc text */
		glRasterPos2i(248+390, 50);
		for(int i=0; i<l8; i++)
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, pauseText[i]);
}

/**************************************************
Display the gameover and restart text
**************************************************/
void displayGameOver() {
	string resText="Press b to restart the game";
	string goText="Game Over";
	int l1=resText.length();
	int l2=goText.length();
		/* Set colour to print */
		glColor3f(1, 0, 0);

		/* Display options */
		glRasterPos2i(50, 15);
		for(int i=0; i<l1; i++) {
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, resText[i]);
		}

		/* Display options */
		glRasterPos2i(140, 400);
		for(int i=0; i<l2; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, goText[i]);
		}
		
}

/**************************************************
Display the gameover and restart text
**************************************************/
void displayGameOver2() {
	string resText="Press b to restart the game";
	string goText="Game Over";
	int l1=resText.length();
	int l2=goText.length();
		/* Set colour to print */
		glColor3f(1, 0, 0);

		/* Display options */
		glRasterPos2i(50+390, 15);
		for(int i=0; i<l1; i++) {
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, resText[i]);
		}

		/* Display options */
		glRasterPos2i(140+390, 400);
		for(int i=0; i<l2; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, goText[i]);
		}
}

/*************************************************
Displays a random image to the screen
*************************************************/
void displayImage(void) {
		/* Generate random object */
		switch(randNum) {
			case 1:
				//cout << "A paper created at\t" << indexCol << "x" << indexRow << endl;
				if( PLAYING == 0) {
					glRasterPos2i(indexCol, indexRow+40);
					indexRow += 40;
				}else {
					glRasterPos2i(indexCol, indexRow);
				}
					glDrawPixels(ROW, COL, GL_LUMINANCE, GL_UNSIGNED_BYTE, paper);
				break;
			case 2:
				//cout << "A rock created at\t" << indexCol << "x" << indexRow << endl;
				if( PLAYING == 0) {
					glRasterPos2i(indexCol, indexRow+40);
					indexRow += 40;
				}else {
					glRasterPos2i(indexCol, indexRow);
				}
				glDrawPixels(ROW, COL, GL_LUMINANCE, GL_UNSIGNED_BYTE, rock);
				break;
			case 3:
				//cout << "A scissor created at\t" << indexCol << "x" << indexRow << endl;
				if( PLAYING == 0) {
					glRasterPos2i(indexCol, indexRow+40);
					indexRow += 40;
				}else {
					glRasterPos2i(indexCol, indexRow);
				}
				glDrawPixels(ROW, COL, GL_LUMINANCE, GL_UNSIGNED_BYTE, scissors);
				break;
			case 4:
				//cout << "A RED SHAPE created at\t" << indexCol << "x" << indexRow << endl;
				glColor3f(1,0,0);			// Red colour
				if( PLAYING == 0) {
					glRasterPos2i(indexCol, indexRow+40);
					indexRow += 40;
				}else {
					glRasterPos2i(indexCol, indexRow);
				}
				glDrawPixels(ROW, COL, GL_RED, GL_UNSIGNED_BYTE, red);
				break;
			case 5:
				//cout << "A BLUE SHAPE created at\t" << indexCol << "x" << indexRow << endl;
				glColor3f(0,0,1);			// Blue colour
				if( PLAYING == 0) {
					glRasterPos2i(indexCol, indexRow+40);
					indexRow += 40;
				}else {
					glRasterPos2i(indexCol, indexRow);
				}
				glDrawPixels(ROW, COL, GL_BLUE, GL_UNSIGNED_BYTE, blue);
				break;
			case 6:
				//cout << "A BOMB created at\t" << indexCol << "x" << indexRow << endl;
				if( PLAYING == 0) {
					glRasterPos2i(indexCol, indexRow+40);
					indexRow += 40;
				}else {
					glRasterPos2i(indexCol, indexRow);
				}
				glDrawPixels(ROW, COL, GL_LUMINANCE, GL_UNSIGNED_BYTE, bomb);
				break;
			default:
				break;
		}
		glFlush();
}

void displayImage2(void) {
		/* Generate random object */
		switch(randNum2) {
			case 1:
				//cout << "A paper created at\t" << indexCol << "x" << indexRow << endl;
				if( PLAYING == 0) {
					glRasterPos2i(indexCol2, indexRow2+40);
					indexRow2 += 40;
				}else {
					glRasterPos2i(indexCol2, indexRow2);
				}
					glDrawPixels(ROW, COL, GL_LUMINANCE, GL_UNSIGNED_BYTE, paper);
				break;
			case 2:
				//cout << "A rock created at\t" << indexCol << "x" << indexRow << endl;
				if( PLAYING == 0) {
					glRasterPos2i(indexCol2, indexRow2+40);
					indexRow2 += 40;
				}else {
					glRasterPos2i(indexCol2, indexRow2);
				}
				glDrawPixels(ROW, COL, GL_LUMINANCE, GL_UNSIGNED_BYTE, rock);
				break;
			case 3:
				//cout << "A scissor created at\t" << indexCol << "x" << indexRow << endl;
				if( PLAYING == 0) {
					glRasterPos2i(indexCol2, indexRow2+40);
					indexRow2 += 40;
				}else {
					glRasterPos2i(indexCol2, indexRow2);
				}
				glDrawPixels(ROW, COL, GL_LUMINANCE, GL_UNSIGNED_BYTE, scissors);
				break;
			case 4:
				//cout << "A RED SHAPE created at\t" << indexCol << "x" << indexRow << endl;
				glColor3f(1,0,0);			// Red colour
				if( PLAYING == 0) {
					glRasterPos2i(indexCol2, indexRow2+40);
					indexRow2 += 40;
				}else {
					glRasterPos2i(indexCol2, indexRow2);
				}
				glDrawPixels(ROW, COL, GL_RED, GL_UNSIGNED_BYTE, red);
				break;
			case 5:
				//cout << "A BLUE SHAPE created at\t" << indexCol << "x" << indexRow << endl;
				glColor3f(0,0,1);			// Blue colour
				if( PLAYING == 0) {
					glRasterPos2i(indexCol2, indexRow2+40);
					indexRow2 += 40;
				}else {
					glRasterPos2i(indexCol2, indexRow2);
				}
				glDrawPixels(ROW, COL, GL_BLUE, GL_UNSIGNED_BYTE, blue);
				break;
			case 6:
				//cout << "A BOMB created at\t" << indexCol << "x" << indexRow << endl;
				if( PLAYING == 0) {
					glRasterPos2i(indexCol2, indexRow2+40);
					indexRow2 += 40;
				}else {
					glRasterPos2i(indexCol2, indexRow2);
				}
				glDrawPixels(ROW, COL, GL_LUMINANCE, GL_UNSIGNED_BYTE, bomb);
				break;
			default:
				break;
		}
		glFlush();
}

void displayNext() {
	// White block
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
		glVertex2f(260, 270);
		glVertex2f(330, 270);
		glVertex2f(330, 200);
		glVertex2f(260, 200);
	glEnd();

	// Green lines arround the block
	glColor3f(0, 0.80, 0);
	glBegin(GL_LINES);
		glVertex2f(259, 199);
		glVertex2f(259, 271);
		glVertex2f(258, 198);
		glVertex2f(258, 272);
		
		glVertex2f(332, 198);
		glVertex2f(332, 272);
		glVertex2f(333, 199);
		glVertex2f(333, 271);
		
		glVertex2f(257, 272);
		glVertex2f(333, 272);
		glVertex2f(258, 273);
		glVertex2f(332, 273);
		
		glVertex2f(257, 197);
		glVertex2f(333, 197);
		glVertex2f(258, 196);
		glVertex2f(332, 196);
	glEnd();
	

	if( END == 1 ) {
		randNum = next;
		next = generateNum();
		END=0;
	}else if (PLAYING == 0) {
		next = generateNum();
		randNum = next;
	}

	// display the next image
	switch(next) {
		case 1:
			glRasterPos2i(275, 215);
			glDrawPixels(ROW, COL, GL_LUMINANCE, GL_UNSIGNED_BYTE, paper);
			break;
		case 2:
			glRasterPos2i(275, 215);
			glDrawPixels(ROW, COL, GL_LUMINANCE, GL_UNSIGNED_BYTE, rock);
			break;
		case 3:
			glRasterPos2i(275, 215);
			glDrawPixels(ROW, COL, GL_LUMINANCE, GL_UNSIGNED_BYTE, scissors);
			break;
		case 4:
			glRasterPos2i(275, 215);
			glDrawPixels(ROW, COL, GL_RED, GL_UNSIGNED_BYTE, red);
			break;
		case 5:
			glRasterPos2i(275, 215);
			glDrawPixels(ROW, COL, GL_BLUE, GL_UNSIGNED_BYTE, blue);
			break;
		case 6:
			glRasterPos2i(275, 215);
			glDrawPixels(ROW, COL, GL_LUMINANCE, GL_UNSIGNED_BYTE, bomb);
			break;
		default:
			break;
	}
	glFlush();
}

void displayNext2() {
	// White block
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
		glVertex2f(260+390, 270);
		glVertex2f(330+390, 270);
		glVertex2f(330+390, 200);
		glVertex2f(260+390, 200);
	glEnd();

	// Green lines arround the block
	glColor3f(0, 0.80, 0);
	glBegin(GL_LINES);
		glVertex2f(259+390, 199);
		glVertex2f(259+390, 271);
		glVertex2f(258+390, 198);
		glVertex2f(258+390, 272);
		
		glVertex2f(332+390, 198);
		glVertex2f(332+390, 272);
		glVertex2f(333+390, 199);
		glVertex2f(333+390, 271);
		
		glVertex2f(257+390, 272);
		glVertex2f(333+390, 272);
		glVertex2f(258+390, 273);
		glVertex2f(332+390, 273);
		
		glVertex2f(257+390, 197);
		glVertex2f(333+390, 197);
		glVertex2f(258+390, 196);
		glVertex2f(332+390, 196);
	glEnd();
	

	if( END2 == 1 ) {
		randNum2 = next2;
		next2 = generateNum2();
		END2=0;
	}else if (PLAYING == 0) {
		next2 = generateNum2();
		randNum2 = next2;
	}

	// display the next image
	switch(next2) {
		case 1:
			glRasterPos2i(275+390, 215);
			glDrawPixels(ROW, COL, GL_LUMINANCE, GL_UNSIGNED_BYTE, paper);
			break;
		case 2:
			glRasterPos2i(275+390, 215);
			glDrawPixels(ROW, COL, GL_LUMINANCE, GL_UNSIGNED_BYTE, rock);
			break;
		case 3:
			glRasterPos2i(275+390, 215);
			glDrawPixels(ROW, COL, GL_LUMINANCE, GL_UNSIGNED_BYTE, scissors);
			break;
		case 4:
			glRasterPos2i(275+390, 215);
			glDrawPixels(ROW, COL, GL_RED, GL_UNSIGNED_BYTE, red);
			break;
		case 5:
			glRasterPos2i(275+390, 215);
			glDrawPixels(ROW, COL, GL_BLUE, GL_UNSIGNED_BYTE, blue);
			break;
		case 6:
			glRasterPos2i(275+390, 215);
			glDrawPixels(ROW, COL, GL_LUMINANCE, GL_UNSIGNED_BYTE, bomb);
			break;
		default:
			break;
	}
	glFlush();
}

void displayObj() {
	for(int i=0; i<13; i++) {
		for(int j=0; j<6; j++) {
			if(V[i][j].getActive() == 1) {
				V[i][j].printItem(i, j);
			}
		}
	}
}

void displayObj2() {
	for(int i=0; i<13; i++) {
		for(int j=0; j<6; j++) {
			if(V2[i][j].getActive() == 1) {
				V2[i][j].printItem2(i, j);
			}
		}
	}
}

void displayLeftLayer() {
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);				//Start drawing quads
		glVertex2f(242, 560);				//first coordinate
		glVertex2f(350, 560);				//second coordinate
		glVertex2f(350, 40);				//third coordinate (now blue)
		glVertex2f(242, 40);				//last coordinate
	glEnd();
	glBegin(GL_QUADS);				//Start drawing quads
		glVertex2f(0, 0);				//first coordinate
		glVertex2f(0, 40);				//second coordinate
		glVertex2f(350, 40);				//third coordinate (now blue)
		glVertex2f(350, 0);				//last coordinate
	glEnd();
	glColor3f(0.18, 0.3, 0.33);
}

void displayLeftLayer2() {
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);				//Start drawing quads
		glVertex2f(242+390, 560);				//first coordinate
		glVertex2f(350+390, 560);				//second coordinate
		glVertex2f(350+390, 40);				//third coordinate (now blue)
		glVertex2f(242+390, 40);				//last coordinate
	glEnd();
	glBegin(GL_QUADS);				//Start drawing quads
		glVertex2f(0+390, 0);				//first coordinate
		glVertex2f(0+390, 40);				//second coordinate
		glVertex2f(350+390, 40);				//third coordinate (now blue)
		glVertex2f(350+390, 0);				//last coordinate
	glEnd();
	glColor3f(0.18, 0.3, 0.33);
}

void displayMiddleLine() {
	glColor3f(0, 0.80, 0);
	glBegin(GL_QUADS);
		glVertex2f(350, 560);
		glVertex2f(350, 0);
		glVertex2f(390, 0);
		glVertex2f(390, 560);
	glEnd();
}
