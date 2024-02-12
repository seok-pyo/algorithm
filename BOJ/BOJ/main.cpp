#include <iostream>
#include <algorithm>
using namespace std;
int t[502][502];
int d[502][502];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> t[i][j];
		}
	}

	d[1][1] = t[1][1];

	for (int i = 2; i<= n; i++) {
		for (int j = 1; j <= i; j++) {
			for (int k = j-1; k <= j; k++) {
				if (d[i][j] <= d[i - 1][k] + t[i][j]) {
					d[i][j] = d[i - 1][k] + t[i][j];
				}
			}
		}
	}

	int ans = -2147000000;
	for (int i = 1; i <= n; i++) {
		if (ans < d[n][i]) ans = d[n][i];
	}

	cout << ans << '\n';

	return 0;
}

