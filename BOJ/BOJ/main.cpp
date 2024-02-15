#include <iostream>
#include <algorithm>
using namespace std;

int d[31];

int main() {
	int n;
	cin >> n;
	d[0] = 1;
	d[2] = 3;
	d[4] = 5;

	for (int i = 4; i <= n; i+=2) {
		d[i] = d[i - 2] * 3;
		for (int j = 2; j <= i/ 2; j++) {
			d[i] += d[i - 2*j] * 2;
		}
	}

	cout << d[n] << '\n';
	
	return 0;
}

