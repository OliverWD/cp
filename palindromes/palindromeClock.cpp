#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

bool palindrome (int H1, int H2, int M1, int M2) {
	if (H1 == 0) {
		if (H2 == 0) {
			if (M1 == 0)
				return true;
			else
				return (M1 == M2);
		} else return (H2 == M2);
	} else return (M2 == H1 && H2 == M1);
}

int main () {

	int n; scanf("%d\n", &n);
	while (n--) {
		int H1, H2, M1, M2;
		while(scanf("%1d%1d:%1d%1d\n", &H1, &H2, &M1, &M2) != EOF) {
			while (1) {

				// clock incrementor
				M2 += 1;
				M1 += (M2 / 10);
				H2 += (M1 / 6);
				H1 += (H2 / 10);
				H2 %= 10; M1 %= 6; M2 %= 10;

				if (H1 == 2 && H2 == 4) {
					H1 = 0;
					H2 = 0;
				}

				if (palindrome(H1, H2, M1, M2)) {
					printf("%d%d:%d%d\n", H1, H2, M1, M2);
					break;
				}
			}
		}
	}
}
