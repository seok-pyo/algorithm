#include <iostream>
#include <algorithm>
using namespace std;

long long d[100000][4];
int mod = 9901;
int main() {
	int n;
	cin >> n;

	d[1][1] = 1;
	d[1][2] = 1;
	d[1][3] = 1;

	for (int i = 2; i <= n; i++) {
		d[i][1] = d[i - 1][2] + d[i - 1][3];
		d[i][2] = d[i - 1][1] + d[i - 1][3];
		d[i][3] = d[i - 1][1] + d[i - 1][2] + d[i-1][3];
		d[i][1] %= mod;
		d[i][2] %= mod;
		d[i][3] %= mod;
	}

	cout << (d[n][1] + d[n][2] + d[n][3])%mod << '\n';
	return 0;
}
