#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
const int MOD = 1000000000;
long long cnt = 0;
void DFS(int L, int sum) {
	if (L > k || sum > n) return;
	if (L == k && sum == n) {
		cnt = (cnt + 1) % MOD;
		//cnt++;
		return;
	}
	else {
		for (int i = 0; i <= n; i++) {
			DFS(L + 1, sum + i);
			//DFS(L + 1, sum, idx);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	DFS(0, 0);

	cout << cnt << '\n';

	return 0;
}
