#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

int main() {

	int TC; scanf("%d\n", &TC);
	while (TC--) {
		char piece; int M, N, x;
		scanf("%c %d %d\n", &piece, &M, &N);

		if (piece == 'r') {
			x = min(M, N);
		}
		if (piece == 'k') {
			x = (M * N + 1) / 2;
		}
		if (piece == 'Q') {
			x = min(M, N);
			if (M % 2 == 0 && N & 2 == 0) {
				x += 1;
			}
		}
		if (piece == 'K') {
			x = ((M + 1) / 2) * ((N + 1) / 2);
		}
		printf("%d\n", x);
	}

}
