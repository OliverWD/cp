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

		string line;
		getline(cin, line);
		sort(line.begin(), line.end());
		cout << line << endl;
		while (next_permutation(line.begin(), line.end()))
			cout << line << endl;

		cout << endl;

	}

}
