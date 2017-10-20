#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#include <cstring>

using namespace std;


int mapCI (char x) {
	 return (int) x - 'A';
}

int main () {

	/* CLion doesn't handle standard input yet..?
    // freopen("/home/olliee/CLionProjects/myProject/in.txt", "r", stdin);
    // freopen("/home/olliee/CLionProjects/myProject/out.txt", "a+", stdout); // */

    long int TC; scanf("%ld", &TC);

	while (TC--) {
		char X0[5], X1[5], result[4];
		bool could_be_light[12], could_be_heavy[12];

		for (int i = 0; i < 12; i++) {
			could_be_light[i] = true;
			could_be_heavy[i] = true;
		}

		for (int z = 0; z < 3; z++) {
            scanf("%s %s %s\n", X0, X1, result);

            /* See which values are being compared. */
            bool being_compared[12];
            for (int i = 0; i < 12; i++)
                being_compared[i] = false;
            for (int i = 0; i < strlen(X0); i++)
                being_compared[mapCI(X0[i])] = true;
            for (int i = 0; i < strlen(X1); i++)
                being_compared[mapCI(X1[i])] = true;

            /* If the compared values weigh the same, all coins being paired cannot be counterfeit. */
            if (result[0] == 'e') {
                for (int i = 0; i < 12; i++) {
                    could_be_light[i] &= !being_compared[i];
                    could_be_heavy[i] &= !being_compared[i];
                }
            } else {
                /* If the coins don't weigh the same, we know those not currently being compared are
                 * not counterfeit. */
                for (int i = 0; i < 12; i++) {
                    if (!being_compared[i]) {
                        could_be_light[i] = false;
                        could_be_heavy[i] = false;
                    }
                }

                /* If the right side is up, we know the right side cannot be heavy, and left side cannot be light. */
                if (result[0] == 'u') {
                    for (int i = 0; i < strlen(X0); i++)
                        could_be_light[mapCI(X0[i])] = false;
                    for (int i = 0; i < strlen(X1); i++)
                        could_be_heavy[mapCI(X1[i])] = false;

                }

                /* If the right side is down, we know the right side cannot be light, and the left side cannot
                 * be heavy. */
                if (result[0] == 'd') {
                    for (int i = 0; i < strlen(X0); i++)
                        could_be_heavy[mapCI(X0[i])] = false;
                    for (int i = 0; i < strlen(X1); i++)
                        could_be_light[mapCI(X1[i])] = false;
                }

            }

        }

        /* It is given in the problem statement that the inputs will give enough information to determine a unique
         * counterfeit coin, and whether it is light or heavy. Since all information was used above, the following
         * should print only once. */

        for (int i = 0; i < 12; i++) {
            if (could_be_light[i]) {
                cout << (char) (i + 'A') << " is the counterfeit coin and it is light." << endl;
                break;
            }
            if (could_be_heavy[i]) {
                cout << (char) (i + 'A') << " is the counterfeit coin and it is heavy." << endl;
                break;
            }
        }
	}

	return 0;
}
