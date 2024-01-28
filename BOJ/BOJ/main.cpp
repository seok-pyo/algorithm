#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int s[20][20];
int n;
int DFS(int index, vector<int>& first, vector<int>& second) {
	if (index == n) {
		/*if (first.size() != n / 2) return -1;
		if (second.size() != n / 2) return -1;*/
		if (first.size() == n || first.size() == 0) return -1;
		if (second.size() == n || second.size() == 0) return -1;
		int t1 = 0; 
		int t2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if (i < first.size() && j < first.size()) {
					t1 += s[first[i]][first[j]];
				}
				if (i < second.size() && j < second.size()) {
					t2 += s[second[i]][second[j]];
				}
			}
		}
		int diff = t1 - t2;
		if (diff < 0) diff = -diff;
		return diff;
	}
	if (first.size() == n) return -1;
	if (second.size() == n) return -1;
	int ans = -1;
	first.push_back(index);
	int t1 = DFS(index + 1, first, second);
	if (ans == -1 || (t1 != -1 && ans > t1)) {
		ans = t1;
	}
	first.pop_back();
	second.push_back(index);
	int t2 = DFS(index + 1, first, second);
	if (ans == -1 || (t2 != -1 && ans > t2)) {
		ans = t2;
	}
	second.pop_back();
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	vector<int> first, second;
	cout << DFS(0, first, second) << '\n';
	return 0;
}
