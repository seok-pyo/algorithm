#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int n, v, m;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> v;
		arr.push_back(v);
	}
	cin >> m;
	vector<int> dy(m + 1, 0);
	for (int i = 0; i < n; i++) {
		v = arr[i];
		for (int j = v; j <= m; j++) {
			if (dy[j] == 0) {
				dy[j] = 1;
			}
			else {
				if (dy[j] <= dy[j - v] + 1) {
					dy[j] = dy[j - v] + 1;
				}
			}
		}
	}
	cout << dy[m];
	return 0;
}

