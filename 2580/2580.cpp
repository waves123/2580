#include <iostream>
using namespace std;

int s[9][9];
bool c[9][9], c1[9][9], c2[9][9];

int square(int i, int j) {
	return (i / 3) * 3 + (j / 3);
}

void sdo(int z) {
	if (z == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << s[i][j] << ' ';
			}
			cout << endl;
		}
		exit(0);
	}

	if (s[z / 9][z % 9] != 0) {
		sdo(z + 1);
	}
	else {
		for (int j = 1; j <= 9; j++) {
			if (c[z / 9][j] == false && c1[z % 9][j] == false && c2[square(z / 9, z % 9)][j] == false) {
				c[z / 9][j] = true;
				c1[z % 9][j] = true;
				c2[square(z / 9, z % 9)][j] = true;
				s[z / 9][z % 9] = j;
				sdo(z + 1);
				s[z / 9][z % 9] = 0;
				c[z / 9][j] = false;
				c1[z % 9][j] = false;
				c2[square(z / 9, z % 9)][j] = false;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> s[i][j];
			if (s[i][j] != 0) {
				c[i][s[i][j]] = true;
				c1[j][s[i][j]] = true;
				c2[square(i, j)][s[i][j]] = true;
			}
		}
	}
	sdo(0);
}