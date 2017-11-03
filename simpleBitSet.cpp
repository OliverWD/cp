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
#include <bitset>

using namespace std;

bitset<3000> bits;

bool isJolly(int n) {

    bool flag = true;

    int first; cin >> first;
    if (n == 1)
        return true;

    bits.reset();
    for (int i = 1; i < n; i++) {
        int current; cin >> current;
        int index = abs(first - current);
        first = current;
        if (index <= n - 1)
            bits.set(index);
        else
            flag = false;
    }

    return (bits.count() == n - 1) && flag;

}

int main () {

    /* CLion doesn't handle standard input yet..? */
    //freopen("/home/olliee/CLionProjects/c11/out.txt", "a+", stdout);
    //freopen("/home/olliee/CLionProjects/c11/in.txt", "r", stdin);

    int n;
    while (cin >> n) {
        if (isJolly(n)) {
            cout << "Jolly\n";
        }
        else {
            cout << "Not jolly\n";
        }

    }


}


