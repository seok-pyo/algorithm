#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, s, cnt = 0;
vector<int> arr(21);
int chk[21];
void DFS(int sum, int I) {
	/*if (I == n) {
		return;
	}

	sum += arr[I];
	if (sum == s) {
		cnt++;
	}

	DFS(sum, I + 1);

	sum -= arr[I];
	DFS(sum, I + 1);*/


	if (I == n) return;
	if (sum == s) {
		cnt++;
	}
		
	sum += arr[I]; // 맨 마지막 원소의 합이 목표 숫자와 같은 경우에는
	// 카운트하지 못한다. 위에 코드처럼 순서를 조건문 위로 올려야함
	DFS(sum, I + 1);
	sum -= arr[I];
	DFS(sum, I + 1);
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	DFS(0, 0);
	cout << cnt << '\n';
	return 0;
}
