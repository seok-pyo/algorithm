#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, ans=-2147000000;
void DFS(int L, int sum, vector<pair<int, int>>& arr) {
	if (L > n) return;
	if (L == n) {
		if (sum > ans) ans = sum;
	}
	else {
		DFS(L + arr[L].first, sum + arr[L].second, arr);
		DFS(L+1, sum, arr); // point - L이 넘어갈 때 선택하지 않은 경우 다음 칸으로 넘어간다.
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	pair<int, int> S;
	vector<pair<int, int>> arr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> S.first >> S.second;
		arr.push_back(S);
	}
	DFS(0, 0, arr);
	cout << ans << '\n';
	return 0;
}
