#include <iostream>
#include <string>
using namespace std;
int n, m;
int arr[9];
int ans[9];
void DFS(int L) {
	if (L == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (arr[i] == 0) {
				arr[i] = 1;
				ans[L] = i;
				DFS(L + 1);
				arr[i] = 0;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	DFS(0);

	return 0;
}
