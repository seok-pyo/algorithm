#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int d[1001];
int a[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
	}

	int maxE = *max_element(d, d + n + 1);

	cout << maxE << '\n';
	return 0;
}
