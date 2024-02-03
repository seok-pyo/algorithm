// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int> arr(1000001, 2147000000);
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	queue<int> Q;
	Q.push(1);
	arr[1] = 0;

	while (!Q.empty()) {
		int f = Q.front();
		Q.pop();
		
		if (arr[n] != 2147000000) break;

		if (f + 1 <= n && arr[f + 1] > arr[f] + 1) {
			arr[f + 1] = arr[f] + 1;
			Q.push(f + 1);
		}
		if (f * 2 <= n && arr[f * 2] > arr[f] + 1) {
			arr[f * 2] = arr[f] + 1;
			Q.push(f * 2);
		}
		if (f * 3 <= n && arr[f * 3] > arr[f] + 1) {
			arr[f * 3] = arr[f] + 1;
			Q.push(f * 3);
		}
	}
	cout << arr[n] << '\n';
	return 0;
}
