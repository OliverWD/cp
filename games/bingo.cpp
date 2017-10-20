#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

int board[5][5];
bool hit[5][5];

bool checkRow(int row) {
	for (int c = 0; c < 5; c++) {
		if (!hit[c][row])
			return false;
	}
	return true;
}

bool checkCol(int col) {
	for (int r = 0; r < 5; r++) {
		if (!hit[col][r])
			return false;
	}
	return true;
}

bool checkDiag1() {
	for (int i = 0; i < 5; i++) {
		if (!hit[i][i])
			return false;
	}
	return true;
}

bool checkDiag2() {
	for (int i = 0; i < 5; i++) {
		if (!hit[i][5 - i - 1])
			return false;
	}
	return true;
}


int main () {

	int n; scanf("%d\n", &n);
	while (n--) {

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (i == 2 && j == 2)
					hit[j][i] = true;
				else {
					hit[j][i] = false;
					scanf("%d", &board[j][i]);
				}

			}
		}

		bool done = false;
		for (int count = 0; count < 75; ++count) {
			int num; scanf("%d", &num);
			if (done)
				continue;

			for (int i = 0; i < 5; i++){
				for (int j = 0; j < 5; j++) {
					if (i == 2 && j == 2)
						continue;
					if (board[j][i] == num)
						hit[j][i] = true;
				}
			}

			for (int i = 0; i < 5; i++) {
				if(checkRow(i) || checkCol(i)) {
					done = true;
					break;
				}
			}

			if (!done && (checkDiag1() || checkDiag2()))
				done = true;

			if (done)
				printf("BINGO after %d numbers announced\n", count + 1);

		}

	}
}
