#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

bool legal (int k, int q, int qn) {
	// next pos on vertical line
	if ((q - qn) % 8 == 0) {
		// king on same vertical line
		if ((q - k) % 8 == 0) {
			if (k < q)
				return (k < qn);
			else
				return (k > qn);
		}
		return true;
	}

	// same horizontal line
	if (q / 8 == qn / 8) {
		// king on same horizontal line
		if (k / 8 == q / 8) {
			if (k < q)
				return (k < qn);
			else
				return (k > qn);
		}
		return true;
	}
	return false;
}

bool allowed (int k, int q, int qn) {
	int ab = abs(k - qn);
	if (ab == 8) {
		return false;
	}
	if (ab == 1) {
		return (k / 8 != qn / 8);
	}
	return true;

}

bool free(int k, int q) {

	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (i == 0 || j == 0) {
				if (i != 0 || j != 0) {
					int xk = k % 8 + i; int yk = k / 8 + j;
					if (0 <= xk && xk < 8 && 0 <= yk && yk < 8) {
						if (!legal (k, q, k + i + 8 * j)) {
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

int main () {
	int a, b, c;
	int x = 10;
	while (scanf("%d %d %d", &a, &b, &c) != EOF) {

		// same
		if (a == b) {
			printf("Illegal state\n");
			continue;
		}

		if (!legal(a, b, c) || a == c || b == c) {
			printf("Illegal move\n");
			continue;
		}

		if (!allowed(a, b, c)) {
			printf("Move not allowed\n");
			continue;
		}

		if (!free(a, c)) {
			printf("Stop\n");
		} else {
			printf("Continue\n");
		}

	}

}
