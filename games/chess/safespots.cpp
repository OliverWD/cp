#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

// Count number of unoccupied, attacked squares (given FEN representation)

bool taken[8][8];
char board[8][8];

void setTrue (int x, int y){
	if (0 <= x && x < 8 && 0 <= y && y < 8) {
		taken[x][y] = true;
	}
}

void setDiags(int x, int y) {
	int dx, dy, xn, yn;

	for (int dy = -1; dy <= 1; dy++) {
		for (int dx = -1; dx <= 1; dx++) {
			if (dy == 0 || dx == 0)
				continue;
			else {
				xn = dx + x; yn = dy + y;
				while (0 <= xn && xn < 8 && 0 <= yn && yn < 8) {
					if (board[xn][yn] == '.')
						taken[xn][yn] = true;
					else
						break;
					xn += dx; yn += dy;
				}
			}
		}
	}
}

void setKnight(int x, int y) {
	setTrue(x + 1, y + 2);
	setTrue(x + 1, y - 2);
	setTrue(x + 2, y + 1);
	setTrue(x + 2, y - 1);
	setTrue(x - 1, y + 2);
	setTrue(x - 1, y - 2);
	setTrue(x - 2, y + 1);
	setTrue(x - 2, y - 1);
}

void setPawn(bool white, int x, int y) {
	if (white) {
		setTrue(x + 1, y - 1);
		setTrue(x - 1, y - 1);
	} else {
		setTrue(x + 1, y + 1);
		setTrue(x - 1, y + 1);
	}
}

void setKing(int x, int y) {
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			setTrue(x + i, y + j);
		}
	}
}

void setLines(int x, int y) {
	int dx, dy, xn, yn;

	for (int dy = -1; dy <= 1; dy++) {
		for (int dx = -1; dx <= 1; dx++) {
			if ((dy == 0 || dx == 0) && !(dy == 0 && dx == 0)) {
				xn = dx + x; yn = dy + y;
				while (0 <= xn && xn < 8 && 0 <= yn && yn < 8) {
					if (board[xn][yn] == '.')
						taken[xn][yn] = true;
					else
						break;
					xn += dx; yn += dy;
				}
			}
		}
	}
}

void check() {
	char piece;
	for (int y = 0; y < 8; ++y) {
		for (int x = 0; x < 8; ++x) {
			piece = board[x][y];

			if (piece != '.') {
				if (piece == 'P') {
					setPawn(true, x, y);
				} else if (piece == 'p') {
					setPawn(false, x, y);
				} else {
					piece = tolower(piece);
					if (piece == 'n') {
						setKnight(x, y);
					} else if (piece == 'b') {
						setDiags(x, y);
					} else if (piece == 'r') {
						setLines(x, y);
					} else if (piece == 'q') {
						setLines(x, y);
						setDiags(x, y);
					} else if (piece == 'k') {
						setKing(x, y);
					}
				}
			}
		}
	}
}

int main () {

	string line;
	while (getline(cin, line)) {

		// initialise boards - Note: board[x][y] is the (x, y) coord
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				taken[j][i] = false;
				board[j][i] = '.';
			}
		}

		// Convert FEN input into board representation
		int x = 0; int y = 0;
		for (int i = 0; i < line.size(); i++) {
			char c = line[i];
			if (c == '/') {
				x = 0; y++;
			}
			else if (isdigit(c)) {
				x += (int) c - '0';
			}
			else {
				taken[x][y] = true; // taken if occupied
				board[x][y] = c;
				x++;
			}
		}

		// Go through board and case update taken
		check();

		// Count, update and out value
		int c = 0;
	  for (int i = 0; i < 8; ++i) {
	    for (int j = 0; j < 8; ++j) {
	      if (!taken[i][j]) {
	        c++;
	      }
	    }
	  }
	  printf("%d\n", c);
	}
}
