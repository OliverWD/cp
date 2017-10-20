#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

int main () {

	int n, m; int x = 1;
	int board[101][101];
	bool bombCoords[101][101];

	while(scanf("%d %d\n", &n, &m), (m || n)) {

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				board[j][i] = 0;
				bombCoords[j][i] = 0;
			}
		}

		int lines = n;
		while (lines--) {
			int columns = m; char square;
			while (columns--) {
				scanf("%c", &square);

				if (square == '*') {
					bombCoords[m - columns - 1][n - lines - 1] = true;
					for (int i = -1; i <= 1; i++) {
						for (int j = -1; j <= 1; j++) {
							if (i == 0 && j == 0)
								continue;
							int xn = (m - columns - 1) + i; int yn = n - lines + j - 1;
							if (0 <= xn && xn < m && 0 <= yn && yn < n) {
									board[xn][yn] += 1;
							}
						}
					}
				}
			}
			scanf("\n");
		}

		if (x != 1)
			printf("\n");

		printf("Field #%d:\n", x);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (bombCoords[j][i])
					printf("*");
				else
					printf("%d", board[j][i]);
			}
			printf("\n");
		}

		x++;

	}



}
