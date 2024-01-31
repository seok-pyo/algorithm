#include <iostream>
#include <algorithm>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; 
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	int flag = 1;

	while (flag) {
		int l = n - 1;
		while (l > 0 && arr[l - 1] >= arr[l]) l--;


		for (int i = 0; i < n; i++) {
			cout << arr[i] << ' ';	
		}

		if (l <= 0) {
			break;
		}

		int p = n - 1;
		while (p > 0 && l > 0 && arr[p] <= arr[l - 1]) p--;
		swap(arr[l - 1], arr[p]);
		sort(arr.begin() + l, arr.end());
		cout << '\n';
	}
	cout << '\n';
	return 0;
}
