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
#include <cmath>

using namespace std;

/* Magic square palindromes. */

bool AZ(char c) {
    return ('a' <= c && c <= 'z');
}

int main () {

	/* CLion doesn't handle standard input yet..? */
    //freopen("/home/olliee/CLionProjects/myProject/out.txt", "a+", stdout);
    //freopen("/home/olliee/CLionProjects/myProject/in.txt", "r", stdin);

    int TC; scanf("%d\n", &TC); int cas = 0;
    while (TC--) {
        cas++;
        string line; getline(cin, line);
        string sentence;

        /* Remove all non-alphabetical characters from the string; store it in `sentence` */
        for (int i = 0; i < line.size(); i++) {
            if (AZ(line[i]))
                sentence += line[i];
        }

        /* Magic square palindromes must have a square-number length */
        double root = sqrt (sentence.size());
        if (root != floor(root)) {
            printf("Case #%d:\n", cas);
            cout << "No magic :(" << endl;
            continue;
        }

        /* Load sentence into board */
        int K; K = (int) root;
        char board[K][K];
        for (int r = 0; r < K; r++) {
            for (int c = 0; c < K; c++) {
                board[c][r] = sentence[c + K * r];
            }
        }

        /* Magic, mathsy index stuff >:) */
        bool magic = true; int x, y;
        for (int r = 0; r < K; r++) {
            for (int c = 0; c < K; c++) {
                x = c; y = r;
                magic &= (board[x][y] == sentence[x + K * y]);
                x = K - c - 1; y = K - r - 1;
                magic &= (board[x][y] == sentence[x + K * y]);
                x = r; y = c;
                magic &= (board[x][y] == sentence[x + K * y]);
                x = K - r - 1; y = K - c - 1;
                magic &= (board[x][y] == sentence[x + K * y]);
            }
        }

        if (magic) {
            printf("Case #%d:\n", cas);
            cout << K << endl;
        }
        else {
            printf("Case #%d:\n", cas);
            cout << "No magic :(" << endl;
        }

    }


	return 0;
}

