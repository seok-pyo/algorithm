#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n, m;
int chk[10];
void DFS(int L, vector<int> &arr, int S) {
	if (L == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
	else {
		for(int i = S; i<n; i++){
			if (chk[i] == 0) {
				chk[i] = 1;
				arr.push_back(i+1);
				DFS(L + 1, arr, i);
				chk[i] = 0;
				arr.pop_back();
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<int> arr;
	DFS(0, arr, 0);
	return 0;
}


