#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k, sum = -2147000000, tmp = 0;
bool chk[12][12];
int b[12][12];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void DFS(int px, int py, int L) {
	if (L == k) {
		if (sum < tmp) sum = tmp;
		return;
	}
	else {
		for (int i = px; i < n; i++) {
			for (int j = (i == px ? py : 0); j < m; j++) {
				bool ok = true;
				if (chk[i][j] == false) {
					for (int k = 0; k < 4; k++) {
						int chex = i + dx[k];
						int chey = j + dy[k];
						if (chex >= 0 && chex < n && chey >= 0 && chey < m) {
							if (chk[chex][chey]) ok = false;
						}
					}
					if (ok) {
						chk[i][j] = true;
						tmp += b[i][j];
						DFS(i, j, L + 1);
						tmp -= b[i][j];
						chk[i][j] = false;
					}
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}

	DFS(0,0,0);
	cout << sum << '\n';
	return 0;
}
