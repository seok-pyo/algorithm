#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> g[1001];
bool chk[1001];

void DFS(int node) {
	chk[node] = true;
	cout << node << " ";
	for (int i = 0; i < g[node].size(); i++) {
		int next = g[node][i];
		if (chk[next] == false) {
			DFS(next);
		}
	}
}

void BFS(int start) {
	queue<int> Q;
	memset(chk, false, sizeof(chk));
	chk[start] = true;
	Q.push(start);
	while (!Q.empty()) {
		int node = Q.front();
		Q.pop();
		cout << node << " ";
		for (int i = 0; i < g[node].size(); i++) {
			int next = g[node][i];
			if (chk[next] == false) {
				chk[next] = true;
				Q.push(next);
			}
		}
	}
}

int main() {
	int n, m, start;
	cin >> n >> m >> start;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end());
	}
	DFS(start);
	puts("");
	BFS(start);
	puts("");
	return 0;
}

