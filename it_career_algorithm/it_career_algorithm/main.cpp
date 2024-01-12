#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[27][27];
int dis[27][27];
struct ms {
	int x;
	int y;
	int dis;

	bool operator<(const ms& other) const {
		if (dis != other.dis) {
			return dis < other.dis;
		}
		if (x != other.x) {
			return x < other.x;
		}
		return y < other.y;
	}
};

priority_queue<ms> pq;
pair<int, int> S;

int main() {
	int n, i, j, num;
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> num;
			map[i][j] = num;
			if (num != 0 && num != 9) {
				pq.push(ms(i, j, 0));
			}
			if (num == 9) {
				S.first = i;
				S.second = j;
			}
		}
	}

	return 0;
}
