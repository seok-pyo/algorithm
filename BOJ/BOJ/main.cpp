#include <iostream>
#include <algorithm>
using namespace std;

int house[1001][4];
int d[1001][4];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> house[i][j];
		}
	}

	d[1][1] = house[1][1];
	d[1][2] = house[1][2];
	d[1][3] = house[1][3];

	for (int i = 2; i <= n; i++) {
		d[i][1] = min(d[i - 1][2] + house[i][1], d[i - 1][3] + house[i][1]);
		d[i][2] = min(d[i - 1][1] + house[i][2], d[i - 1][3] + house[i][2]);
		d[i][3] = min(d[i - 1][2] + house[i][3], d[i - 1][1] + house[i][3]);
	}

	int ans = min(d[n][1], d[n][2]);

	cout << min(ans, d[n][3]) << '\n';
	return 0;
}
