#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

int main () {

	vector<int> scene;

	// such an awkward I/O... :(

	while (1) {

		while (1) {
			int i; scanf("%d", &i);
			if (i == 0)
				break;
			scene.push_back(i);
		}

		// proccess scene *HERE*

		int size = scene.size();

		int states[size + 1];
		int cycle_times[size][3];
		int timeOnState[size];
		int t = 0; states[size] = 0;

		for (int i = 0; i < size; i++) {
			states[i] = 0;
			timeOnState[i] = 0;
			cycle_times[i][0] = scene[i] - 5; // green time
			cycle_times[i][1] = 5;						// orange time
			cycle_times[i][2] = scene[i];		 // red time
		}

		bool changed = false;
		bool zeros;
		while (1) {
			int m = INT_MAX;
			for (int i = 0; i < size; i++) // more efficient
				m = min(cycle_times[i][states[i]] - timeOnState[i], m);

			zeros = true; t += m;
			for (int i = 0; i < size; i++) {
				timeOnState[i] += m;
				if (timeOnState[i] >= cycle_times[i][states[i]]) {
					changed = true;
					states[i] += 1;
					states[i] %= 3;
					timeOnState[i] = 0;
				}
				zeros = changed && zeros && (states[i] == 0);
			}

			if (zeros || t > 18000)
				break;
		}

		if (zeros) {
			// time to HH:MM:SS conversion.
			 int hr = t / 3600;
			printf("0%d:%02d:%02d\n", t / 3600, (t - hr * 3600) / 60, t % 60);
		} else cout << "Signals fail to synchronise in 5 hours" << endl;

		// till *HERE*

		int x, y; scanf("%d %d", &x, &y);
		if (x == 0 && y == 0)
			break;
		else {
			scene.clear();
			scene.push_back(x);
			scene.push_back(y);
		}

	}


}
