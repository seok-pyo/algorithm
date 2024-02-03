// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int on = 2147000000, en = 2147000000;
	int n;

	cin >> n;

	vector<int> arr(n);
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	int odd, eve, tmp;
	for (int i = 0; i < n; i++) {
		int cur = arr[i];
		odd = i, eve = i;
		while (1) {
			eve++;
			if (eve >= n) break;
			if (arr[eve] % 2 == 0) break;
		}
		while (1) {
			odd++;
			if (odd >= n) break;
			if (arr[odd] % 2 != 0) break;
		}
		if (cur % 2 == 0) {
			if (odd < n) {
				tmp = cur - arr[odd];
				if (tmp < 0) tmp = -tmp;
				if (on > tmp) on = tmp;
			}

			if (eve < n) {
				tmp = cur- arr[eve];
				if (tmp < 0) tmp = -tmp;
				if (en > tmp) en = tmp;
			}
		}
		else {
			if (odd < n) {
				tmp = cur - arr[odd];
				if (tmp < 0) tmp = -tmp;
				if (en > tmp) en = tmp;
			}

			if (eve < n) {
				tmp = cur - arr[eve];
				if (tmp < 0) tmp = -tmp;
				if (on > tmp) on = tmp;
			}
		}
	}

	if (on == 2147000000) on = -1;
	if (en == 2147000000) en = -1;
	
	cout << en << ' ' << on;

	return 0;
}


