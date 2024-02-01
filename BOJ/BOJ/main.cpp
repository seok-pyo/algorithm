#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int chk[15];
void DFS(int L, vector<int> &ans, int S, vector<int> &ina) {
	if (L == 6) {
		sort(ans.begin(), ans.end());
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
	}
	else {
		for(int i = S; i<n; i++){
			if (chk[i] == 0) {
				chk[i] = 1;
				ans.push_back(ina[i]);
				DFS(L + 1, ans, i+1, ina);
				chk[i] = 0;
				ans.pop_back();
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		cin >> n;
		vector<int> ans;
		vector<int> ina;
		if (n == 0) {
			break;
		}
		int num;
		for (int i = 0; i < n; i++) {
			cin >> num;
			ina.push_back(num);
		}
		DFS(0, ans, 0, ina);
		cout << '\n';
	}
	return 0;
}
