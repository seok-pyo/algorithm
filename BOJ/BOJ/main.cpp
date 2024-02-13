#include <iostream>
#include <algorithm>
using namespace std;

int a[1001];
int d[1001];
int d2[1001];

int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j <= i; j++) {
			if(a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
	}
	for (int i = n; i >= 1; i--) {
		d2[i] = 1;
		for (int k = i+1; k <= n; k++) {
			if (a[i] > a[k] && d2[i] < d2[k] + 1) {
				d2[i] = d2[k] + 1;
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (ans < d[i] + d2[i] - 1) {
			ans = d[i] + d2[i] - 1;
		}
	}

	cout << ans << '\n';
	return 0;
}

