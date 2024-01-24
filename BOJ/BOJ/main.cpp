#include <iostream>
#include <vector>
using namespace std;
const int MAX = 40000;
int check(int m, int n, int x, int y) {
	vector<int> a1;
	vector<int> a2;
	for (int i = x; i <= MAX; i += m) {
		a1.push_back(i);
	}
	for (int j = y; j <= MAX; j += n) {
		a2.push_back(j);
	}
	int common = -1;
	int i = 0;
	int j = 0;
	while (i < a1.size() && j < a2.size()) {
		if (a1[i] < a2[j]) {
			i++;
		}
		else if (a1[i] > a2[j]) {
			j++;
		}
		else {
			common = a1[i];
			break;
		}
	}
	return common;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> res;
	int t, m, n, x, y;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> x >> y;
		res.push_back(check(m, n, x, y));
	}

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << '\n';
	}
	return 0;
}
