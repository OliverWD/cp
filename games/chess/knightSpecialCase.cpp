#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

int main() {
	int M, N, x;
	int M1, N2;
	while (scanf("%d %d", &M, &N), (M || N)) {

		M1 = M; N2 = N;

		x = 0;
		int tmp;
		if (M > N) {
			tmp = N;
			N = M;
			M = tmp;
		}

		if (M > 2) {
			x = ((M * N + 1) / 2);
		}

		if (M == 2) {
			x = 4 * (N / 4) + 2 * min (2, N % 4);
		}

		if (M == 1) {
			x = N;
		}

		printf("%d knights may be placed on a %d row %d column board.\n", x, M1, N2);
	}
}
