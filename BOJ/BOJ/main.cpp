#include <iostream>
#include <algorithm>
using namespace std;
int a[1001];
int d[1001];
int e[1001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		// int sum = 0;
		d[i] = a[i];
		for (int j = 1; j <= i; j++) {
			//if(a[j] < a[i]) {
			if(a[j] < a[i] && d[i] < d[j] + a[i]) {
				// sum += a[j];
				d[i] = d[j] + a[i];
			}
		}
		// d[i] = sum;
	}
	int MAX = -2147000000;
	for (int i = 1; i <= n; i++) {
		MAX = max(MAX, d[i]);
	}

	 cout << MAX << '\n';
	return 0;
}

