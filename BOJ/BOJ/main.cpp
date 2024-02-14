#include <iostream>
#include <algorithm>
using namespace std;

int d[100001];
int d2[100001];
int a[100001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		d[i] = a[i];
 		if (i == 1) continue;
		if (d[i] < d[i - 1] + a[i]) {
			d[i] = d[i - 1] + a[i];
		}
	}
	
	for (int i = n; i >= 1; i--) {
		d2[i] = a[i];
		if (i == n) continue;
		if (d2[i] < d2[i + 1] + a[i]) {
			d2[i] = d2[i + 1] + a[i];
		}
	}

	int ans = d[0];

	for (int i = 1; i <= n; i++) {
		if (ans < d[i]) {
			ans = d[i];
		}
	}

	for (int i = 2; i < n; i++) {
		if (ans < d[i - 1] + d2[i + 1]) {
			ans = d[i - 1] + d2[i + 1];
		}
	}

	cout << ans << '\n';

	return 0;
}

