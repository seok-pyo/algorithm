#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

int dy[50];
int DFS(int n) {
	if (dy[n] > 0) return dy[n]; // �޸������̼� ���� ����

	if (n == 1 || n == 2) return n; // ���������� �� �� �ִ� ���� �ٷ� �����Ѵ�.
	// ���̺��� �ڸ��� �������� 1�� ���� 2�� ���
	else return dy[n] = DFS(n - 2) + DFS(n - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	ifstream cin;
	cin.open("input.txt");
	int n;
	cin >> n;
	cout << DFS(n);
	return 0;
}
