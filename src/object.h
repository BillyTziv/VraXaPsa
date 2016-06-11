/******************************************
The class below specidies methods and
attributes for the rock, paper scissors
images.
******************************************/
class object {
private:
	GLubyte item[40][40];
	int active;
	int type;
	int loaded;
	int r, c;
public:
	object() { active=0; loaded=0;}	// set active to 0
	void setActive() { active=1; }
	void setLoaded() { loaded=1; }
	int getActive() { return active; }
	void setItem(int x, int r1, int c1);	// save an image to the cell
	int getType() { return type; }		// get type of image
	int getLoaded() { return loaded; }
	int getRowPos() { return r; }
	int getColPos() { return c; }
	
	void printItem(int x, int y);
	void printItem2(int x, int y);
	void setInactive() { active=0; }
	
};

// Prints the current image at given (x,y) position
void object::printItem(int x, int y) {
	x = (x+1)*40;	// calculates the colunm pixel
	y = y*40;		// calculates the row pixel
	glRasterPos2i(y, x);
	if( type == 4 ) {
		glDrawPixels(ROW, COL, GL_RED, GL_UNSIGNED_BYTE, item);
	}else if( type == 5 ) {
		glDrawPixels(ROW, COL, GL_BLUE, GL_UNSIGNED_BYTE, item);
	}else {
		glDrawPixels(ROW, COL, GL_LUMINANCE, GL_UNSIGNED_BYTE, item);	
	}
}

// Prints the current image at given (x,y) position
void object::printItem2(int x, int y) {
	x = (x+1)*40;	// calculates the colunm pixel
	y = y*40;		// calculates the row pixel
	glRasterPos2i(y+390, x);
	if( type == 4 ) {
		glDrawPixels(ROW, COL, GL_RED, GL_UNSIGNED_BYTE, item);
	}else if( type == 5 ) {
		glDrawPixels(ROW, COL, GL_BLUE, GL_UNSIGNED_BYTE, item);
	}else {
		glDrawPixels(ROW, COL, GL_LUMINANCE, GL_UNSIGNED_BYTE, item);	
	}
}

void object::setItem(int x, int r1, int c1) {
	type = x;
	r = r1; c = c1;
	switch(x) {
		case 1:
			for(int i=0; i<40; i++) {
				for(int j=0; j<40; j++) {
					item[i][j] = paper[i][j];
				}
			}
			break;
		case 2:
			for(int i=0; i<40; i++) {
				for(int j=0; j<40; j++) {
					item[i][j] = rock[i][j];
				}
			}
			break;
		case 3:
			for(int i=0; i<40; i++) {
				for(int j=0; j<40; j++) {
					item[i][j] = scissors[i][j];
				}
			}
			break;
		case 4:
			for(int i=0; i<40; i++) {
				for(int j=0; j<40; j++) {
					item[i][j] = red[i][j];
				}
			}
			break;
		case 5:
			for(int i=0; i<40; i++) {
				for(int j=0; j<40; j++) {
					item[i][j] = blue[i][j];
				}
			}
			break;
		default:
			break;
	}
}
