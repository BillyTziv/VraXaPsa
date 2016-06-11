/**************************************************
- moveDown
- moveFast
- moveLeft
- moveRight
**************************************************/
#include <time.h>

using namespace std;

struct timespec tim;

   
void moveDown(int value) {
	int tempRow = (indexRow-1)/40;
	int tempCol = indexCol/40;
		if( (GAMEOVER == 0) && (PAUSE == 0) ) {
			//cout << "tempRow: " << tempRow << "\ttempCol: " << tempCol << endl;
			//cout << "indexRow: " << indexRow << "\tindexCol: " << indexCol << endl;
			if( (indexRow > 40) && (V[tempRow-1][tempCol].getActive() == 0) ) {
				indexRow --;
			}else {
				//cout << "\t" << tempRow << endl;
				if(tempRow == 12) {
					GAMEOVER=1;
				}

				V[tempRow][tempCol].setItem(randNum, tempRow, tempCol);
				V[tempRow][tempCol].setActive();
				eat(tempRow, tempCol);
				textEffectX = indexRow;
				textEffectY = indexCol;
				dropAloneItems();

				/* Setup for the new object */
				END = 1;
				indexRow = 520;
				indexCol = 120;
				
			}
		}
		if( playerNum == 2 ) {
			int tempRow2 = (indexRow2-1)/40;
			int tempCol2 = (indexCol2-390)/40;
			if( (GAMEOVER2 == 0) && (PAUSE == 0) ) {
				cout << "tempRow: " << tempRow2 << "\ttempCol: " << tempCol2 << endl;
				cout << "indexRow: " << indexRow2 << "\tindexCol: " << indexCol2 << endl;
				if( (indexRow2 > 40) && (V2[tempRow2-1][tempCol2].getActive() == 0) ) {
					indexRow2 --;
				}else {
					//cout << "\t" << tempRow << endl;
					if(tempRow2 == 12) {
						GAMEOVER2=1;
					}

					V2[tempRow2][tempCol2].setItem(randNum2, tempRow2, tempCol2);
					V2[tempRow2][tempCol2].setActive();
					eat2(tempRow2, tempCol2);
					
					textEffectX2 = indexRow2;
					textEffectY2 = indexCol2;

					END2 = 1;
					dropAloneItems2();

					/* Setup for the new object */
					END2 = 1;
					indexRow2 = 520;
					indexCol2 = 120+390;
				}
			}
		}
			
		glFlush();
		glutPostRedisplay();
		glutTimerFunc(30, moveDown, 0);
}

void moveFast(int col) {
	col = col/40;
	int flag=0;
		if( GAMEOVER == 0 ) {
			for(int i=0; i<13; i++) {
				if( (V[i][col].getActive() == 0) && (flag == 0) ) {
					flag = 1;
					V[i][col].setActive();
					V[i][col].setItem(randNum, i, col);
					eat(i, col);
					dropAloneItems();
					END=1;
					textEffectX = (i+1)*40;
					textEffectY = col*40;
					
					indexRow=520;
					indexCol=120;
				}
			}
		}
		glFlush();
}

void moveFast2(int col) {
	col = (col-390)/40;
	int flag=0;
		if( GAMEOVER2 == 0 ) {
			for(int i=0; i<13; i++) {
				if( (V2[i][col].getActive() == 0) && (flag == 0) ) {
					flag = 1;
					V2[i][col].setActive();
					V2[i][col].setItem(randNum2, i, col);
					eat2(i, col);
					dropAloneItems2();
					END2=1;
					textEffectX2 = (i+1)*40;
					textEffectY2 = col*40+390;
					indexRow2 = 520;
					indexCol2 = 120+390;

				}
			}
		}
		glFlush();
}

void moveLeft() {
	int x=indexRow/40-1;
	int y=indexCol/40-1;
		if( (indexCol >= 40) && (V[x][y].getActive() == 0) ) { 
			indexCol = indexCol-40;
		}
		glFlush();
}

void moveRight() {
	int x=indexRow/40-1;
	int y=indexCol/40+1;
		if( (indexCol <= 160) && (V[x][y].getActive() == 0) ) {
			indexCol = indexCol+40;
		}
		glFlush();
}

void moveLeft2() {
	int x=indexRow2/40-1;
	int y=(indexCol2-390)/40-1;
		if( (indexCol2 >= 40+390) && (V2[x][y].getActive() == 0) ) { 
			indexCol2 = indexCol2-40;
		}
		glFlush();
}

void moveRight2() {
	int x=indexRow2/40-1;
	int y=(indexCol2-390)/40+1;
		if( (indexCol2 <= 160+390) && (V2[x][y].getActive() == 0) ) {
			indexCol2 = indexCol2+40;
		}
		glFlush();
}
