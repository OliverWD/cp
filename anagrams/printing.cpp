#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

int main () {

	while (1) {
		int pages; scanf("%d", &pages);
		if (pages == 0)
			break;
		int pages4;
		if (pages % 4 == 0)
			pages4 = pages;
		else
			pages4 = pages + (4 - pages % 4);

		int j = pages4; int i = 1;

		printf("Printing order for %d pages:\n", pages);
		if (pages == 2) {
			printf("Sheet 1, front: Blank, 1\n");
			printf("Sheet 1, back : 2, Blank\n");
			continue;
		}
		if (pages == 1) {
			printf("Sheet 1, front: Blank, 1\n");
			continue;
		}

		int x = 0;
		while (1) {
			// front
			x++;
			printf("Sheet %d, front: ", x);
			if (j > pages)
				printf("Blank, %d\n", i);
			else
				printf("%d, %d\n", j, i);

			i++; j--;
			if (i > j)
				break;

			//back
			printf("Sheet %d, back : ", x);
			if (j > pages)
				printf("%d, Blank\n", i);
			else
				printf("%d, %d\n", i, j);

			i++; j--;
			if (i > j)
				break;
		}

	}

}
