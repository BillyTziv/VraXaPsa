void loadNeighbourg(int x, int y, int z, int c) {
	// test for segmentation and Active or not and double load
	if((x < 15) && (V[x+1][y][z].getActive() == 1) && (V[x+1][y][z].getLoaded() == 0) && (V[x+1][y][z].getColour() == c) ) {
		myQ.push(V[x+1][y][z]);
	}
	if((y < 15) && (V[x][y+1][z].getActive() == 1) && (V[x][y+1][z].getLoaded() == 0) && (V[x][y+1][z].getColour() == c) ) {
		myQ.push(V[x][y+1][z]);
	}
	if((x > 0) && (V[x-1][y][z].getActive() == 1) && (V[x-1][y][z].getLoaded() == 0) && (V[x-1][y][z].getColour() == c) ) {
		myQ.push(V[x-1][y][z]);
	}
	if((y > 0) && (V[x][y-1][z].getActive() == 1) && (V[x][y-1][z].getLoaded() == 0) && (V[x][y-1][z].getColour() == c) ) {
		myQ.push(V[x][y-1][z]);
	}
	if((z < 15) && (V[x][y][z+1].getActive() == 1) && (V[x][y][z+1].getLoaded() == 0) && (V[x][y][z+1].getColour() == c) ) {
		myQ.push(V[x][y][z+1]);
	}
	if((z > 0) && (V[x][y][z-1].getActive() == 1) && (V[x][y][z-1].getLoaded() == 0) && (V[x][y][z-1].getColour() == c) ) {
		myQ.push(V[x][y][z-1]);
	}
}
