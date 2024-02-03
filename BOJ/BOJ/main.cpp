// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
void subsets(int n, vector<int> &vt, int target) {
	int cnt = 0;
	for (int i = 1; i < (1 << n); ++i) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				sum += vt[j];
			}
		}
		if (sum == target) cnt++;
	}
	cout << cnt << '\n';
}
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;
	cin >> n >> t;
	vector<int> vt(n);
	for (int i = 0; i < n; i++) {
		cin >> vt[i];
	}
	subsets(n, vt, t);
	
	return 0;
}
