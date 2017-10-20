#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

int main () {
	int round;
 	int x = 0;
	while (1) {
		x++;
		bool sol[26] = {false};
		bool ges[26] = {false};
		bool lose = false;
		bool win = false;

		scanf("%d\n", &round);
		if (round == -1)
			break;

		int dif = 0;
		string solution; getline(cin, solution);
		for (int i = 0; i < solution.size(); i++) {
			if (!sol[solution[i] - 'a'])
				dif += 1;
			sol[solution[i] - 'a'] = true;
		}

		int falseGuess = 0; int corrects = 0;
		string guess; getline(cin, guess);
		for (int i = 0; i < guess.size(); ++i) {
			// correct guess
			if (sol[guess[i] - 'a']) {
				// if haven't already guessed this
				if (!ges[guess[i] - 'a']) {
					corrects += 1;
        }
				if (corrects >= dif) {
						win = true;
						break;
				}
			} else {
				// incorrect guess
				if (!ges[guess[i] - 'a'])
					falseGuess += 1;
				if (falseGuess >= 7) {
					lose = true;
					break;
				}
			}
			ges[guess[i] - 'a'] = true;
		}

		printf("Round %d\n", x);

		if (!(win || lose)) {
			printf("You chickened out.\n");
		}
		if (win) {
			printf("You win.\n");
		}
		if (lose) {
			printf("You lose.\n");
		}

	}


}
