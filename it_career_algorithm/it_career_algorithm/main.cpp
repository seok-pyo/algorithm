#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int n, m, s, t;
	cin >> n >> m;
	vector<int> dy(m + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> s >> t;
		for (int j = m; j >= t; j--) {
			dy[j] = max(dy[j], dy[j-t] + s);
		}
	}
	cout << dy[m];
	return 0;
}

