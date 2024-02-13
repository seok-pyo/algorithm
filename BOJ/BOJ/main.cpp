#include <iostream>
#include <algorithm>
using namespace std;

int d[100001];
int a[100001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		int tmp = d[i - 1] + a[i];
		if (a[i] > tmp) d[i] = a[i];
		else d[i] = tmp;
	}

	int max = *max_element(d, d+n);
	cout << max << '\n';

	return 0;
}

