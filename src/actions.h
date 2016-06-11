/**================= Functions =====================
- updateScore
- generateNum
- restartGame
- loadToEat
- canEat
- eat
- dropAloneItems
=================================================**/

using namespace std;

/**************************************************
String concatenation
**************************************************/
string updateScore(int s) {
	string str3, temp;
	ostringstream str2;
		str2 << s;
		str3 = str2.str().c_str();
return str3;
}

/**************************************************
Generate a random number from [1-3]
**************************************************/
int generateNum() {
	int num;
		srand(time(NULL));
		num = 1 + (rand() % 6);
return num;
}

int generateNum(int i) {
	int num;
		srand(i*3);
		//for(int i=0; i<20; i++) {
			num = 1 + (rand() % 6);
			cout << "Random Number: " << num << endl;
		//}
return num;
}

int generateNum2() {
	int num;
		srand(time(NULL));
		num = 1 + (rand() % 6);
return num;
}

/**************************************************
After the eat function V array must be updated so
there will be no images with an empty field below
**************************************************/
void dropAloneItems() {
	for(int j=0; j<6; j++) {
		int minRow = 12;
		for(int i=0; i<13; i++) {
			if( (V[i][j].getActive() == 0) && (i < minRow) ) {
				minRow=i;
			}
		}
		for(int i=0;i<13;i++) {
			if( (V[i][j].getActive() == 1) && (i > minRow) ) {
				V[minRow][j].setActive();
				V[minRow][j].setItem(V[i][j].getType(), minRow, j);
				minRow=minRow+1;
				V[i][j].setInactive();
			}
		
		}
	}
}

void dropAloneItems2() {
	for(int j=0; j<6; j++) {
		int minRow = 12;
		for(int i=0; i<13; i++) {
			if( (V2[i][j].getActive() == 0) && (i < minRow) ) {
				minRow=i;
			}
		}
		for(int i=0;i<13;i++) {
			if( (V2[i][j].getActive() == 1) && (i > minRow) ) {
				V2[minRow][j].setActive();
				V2[minRow][j].setItem(V2[i][j].getType(), minRow, j);
				minRow=minRow+1;
				V2[i][j].setInactive();
			}
		
		}
	}
}

void giveItems(int type, int n) {
	int gn, flag=0, t;
	switch(type) {
			case 1:	// papers
					t=2;
				break;
			case 2:	// rock
					t=3;
				break;
			case 3:	// scissors
					t=1;
				break;
			default:
				break;
		}
	for(int i=0; i<n; i++) {
		gn = generateNum(i);
		for( int j=0; j<13; j++) {
			if( (V2[j][gn].getActive() == 0) && (flag == 0) ) {
				if(j==12) {
					GAMEOVER2=1;
				}
				V2[j][gn].setItem(t, j, gn);
				V2[j][gn].setActive();
				flag = 1;
			}
		}
		flag=0;
	}	
	dropAloneItems2();
}

void giveItems2(int type, int n) {
	int gn, flag=0, t;
	switch(type) {
			case 1:	// papers
					t=2;
				break;
			case 2:	// rock
					t=3;
				break;
			case 3:	// scissors
					t=1;
				break;
			default:
				break;
		}
	for(int i=0; i<n; i++) {
		gn = generateNum(i);
		for( int j=0; j<13; j++) {
			if( (V[j][gn].getActive() == 0) && (flag == 0) ) {
				if(j==12) {
					GAMEOVER=1;
				}
				V[j][gn].setItem(t, j, gn);
				V[j][gn].setActive();
				flag = 1;
			}
		}
		flag=0;
	}
	dropAloneItems();
}
/**************************************************
Initiate a new game. Score will be zero and all the
images will be removed!
**************************************************/
void restartGame() {
	GAMEOVER=0;
	GAMEOVER2=0;
	/* restart game */
	for(int i=0; i<13; i++) {
		for(int j=0; j<6; j++) {
			V[i][j].setInactive();
		}
	}
	SCORE=0;
	for(int i=0; i<13; i++) {
		for(int j=0; j<6; j++) {
			V2[i][j].setInactive();
		}
	}
	SCORE2=0;
	
	indexCol=120, indexRow=520;
	indexCol2 = 120+390, indexRow2=520;
}

