#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n;
char a[20];
vector<string> ans;
bool check[10];
//bool ok(string num) {
//	for (int i = 0; i < n; i++) {
//		if (a[i] == '<') {
//			if (num[i] > num[i + 1]) return false;
//		}
//		else if (a[i] == '>') {
//			if (num[i] < num[i + 1]) return false;
//		}
//	}
//	return true;
//}
bool good(char x, char y, char op) {
	if (op == '<') {
		if (x > y) return false;
	}
	if (op == '>') {
		if (x < y) return false;
	}
	return true;
}
void DFS(int index, string num) {
	/*if (index == n + 1) {
		if (ok(num)) {
			ans.push_back(num);
		}
		return;
	}*/
	if (index == n + 1) {
		ans.push_back(num);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (check[i]) continue;
		if (index == 0 || good(num[index - 1], i + '0', a[index - 1])) {
			check[i] = true;
			DFS(index + 1, num + to_string(i));
			check[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	DFS(0, "");
	auto p = minmax_element(ans.begin(), ans.end());
	cout << *p.second << '\n';
	cout << *p.first << '\n';
	return 0;
}
