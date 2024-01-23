#include <iostream>
#include <vector>
using namespace std;
int block[19][3][2] = {
	{{0,1}, {0,2}, {0,3}},
	{{1,0}, {2,0}, {3,0}},
	{{1,0}, {1,1}, {1,2}},
	{{0,1}, {1,0}, {2,0}},
	{{0,1}, {0,2}, {1,2}},
	{{1,0}, {2,0}, {2,-1}},
	{{0,1}, {0,2}, {-1,2}},
	{{1,0}, {2,0}, {2, 1}},
	{{0,1}, {0,2}, {1,0}},
	{{0,1}, {1,1}, {2,1}},
	{{0,1}, {1,0}, {1,1}},
	{{0,1}, {-1,1}, {-1,2}},
	{{1,0}, {1,1}, {2,1}},
	{{0,1}, {1,1}, {1,2}},
	{{1,0}, {1,-1}, {2,-1}},
	{{0,1}, {0,2}, {-1,1}},
	{{0,1}, {0,2}, {1,1}},
	{{1,0}, {2,0}, {1,1}},
	{{1,0}, {2,0}, {1,-1}}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i= 0; i < n; i++) {
		for (int j= 0; j < m; j++) {
			for (int k = 0; k < 19; k++) {
				bool ok = true;
				int sum = a[i][j];
				for (int l = 0; l < 3; l++) {
					int x = i + block[k][l][0];
					int y = j + block[k][l][1];
					if (0 <= x && x < n && 0 <= y && y < m) {
						sum += a[x][y];
					}
					else {
						ok = false;
						break;
					}
				}
				if (ok && ans < sum) {
					ans = sum;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