/**************************************************
Loads the four neighbours of the image at position
(r, c)
**************************************************/
void loadToEat(int r, int c) {
	// test for segmentation and Active or not and double load
	if((r < 12) && (V[r+1][c].getActive() == 1) && (V[r+1][c].getLoaded() == 0) ) {
		myQ.push(V[r+1][c]);
	}
	if((c < 5) && (V[r][c+1].getActive() == 1) && (V[r][c+1].getLoaded() == 0)) {
		myQ.push(V[r][c+1]);
	}
	if((r > 0) && (V[r-1][c].getActive() == 1) && (V[r-1][c].getLoaded() == 0)) {
		myQ.push(V[r-1][c]);
	}
	if((c > 0) && (V[r][c-1].getActive() == 1) && (V[r][c-1].getLoaded() == 0)) {
		myQ.push(V[r][c-1]);
	}
}

void loadToEat2(int r, int c) {
	// test for segmentation and Active or not and double load
	if((r < 12) && (V2[r+1][c].getActive() == 1) && (V2[r+1][c].getLoaded() == 0) ) {
		myQ2.push(V2[r+1][c]);
	}
	if((c < 5) && (V2[r][c+1].getActive() == 1) && (V2[r][c+1].getLoaded() == 0)) {
		myQ2.push(V2[r][c+1]);
	}
	if((r > 0) && (V2[r-1][c].getActive() == 1) && (V2[r-1][c].getLoaded() == 0)) {
		myQ2.push(V2[r-1][c]);
	}
	if((c > 0) && (V2[r][c-1].getActive() == 1) && (V2[r][c-1].getLoaded() == 0)) {
		myQ2.push(V2[r][c-1]);
	}
}
/**************************************************
This function take an input (int) and according to
the number it returns what image can be eaten.
**************************************************/
int canEat(object tempObj, int type) {
		switch(type) {
			case 1:	// papers
					if( tempObj.getType() == 2) {
						return 1;
					}
				break;
			case 2:	// rock
					if( tempObj.getType() == 3) {
						return 1;
					}
				break;
			case 3:	// scissors
					if( tempObj.getType() == 1) {
						return 1;
					}
				break;
			default:
				break;
		}
return 0;
}

void loadRed(int r, int c) {
	// test for segmentation and Active or not and double load
	if((r < 12) && (V[r+1][c].getActive() == 1) && (V[r+1][c].getLoaded() == 0) && (V[r+1][c].getType() == 4) ) {
		myQ.push(V[r+1][c]);
	}
	if((c < 5) && (V[r][c+1].getActive() == 1) && (V[r][c+1].getLoaded() == 0) && (V[r][c+1].getType() == 4)) {
		myQ.push(V[r][c+1]);
	}
	if((r > 0) && (V[r-1][c].getActive() == 1) && (V[r-1][c].getLoaded() == 0)&& (V[r-1][c].getType() == 4)) {
		myQ.push(V[r-1][c]);
	}
	if((c > 0) && (V[r][c-1].getActive() == 1) && (V[r][c-1].getLoaded() == 0)&& (V[r][c-1].getType() == 4)) {
		myQ.push(V[r][c-1]);
	}
}

void loadBlue(int r, int c) {
	// test for segmentation and Active or not and double load
	if((r < 12) && (V[r+1][c].getActive() == 1) && (V[r+1][c].getLoaded() == 0)&& (V[r+1][c].getType() == 5) ) {
		myQ.push(V[r+1][c]);
	}
	if((c < 5) && (V[r][c+1].getActive() == 1) && (V[r][c+1].getLoaded() == 0)&& (V[r][c+1].getType() == 5)) {
		myQ.push(V[r][c+1]);
	}
	if((r > 0) && (V[r-1][c].getActive() == 1) && (V[r-1][c].getLoaded() == 0)&& (V[r-1][c].getType() == 5)) {
		myQ.push(V[r-1][c]);
	}
	if((c > 0) && (V[r][c-1].getActive() == 1) && (V[r][c-1].getLoaded() == 0)&& (V[r][c-1].getType() == 5)) {
		myQ.push(V[r][c-1]);
	}
}

