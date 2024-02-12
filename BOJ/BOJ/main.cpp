#include <iostream>
#include <algorithm>
using namespace std;

int dy[10001][3];
int a[10001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		dy[i][0] = max(dy[i - 1][1], max(dy[i - 1][2], dy[i - 1][0]));
		// dy[i][1] = max(dy[i - 1][0] + a[i], dy[i - 1][1] + a[i]) 
		// 2잔 연속해서 마신 경우가 된다.
		dy[i][1] = dy[i - 1][0] + a[i];
		dy[i][2] = dy[i - 1][1] + a[i];
	}

	cout << max(dy[n][0], max(dy[n][1], dy[n][2]));
	return 0;
}

