/*************************************************
- loadImage
*************************************************/
using namespace std;

/*************************************************
Load the 3 images and store the objects
*************************************************/
void loadImage(void) {
	ifstream paperFile, rockFile, scissorsFile, bombFile, redFile, blueFile;
	int tempPaper, tempRock, tempScissors, tempBomb, tempRed, tempBlue;
	string buf;
		cout << "\nLoading images...\n" << endl;
		paperFile.open("images/paper.pgm");			// opening paper.pgm
		rockFile.open("images/rock.pgm");			// opening rock.pgm
		scissorsFile.open("images/scissors.pgm");	// opening scissors.pgm
		bombFile.open("images/bomb.pgm");			// opening bomb.pgm
		redFile.open("images/red.pgm");				// opening red.pgm
		blueFile.open("images/blue.pgm");			// opening blue.pgm

		/* Check for errors in files opening */
		if(!paperFile) {
			cout << "Error opening 'paper.pgm'" << endl;
			exit(EXIT_FAILURE);
		}else if(!rockFile){
			cout << "Error opening 'rock.pgm'" << endl;
			exit(EXIT_FAILURE);
		}else if(!scissorsFile){
			cout << "Error opening 'scissors.pgm'" << endl;
			exit(EXIT_FAILURE);
		}else if(!bombFile){
			cout << "Error opening 'bomb.pgm'" << endl;
			exit(EXIT_FAILURE);
		}else if(!redFile){
			cout << "Error opening 'red.pgm'" << endl;
			exit(EXIT_FAILURE);
		}else if(!blueFile){
			cout << "Error opening 'blue.pgm'" << endl;
			exit(EXIT_FAILURE);
		}
		
		/* Get 4 first lines of the file */
		for(int i=0; i<4; i++)
			getline(paperFile, buf);

		for(int i=0; i<4; i++)
			getline(rockFile, buf);

		for(int i=0; i<4; i++)
			getline(scissorsFile, buf);

		for(int i=0; i<4; i++)
			getline(bombFile, buf);

		for(int i=0; i<4; i++)
			getline(redFile, buf);

		for(int i=0; i<4; i++)
			getline(blueFile, buf);

		/* Parse the files and store the images */
		for(int i=0; i<ROW; i++) {
			for(int j=0; j<COL; j++) {
				paperFile >> tempPaper;
				paper[ROW-1-i][j] = tempPaper;

				rockFile >> tempRock;
				rock[ROW-1-i][j] = tempRock;

				scissorsFile >> tempScissors;
				scissors[ROW-1-i][j] = tempScissors;

				bombFile >> tempBomb;
				bomb[ROW-1-i][j] = tempBomb;
				
				redFile >> tempRed;
				red[ROW-1-i][j] = tempRed;

				blueFile >> tempBlue;
				blue[ROW-1-i][j] = tempBlue;
			}
		}
		cout << "Images have been loaded successfully!" << endl;
}
