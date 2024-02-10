#include <iostream>
#include <algorithm>
using namespace std;

long long d[1000001][4];
long long mod = 1000000009;

int main() {

	long long n;
	cin >> n;
	while (n--) {
		long long num;
		cin >> num;
		for (int i = 1; i <= num; i++) {
			
			if (i >= 1 && d[i][1] == 0) {
				d[i][1] = (d[i - 1][1] + d[i - 1][2] + d[i - 1][3])%mod;
				if (i == 1) d[1][1] = 1LL;
			}
			if (i >= 2 && d[i][2]==0) {
				d[i][2] = (d[i - 2][1] + d[i - 2][2] + d[i - 2][3])%mod;
				if (i == 2) d[2][2] = 1LL;
			}
			if (i >= 3&&d[i][3]==0) {
				d[i][3] = (d[i - 3][1] + d[i - 3][2] + d[i - 3][3])%mod;
				if (i == 3) d[3][3] = 1LL;
			}
		}
		cout << (d[num][1] + d[num][2] + d[num][3])%mod << '\n';
	}

	return 0;
}
