#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

string s2 = "A   3  HIL JM O   2TUVWXY501SE Z  8 ";

char map(char c1) {
 	if (isdigit(c1))
		return s2[26 + (int) c1 - '0'];
	else
	 	return s2[c1 - 'A'];
}

int main () {

  string line; bool first = true;
	while (getline(cin, line)) {

		int s = line.size(); int i = 0;
		bool mirroredString = true; bool palindrome = true;
		while (i <= s / 2 && (mirroredString || palindrome)) {
			char c1 = line[i]; char c2 = line[s - i - 1];

			if (c1 != c2)
				palindrome = false;

			if (c1 != map(c2))
				mirroredString = false;

			i++;
		}

		cout << line << " -- ";

		if (!mirroredString && !palindrome)
			printf("is not a palindrome.\n");

		if (mirroredString && !palindrome)
			printf("is a mirrored string.\n");

		if (!mirroredString && palindrome)
			printf("is a regular palindrome.\n");

		if (mirroredString && palindrome)
			printf("is a mirrored palindrome.\n");

		cout << endl;
	}




}
