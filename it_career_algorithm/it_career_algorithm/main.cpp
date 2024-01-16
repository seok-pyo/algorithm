#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
int arr[21][21], dy[21][21];
int main() {
	ios_base::sync_with_stdio(false);
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	dy[0][0] = arr[0][0];
	// 0번째 행, 열의 값을 >> 이전 값에 입력값을 더한 값으로 초기화
	for (int i = 1; i < n; i++) {
		dy[0][i] = dy[0][i - 1] + arr[0][i];
		dy[i][0] = dy[i - 1][0] + arr[i][0];
	}
	// 이동방향은 오른쪽, 아래쪽으로 이동하는 경우만 계산해서, 작은 값으로 dy테이블을 갱신한다.
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			dy[i][j] = min(dy[i - 1][j], dy[i][j - 1]) + arr[i][j];
		}
	}
	cout << dy[n - 1][n - 1];
	return 0;
}

