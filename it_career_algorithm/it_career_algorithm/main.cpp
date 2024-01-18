#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int n, m, a, b, score;
	cin >> n >> m;
	vector<vector<int> >graph(n + 1, vector<int>(n + 1, 0));
	vector<int> degree(n + 1);
	queue<int> Q;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a][b] = 1; // a에서 b로 이동함을 표시 1로 표시
		degree[b]++; // 진입차수를 1차원 배열에 기록
	}
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) Q.push(i);
	}
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		cout << now << " ";
		for (int i = 1; i <= n; i++) {
			if (graph[now][i] == 1) {
				degree[i]--; // 모든 선결작업이 완료된 작업이 진입한 다른 작업
				// 의 차수를 하나 뺀다.

				if (degree[i] == 0) Q.push(i); // 진입차수가 0이 되면 Q에 추가
				// 진입차수가 0이라는 말은 앞에 선결되어야 하는 작업이 더 이상
				// 없다는 의미!
			}
		}
	}
	return 0;
}
