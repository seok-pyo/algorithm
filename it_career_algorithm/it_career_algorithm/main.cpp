#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

int dy[50];
int DFS(int n) {
	if (dy[n] > 0) return dy[n]; // 메모이제이션 가지 정리

	if (n == 1 || n == 2) return n; // 직관적으로 알 수 있는 경우는 바로 리턴한다.
	// 케이블을 자르는 마지막이 1인 경우와 2인 경우
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
