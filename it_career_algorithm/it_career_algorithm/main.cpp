#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[22][22];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

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
	int n, i, j, k, num, cnt = 0;
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> num;
			map[i][j] = num;
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (map[i][j] == 1) {
				/*Loc tmp = Loc(i, j);
				Q.push(tmp);*/ // Q.push(Loc(i, j) 로 바로 입력하면 된다.
				Q.push(Loc(i, j));
				map[i][j] = 0;
				while (!Q.empty()) {
					Loc x = Q.front();
					Q.pop();
					for (k = 0; k < 8; k++) {
						if (map[x.x + dx[k]][x.y + dy[k]] == 1) {
							Q.push(Loc(x.x + dx[k], x.y + dy[k]));
							map[x.x + dx[k]][x.y + dy[k]] = 0;
						}
					}
				}
				cnt++;
			}
		}
	}
	std::cout << cnt << endl;

	return 0;
}
