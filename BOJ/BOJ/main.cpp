#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
const int MOD = 1000000000;
vector<vector<int>> dp;

int DFS(int L, int sum) {
	//if (L > k || sum > n) return;
	//if (L == k && sum == n) {
	//	cnt = (cnt + 1) % MOD;
	//	//cnt++;
	//	return;
	//}
	//else {
	//	for (int i = 0; i <= n; i++) {
	//		DFS(L + 1, sum + i);
	//		//DFS(L + 1, sum, idx);
	//	}
	//}
	if(L > k || sum > n) return 0;
	if (L == k && sum == n) return 1;

	if (dp[L][sum] != -1) {
		return dp[L][sum];
	}

	int result = 0;
	for (int i = 0; i <= n; i++) {
		result = (result + DFS(L + 1, sum + i) % MOD);
	}

	dp[L][sum] = result;
	return result;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	dp.assign(k + 1, vector<int>(n + 1, -1));

	int cnt = DFS(0, 0);

	cout << cnt << '\n';

	return 0;
}
