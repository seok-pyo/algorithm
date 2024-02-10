#include <iostream>
#include <algorithm>
using namespace std;

long long d[1000001][4];

int main() {
	int n = 10;

	for (int i = 1; i <= n; i++) {
		if (i >= 1) {
			d[i][1] = d[i - 1][1] + d[i - 1][2] + d[i - 1][3];
			if (i == 1) d[1][1] = 1;
		}
		if (i >= 2) {
			d[i][2] = d[i - 2][1] + d[i - 2][2] + d[i - 2][3];
			if (i == 2) d[2][2] = 1;
		}
		if (i >= 3) {
			d[i][3] = d[i - 3][1] + d[i - 3][2] + d[i - 3][3];
			if (i == 3) d[3][3] = 1;
		}
	}

	cout << d[n][1] + d[n][2] + d[n][3] << '\n';
	return 0;
}
