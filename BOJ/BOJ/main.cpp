#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n;
int ans = 2147000000;
int chk[11];
int b[11][11];

int sum(vector<int>& arr) {
	int sum = 0;
	int i = 0;
	bool flag = true;
	for (i = 0; i < arr.size() - 1; i++) {
		if (flag && b[arr[i]][arr[i + 1]] != 0) {
			sum += b[arr[i]][arr[i + 1]];
		}
		else {
			flag = false;
		}
	}
	if (b[arr[i]][arr[0]] == 0) {
		flag = false;
	}
	else {
		sum += b[arr.back()][arr.front()];
	}
	if (flag) {
		return sum;
	}
	else {
		return 0;
	}
}

void DFS(int L, vector<int>& a) {
	if (L == n) {
		if(sum(a)) ans = min(ans, sum(a));
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (chk[i] == 0) {
				chk[i] = 1;
				a.push_back(i);
				DFS(L + 1, a);
				chk[i] = 0;
				a.pop_back();
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> b[i][j];
		}
	}
	vector<int> as;
	
	DFS(0, as);
	cout << ans << '\n';
	return 0;
}


