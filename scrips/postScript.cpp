#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#include <cstring>

using namespace std;

char grid[60][60];

// Navigate bigChars with [column + row * 5]

const string bigChars[] = 	{".***.*...*******...**...*", // A
                               "****.*...*****.*...*****.", // B
                               ".*****...**....*.....****", // C
                               "****.*...**...**...*****.", // D
                               "******....***..*....*****", // E
                               "******....***..*....*....", // F
                               ".*****....*..***...*.***.", // G
                               "*...**...*******...**...*", // H
                               "*****..*....*....*..*****", // I
                               "..***...*....*.*..*..**..", // J
                               "*...**..*.***..*..*.*...*", // K
                               "*....*....*....*....*****", // L
                               "*...***.***.*.**...**...*", // M
                               "*...***..**.*.**..***...*", // N
                               ".***.*...**...**...*.***.", // O
                               "****.*...*****.*....*....", // P
                               ".***.*...**...**..**.****", // Q
                               "****.*...*****.*..*.*...*", // R
                               ".*****.....***.....*****.", // S
                               "******.*.*..*....*...***.", // T
                               "*...**...**...**...*.***.", // U
                               "*...**...*.*.*..*.*...*..", // V
                               "*...**...**.*.***.***...*", // W
                               "*...*.*.*...*...*.*.*...*", // X
                               "*...*.*.*...*....*....*..", // Y
                               "*****...*...*...*...*****", // Z
														 	 "........................."}; // "."

void outPage() {
	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < 60; j++)
			printf("%c", grid[j][i]);
		printf("\n");
	}
	// out lines
	cout << endl;
	for (int i = 0; i < 60; i++) {
		cout << "-";
	} cout << endl << endl;

}

void setPage() {
	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < 60; j++) {
				grid[j][i] = '.';
		}
	}
}

char str[61];

void writeChar(int i, int C, int R, char fontSize) {

	// Check out of bounds.
	if (i >= strlen(str)) {
		return;
	}

  // Small font.
	if (fontSize == '1') {
		if (0 <= C && C < 60 && 0 <= R && R < 60) {
			if (str[i] != ' ')
				grid[C][R] = str[i];
		}
		return;
	}

  // Large font.
	int ci = (str[i] != ' ') ? ((int) str[i] - 'A') : 26;
	char to_write; int x, y;

	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 5; col++){
			x = col + C; y = row + R;
			if (0 <= x && x < 60 && 0 <= y && y < 60) {
				to_write = bigChars[ci][col + row * 5];
				if (to_write != '.')
					grid[x][y] = to_write;
			}
		}
	}
}

int main () {
	setPage();
	string line;
	while (getline(cin, line)) {

		if (line == ".EOP") {
			outPage();
			setPage();
      continue;
		}

    // I/O format is dependent on 2nd character 'justify'.
		char justify = line[1]; char font; int R, C;
		if (justify == 'P')
			sscanf(line.c_str(), ".P C%c %d %d |%[^|]s|", &font, &R, &C, str);
		else
			sscanf(line.c_str(), ".%c C%c %d |%[^|]s|", &justify, &font, &R, str);

		int charSize = (font == '1') ? 1 : 6;

    int totalLength = (int) strlen(str) * charSize;
		int width = min (totalLength, 60); // width of printed string
		int charsPrinted = width / charSize; // number of characters that will be printed

		// str[i..j) is to-print.
		int i, j;

		if (justify == 'P') {
			i = 0;
      C -= 1; // Coords start at 0, not 1 as given in the input.
		}
		if (justify == 'L') { // Simple case.
			i = 0;
			C = 0;
		}
		if (justify == 'R') {
			i = strlen(str) - charsPrinted;
			C = 60 - width;
		}

    // Hideous case. Needs generalising.
		if (justify == 'C') {
      if (totalLength <= 60 || charSize == 1) {
        i = (strlen(str) / 2) - charsPrinted / 2;
        C = (60 - width + 1) / 2; // +1 to round up (centered around col 31.) I think..?
      }
      else {
        int X = totalLength / 2 - 30;
        C = -(X % 6) ;
        i = (X / 6);
      }

		}

    // This is poor.
		j = i + charsPrinted + 1;

		while (i < j) {
			writeChar(i, C, R - 1, font); // -1 as coord system starts at 1... Of course.
			C += charSize;
			i++;
		}




	}


}
