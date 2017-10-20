#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

bool ls(char x, char y){
	if (tolower(x) == tolower(y))
		return (x < y);
	else
		return (tolower(x) < tolower(y));
}

bool nextPerm(string & xs) {

	int i = xs.size() - 1;
	while (i > 0 && (xs[i-1] == xs[i] || ls(xs[i], xs[i - 1]))) {i -= 1;}

	// if (i == 0), then whole string is decreasing -- maximum achieved
	if (i == 0)
		return false;

	i -= 1;
	int rightMost = i;
	for (int j = i + 1; j < xs.size(); j++) {
		if (ls(xs[i], xs[j]))
			rightMost = j;
	}

	int t = xs[i];
	xs[i] = xs[rightMost];
	xs[rightMost] = t;

	reverse(xs.begin() + i + 1, xs.end());

	return true;

}

int main () {

	int TC; scanf("%d\n", &TC);
	while (TC--) {

		string ori; getline(cin, ori);
		sort(ori.begin(), ori.end(), ls);
		cout << ori << endl;
		while (nextPerm(ori))
			cout << ori << endl;
	}

}
