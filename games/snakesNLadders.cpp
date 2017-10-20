#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

int main () {

	int TC; scanf("%d\n", &TC);
	while (TC--) {
		long int a, c; int b;

		int map[101] = {0};

		scanf("%ld %d %ld\n", &a, &b, &c);
		while (b--) {
			int x, fx;
			scanf("%d %d", &x, &fx);
			map[x] = fx;
		}

		vector<int> playerPos;
		playerPos.reserve(a);
		for (long int i = 0; i < a; i++)
			playerPos.push_back(1);

		int playerTurn = 0; bool ended = false;
		while (c--) {
			int roll;
			scanf("%d\n", &roll);

			if (ended)
				continue;

			playerPos[playerTurn] += roll; // current player's position

			if (map[playerPos[playerTurn]] != 0) // hit a snake / ladder
				playerPos[playerTurn] = map[playerPos[playerTurn]];

			if (playerPos[playerTurn] >= 100) {
				playerPos[playerTurn] = 100;
				ended = true;
			}
			playerTurn += 1;
			playerTurn = playerTurn % a;

		}

		for (long int i = 0; i < a; i++) {
			printf("Position of player %ld is %d.\n", i+1, playerPos[i]);
		}

	}

}
