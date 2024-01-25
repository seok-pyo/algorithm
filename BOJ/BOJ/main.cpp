#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long ans = 0;
	for (int start = 1, len = 1; start <= n; start *= 10, len++) {
		int end = start * 10 - 1;
		if (end > n) {
			end = n;
		}
		ans += (long long)(end - start + 1) * len;
	}
	cout << ans << '\n';
	return 0;
}
