#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

// don't need lexograhical ordering as it has it by default for strings

int main () {

	vector<pair <string, string> > vi;
	string word;
	while (1) {
		cin >> word;
		if (word == "#")
			break;

		string toSort = "";
		for (string::iterator it = word.begin(); it < word.end(); it++)
			toSort += tolower(*it);

		sort(toSort.begin(), toSort.end());
		vi.push_back(make_pair(toSort, word));
	}

	sort(vi.begin(), vi.end());


	if (vi.size() < 2)
		cout << vi[0].second << endl;
	else
	{

		vector<string> toOut;

		// rather messy special cases
		if (vi[0].first != vi[1].first)
			toOut.push_back(vi[0].second);
		if (vi[vi.size() - 1].first != vi[vi.size() - 2].first)
			toOut.push_back(vi[vi.size() - 1].second);

		for (int i = 1; i < vi.size() - 1; i++) {
			if (vi[i - 1].first != vi[i].first && vi[i].first != vi[i + 1].first)
				toOut.push_back(vi[i].second);
		}

		sort(toOut.begin(), toOut.end());

		for (int i = 0; i < toOut.size(); i++){
			cout << toOut[i] << endl;
		}

	}



}
