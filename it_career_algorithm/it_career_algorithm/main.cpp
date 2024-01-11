#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[9][9];
int dis[9][9];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Loc {
	int x;
	int y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}
};
queue<Loc> Q;

int main() {
	int n, m, i, j, k, num, max = -2147000000 ;
	cin >> m >> n;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> num;
			map[i][j] = num;
			
			if (num == 1) {
				Q.push(Loc(i, j));
			}
		}
	}

	while (!Q.empty()) {
		Loc tmp = Q.front();
		Q.pop();
		for (k = 0; k < 4; k++) {
			int xx = tmp.x + dx[k];
			int yy = tmp.y + dy[k];
			if (map[xx][yy] == 0 && xx <= n && xx >= 1 && yy <= m && yy >= 1) {
				map[xx][yy] = 1;
				dis[xx][yy] = dis[tmp.x][tmp.y] + 1;
				Q.push(Loc(xx, yy));
			}
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (dis[i][j] > max && dis[i][j] != 0) {
				max = dis[i][j];
			}
			if (map[i][j] == 0) {
				cout << "-1" << endl;
				return 0;
			}
		}
	}

	cout << max;
	return 0;
}