void loadRed2(int r, int c) {
	// test for segmentation and Active or not and double load
	if((r < 12) && (V2[r+1][c].getActive() == 1) && (V2[r+1][c].getLoaded() == 0) && (V2[r+1][c].getType() == 4) ) {
		myQ2.push(V2[r+1][c]);
	}
	if((c < 5) && (V2[r][c+1].getActive() == 1) && (V2[r][c+1].getLoaded() == 0) && (V2[r][c+1].getType() == 4)) {
		myQ2.push(V2[r][c+1]);
	}
	if((r > 0) && (V2[r-1][c].getActive() == 1) && (V2[r-1][c].getLoaded() == 0)&& (V2[r-1][c].getType() == 4)) {
		myQ2.push(V2[r-1][c]);
	}
	if((c > 0) && (V2[r][c-1].getActive() == 1) && (V2[r][c-1].getLoaded() == 0)&& (V2[r][c-1].getType() == 4)) {
		myQ2.push(V2[r][c-1]);
	}
}

void loadBlue2(int r, int c) {
	// test for segmentation and Active or not and double load
	if((r < 12) && (V2[r+1][c].getActive() == 1) && (V2[r+1][c].getLoaded() == 0)&& (V2[r+1][c].getType() == 5) ) {
		myQ2.push(V2[r+1][c]);
	}
	if((c < 5) && (V2[r][c+1].getActive() == 1) && (V2[r][c+1].getLoaded() == 0)&& (V2[r][c+1].getType() == 5)) {
		myQ2.push(V2[r][c+1]);
	}
	if((r > 0) && (V2[r-1][c].getActive() == 1) && (V2[r-1][c].getLoaded() == 0)&& (V2[r-1][c].getType() == 5)) {
		myQ2.push(V2[r-1][c]);
	}
	if((c > 0) && (V2[r][c-1].getActive() == 1) && (V2[r][c-1].getLoaded() == 0)&& (V2[r][c-1].getType() == 5)) {
		myQ2.push(V2[r][c-1]);
	}
}


/* NUCLEAR */
void kaboom(int r, int c) {
	object tempObj;

		V[r][c].setInactive();
		loadToEat(r, c);	// load neighbours
		while(!myQ.empty()) {

			tempObj = myQ.front();
			int r1=tempObj.getRowPos(), c1=tempObj.getColPos();
			if( tempObj.getType() == 4 ) {
				loadRed(r1, c1);
			}else if( tempObj.getType() ==  5 ) {
				loadBlue(r1,c1);
			}
			V[r1][c1].setInactive();
			myQ.pop();

			countEaten++;
		}
}

void kaboom2(int r, int c) {
	object tempObj;
		V2[r][c].setInactive();
		loadToEat2(r, c);	// load neighbours
		while(!myQ2.empty()) {

			tempObj = myQ2.front();
			int r1=tempObj.getRowPos(), c1=tempObj.getColPos();
			if( tempObj.getType() == 4 ) {
				loadRed2(r1, c1);
			}else if( tempObj.getType() ==  5 ) {
				loadBlue2(r1,c1);
			}
			V2[r1][c1].setInactive();
			myQ2.pop();

			countEaten2++;
		}
}

