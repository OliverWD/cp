#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

char board[100][100];
char boardNext[100][100];

char match(char x, char y) {

	if (x == y)
		return x;

	if (x == 'R') {
		if (y == 'S')
			return 'R';
		 else
			return 'P';
	}

	if (x == 'S') {
		if (y == 'R')
			return 'R';
		else
			return 'S';
	}

	if (x == 'P') {
		if (y == 'R')
			return 'P';
		else
			return 'S';
	}

}

int main () {

  int TC; scanf("%d\n", &TC); bool first = true;
  while (TC--) {

			if (!first) {
				cout << endl;
			} else {
				first = false;
			}

      int r, c, n;
      scanf("%d %d %d\n", &r, &c, &n);

      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
					char cell;
          scanf("%c", &cell);
					board[j][i] = cell;
					boardNext[j][i] = cell;
        }
        scanf("\n");
      }

			for (int d = 0; d < n; d++) {
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						for (int x = -1; x <= 1; x++) {
							for (int y = -1; y <= 1; y++) {
								if ((x == 0 || y == 0) && (x != 0 || y != 0)) {
									int xn = j + x; int yn = i + y;
									if (0 <= xn && xn < c && 0 <= yn && yn < r) {

										// can change
										if (boardNext[xn][yn] == board[xn][yn]) {
											boardNext[xn][yn] = match(board[j][i], board[xn][yn]);
										}

									}
								}
							}
						}
					}
				}
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						board[j][i] = boardNext[j][i];
					}
				}
			}

			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					printf("%c", board[j][i]);
				}
				printf("\n");
			}


  }

}
