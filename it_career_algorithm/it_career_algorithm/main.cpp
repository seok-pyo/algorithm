#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[9][9] = { 1 };
int res[9][9];

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
	int i, j, num;
	for (i = 1; i <= 7; i++) {
		for (j = 1; j <= 7; j++) {
			cin >> num;
			map[i][j] = num;
		}
	}
	Q.push(Loc(1, 1));
	map[1][1] = 1;
	while (!Q.empty()) {
		Loc tmp = Q.front();
		Q.pop();
		for (i = 0; i < 4; i++) {
			int xx = tmp.x + dx[i];
			int yy = tmp.y + dy[i];
			if (map[xx][yy] == 0 && xx >= 1 && xx <= 7 && yy >=1 && yy <= 7) {
				Q.push(Loc(xx, yy));
				map[xx][yy] = 1;
				res[xx][yy] = res[tmp.x][tmp.y] + 1;
			}
		}
	}
	
	if (res[7][7] !=0) {
		cout << res[7][7] << endl;
	}
	else {
		cout << "-1" << endl;
	}

	return 0;
}