/**************************************************
Function about eating. Every image-object which just
felt at the bottom calls the code below and eat his
neighbours and their neighbours.
**************************************************/
void eat(int r, int c) {
	int flag=0;
	object tempObj;
	int t = V[r][c].getType();
	countEaten=0;
	
		if( t != 6 ) {
			loadToEat(r, c);
			nextRow = 12;
			nextCol = 0;

			//cout << "I am in baby!" << endl;
			while(!myQ.empty()) {
				//cout << "I am in while loop!" << endl;
				tempObj = myQ.front();

				if( canEat(tempObj, t) == 1 ) {	// trwgetai
					countEaten++;
					// mikroterh grammh kai megalyterh sthlh
					if( nextCol < tempObj.getColPos() ) {
						nextRow = tempObj.getRowPos();
						nextCol = tempObj.getColPos();
					}

					if( (nextRow > tempObj.getRowPos()) && (nextCol == tempObj.getColPos()) ) {
						nextRow = tempObj.getRowPos();
						nextCol = tempObj.getColPos();
					}

					cout << "New Item in Pos: " << nextRow << "x" << nextCol << endl;
					int r1=tempObj.getRowPos(), c1=tempObj.getColPos();
					loadToEat(r1, c1);
					//cout << "Check in :" << r1 << "x" << c1 << endl;
					V[r1][c1].setInactive();
					flag = 1;
				}
				myQ.pop();
			}
			
			giveItems(t, countEaten);
	
			if(flag == 1) {				// something have been eaten
				V[r][c].setInactive();	// set previours position to inactive - remove the previous image
				V[nextRow][nextCol].setItem(V[r][c].getType(), nextRow, nextCol);	// set the new image to the right position
				V[nextRow][nextCol].setActive(); 	// set the new position as active
			}
		}else{
			kaboom(r, c);
		}

		// calculate the Score according to the algorithm given
		SCORE += (10*countEaten)+(countEaten*countEaten);

		// sound for x5 and x10 
		if( ( countEaten >= 5 ) && ( countEaten < 10) ) {
			irrklang::ISoundEngine* engine;
			engine = irrklang::createIrrKlangDevice();
			if (!engine)
				cout << "Could not startup engine" << endl;
			engine->play2D("sound/Combowhore.wav", false);
		}else if(countEaten >= 10){
			irrklang::ISoundEngine* engine;
			engine = irrklang::createIrrKlangDevice();
			if (!engine)
				cout << "Could not startup engine" << endl;
			engine->play2D("sound/HolyShit.wav", false);
		}
}

void eat2(int r, int c) {
	int flag=0;
	object tempObj;
	int t = V2[r][c].getType();
	countEaten2=0;
	
		if( t != 6 ) {
			loadToEat2(r, c);
			nextRow2 = 12;
			nextCol2 = 0;

			//cout << "I am in baby!" << endl;
			while(!myQ2.empty()) {
				//cout << "I am in while loop!" << endl;
				tempObj = myQ2.front();

				if( canEat(tempObj, t) == 1 ) {	// trwgetai
					countEaten2++;
					// mikroterh grammh kai megalyterh sthlh
					if( nextCol2 < tempObj.getColPos() ) {
						nextRow2 = tempObj.getRowPos();
						nextCol2 = tempObj.getColPos();
					}

					if( (nextRow2 > tempObj.getRowPos()) && (nextCol2 == tempObj.getColPos()) ) {
						nextRow2 = tempObj.getRowPos();
						nextCol2 = tempObj.getColPos();
					}

					cout << "New Item in Pos: " << nextRow2 << "x" << nextCol2 << endl;
					int r1=tempObj.getRowPos(), c1=tempObj.getColPos();
					loadToEat2(r1, c1);
					//cout << "Check in :" << r1 << "x" << c1 << endl;
					V2[r1][c1].setInactive();
					flag = 1;
				}
				myQ2.pop();
			}
			
			giveItems2(t, countEaten2);
			if(flag == 1) {				// something have been eaten
				V2[r][c].setInactive();	// set previours position to inactive - remove the previous image
				V2[nextRow2][nextCol2].setItem(V2[r][c].getType(), nextRow2, nextCol2);	// set the new image to the right position
				V2[nextRow2][nextCol2].setActive(); 	// set the new position as active
			}
		}else{
			kaboom2(r, c);
		}

		// calculate the Score according to the algorithm given
		SCORE2 += (10*countEaten2)+(countEaten2*countEaten2);

		// sound for x5 and x10 
		if( ( countEaten2 >= 5 ) && ( countEaten2 < 10) ) {
			irrklang::ISoundEngine* engine;
			engine = irrklang::createIrrKlangDevice();
			if (!engine)
				cout << "Could not startup engine" << endl;
			engine->play2D("sound/Combowhore.wav", false);
		}else if(countEaten2 >= 10){
			irrklang::ISoundEngine* engine;
			engine = irrklang::createIrrKlangDevice();
			if (!engine)
				cout << "Could not startup engine" << endl;
			engine->play2D("sound/HolyShit.wav", false);
		}
}


