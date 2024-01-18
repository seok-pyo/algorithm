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
		graph[a][b] = 1; // a���� b�� �̵����� ǥ�� 1�� ǥ��
		degree[b]++; // ���������� 1���� �迭�� ���
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
				degree[i]--; // ��� �����۾��� �Ϸ�� �۾��� ������ �ٸ� �۾�
				// �� ������ �ϳ� ����.

				if (degree[i] == 0) Q.push(i); // ���������� 0�� �Ǹ� Q�� �߰�
				// ���������� 0�̶�� ���� �տ� ����Ǿ�� �ϴ� �۾��� �� �̻�
				// ���ٴ� �ǹ�!
			}
		}
	}
	return 0;
}
