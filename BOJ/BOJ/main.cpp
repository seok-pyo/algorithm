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
	/*char c;
	string arr;*/
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		// cin >> c;
		// arr += c;
		cin >> arr[i];
	}
	int l = n - 1;
	while (l > 0 && arr[l - 1] >= arr[l]) l--;

	if (l <= 0) {
		cout << "-1" << '\n';
		return 0;
	}

	int p = n - 1;
	while (arr[p] <= arr[l - 1]) p--;
	swap(arr[l - 1], arr[p]);
	sort(arr.begin() + l, arr.end());
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';	
	}
	cout << '\n';
	return 0;
}
