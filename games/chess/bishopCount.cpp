#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

int main () {


	int TC; scanf("%d", &TC);
	while (TC--) {

		int TC2, N;

		scanf("%d\n%d", &TC2, &N);

		int a, b, c, d;
		while (TC2--) {
			scanf("%d %d %d %d", &a, &b, &c, &d);

			if (a == c && b == d) {
				printf("0\n");
				continue;
			}

			int x = a - c; int y = b - d;
			if ((x + y) % 2 != 0) {
				printf("no move\n");
				continue;
			}

			if (abs(x) == abs(y)) {
				printf("1\n");
			} else {
				printf("2\n");
			}

		}

	}

}
