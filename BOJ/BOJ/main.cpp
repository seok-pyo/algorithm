#include <iostream>
using namespace std;
long long d[91][2];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			d[i][1] = 1;
		}
		if (i > 1) {
			d[i][1] = d[i - 1][0];
			d[i][0] = d[i - 1][1] + d[i-1][0];
		}
	}

	cout << d[n][0] + d[n][1] << '\n';
	return 0;
}
