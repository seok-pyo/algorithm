#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> map[21];
queue<int> Q;
int ch[21], res[21];

int main() {
	int v, e, i, x, cnt=0, a, b, tmp;
	cin >> v >> e;
	for (i = 0; i < e; i++) {
		cin >> a >> b;
		map[a].push_back(b);
	}
	Q.push(1);
	res[1] = 0;
	while(!Q.empty()){
		tmp = Q.front();
		Q.pop();
		for (i = 0; i < map[tmp].size(); i++) {
			if (res[map[tmp][i]] == 0) { // 최단거리로 한번 기록이 되면, 그 거리가 최단 거리가 된다.
				// 중복으로 queue에 들어가는 것도 체크한다.
				Q.push(map[tmp][i]);
				res[map[tmp][i]] = res[tmp] + 1;
			}
		}
	}
	cout << endl;
	for (i = 2; i <= v; i++) {
		cout << i << ":" << res[i] << endl;
	}
	return 0;
}
