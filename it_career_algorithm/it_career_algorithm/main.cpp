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
		if (dy[t] < dy[t] + s) {
			dy[t] = dy[t] + s;
		}
		for (int j = 1; j <= m; j++) {
			if (dy[j] != 0 && j + t <= m) 
				dy[j+t] = max(dy[j + t], dy[j] + s);
		}
	}
	cout << dy[m];
	return 0;
}

