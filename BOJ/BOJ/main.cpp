#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> dy(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dy[0] = arr[0];
	for (int i = 1; i < n; i++) {
		int tmp = dy[i - 1] + arr[i];
		if (arr[i] > tmp) dy[i] = arr[i];
		else dy[i] = tmp;
	}

	int max = *max_element(dy.begin(), dy.end());
	cout << max << '\n';
	return 0;
}
