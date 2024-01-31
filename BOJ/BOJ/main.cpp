#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n;
int ans = -2147000000;
int chk[9];

int sum(vector<int>& arr) {
	int sum = 0;
	for (int i = 0; i < arr.size() - 1; i++) {
			int tmp = abs(arr[i] - arr[i + 1]);
			sum += tmp;
	}
	return sum;
}

void DFS(int L, vector<int>& a, vector<int>& arr) {
	if (L == n) {
		ans = max(ans, sum(a));
	}
	else {
		for (int i = 0; i < n; i++) {
			if (chk[i] == 0) {
				chk[i] = 1;
				a.push_back(arr[i]);
				DFS(L + 1, a, arr);
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
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> as;
	
	DFS(0, as, arr);
	cout << ans << '\n';
	return 0;
}
