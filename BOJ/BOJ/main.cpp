#include <iostream>
#include <string>
using namespace std;
int cnt = 0, num;
void DFS(int sum) {
	if (sum > num) return;
	if (sum == num) {
		cnt++;
	}
	else {
		for (int i = 1; i <= 3; i++) {
			DFS(sum + i);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		DFS(0);
		cout << cnt << '\n';
		cnt = 0;
	}
	return 0;
}
