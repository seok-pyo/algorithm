#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int n, i, j, a, b, k;
	cin >> n;
	vector<vector<int>> f(n + 1, vector<int>((n + 1), 100));
	vector<int> res(n + 1);
	for (i = 1; i <= n; i++) f[i][i] = 0;
	while (1) {
		cin >> a >> b;
		if (a == -1 || b == -1) break;
		f[a][b] = 1;
		f[b][a] = 1;
	}

	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if(f[i][j] > f[i][k] + f[k][j])
					f[i][j] = f[i][k] + f[k][j];
			}
		}
	}
	int score = 100;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			res[i] = max(res[i], f[i][j]);
		}
		score = min(score, res[i]);
	}
	int cnt = 0;
	for (i = 1; i < n; i++) {
		if (res[i] == score) cnt++;
	}
	cout << score << " " << cnt << endl;
	for (i = 1; i <= n; i++) {
		if (res[i] == score) {
			cout << i << " ";
		}
	}
	
	return 0;
}
