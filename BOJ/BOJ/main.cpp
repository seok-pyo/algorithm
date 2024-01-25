#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, share = 1, ans = 0;
	cin >> n;
	string str = to_string(n);
	int length = str.length();

	int re = length;
	if (re > 1) {
		while (--re) {
			share *= 10;
		}
		int moc = n / share;
		int rem = n % share;
		ans += (rem * length);
		ans += ((moc - 1) * length);
		n = n - rem;
		
		for (int i = n; i >= 1; i--) {
			string len = to_string(i);
			ans += len.length();
		}
	}
	else {
		ans = n;
	}

	cout << ans << '\n';

	return 0;
}
