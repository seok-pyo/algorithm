#include <iostream>
#include <vector>
using namespace std;
vector<int> map[10];
int Q[10];
int ch[10];
int front = -1, back = -1;

int main() {
	int a, b, i, x;
	for (i = 0; i < 6; i++) {
		cin >> a >> b;
		map[a].push_back(b); // 양방향 그래프
		map[b].push_back(a);
	}
	Q[++back] = 1;
	ch[1] = 1;
	while (front < back) {
		x = Q[++front];
		cout << x << " ";
		for (i = 0; i < map[x].size(); i++) {
			if (ch[map[x][i]] == 0) {
				ch[map[x][i]] = 1;
				Q[++back] = map[x][i];
			}
		}
	}
	return 0;
}