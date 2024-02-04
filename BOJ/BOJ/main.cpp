#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long on = LLONG_MAX, en = LLONG_MAX;
	long long num;
	int n;

	cin >> n;

	vector<long long> arr;
	vector<long long> oa;
	vector<long long> ea;
	
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num % 2 == 0) ea.push_back(num);
		else oa.push_back(num);
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	sort(oa.begin(), oa.end());
	sort(ea.begin(), ea.end());

	long long t;
	if (ea.size() != 0) {
		for (int i = 0; i < ea.size()-1; i++) {
			t = ea[i+1] - ea[i];
			if (t < 0) t = -t;
			if (t < en) en = t;
		}
	}

	if (oa.size() != 0) {
		for (int i = 0; i < oa.size() - 1; i++) {
			t = oa[i+1] - oa[i];
			if (t < 0) t = -t;
			if (t < en) en = t;
		}
	}

	for (int i = 0; i < arr.size() - 1; i++) {
		if (arr[i] % 2 == 0 && arr[i + 1] % 2 != 0) {
			t = arr[i + 1] - arr[i];
			if (t < 0) t = -t;
			if (t < on) on = t;
		}
		else if (arr[i] % 2 != 0 && arr[i + 1] % 2 == 0) {
			t = arr[i + 1] - arr[i];
			if (t < 0) t = -t;
			if (t < on) on = t;
		}
	}
	
	if (en == LLONG_MAX) en = -1;
	if (on == LLONG_MAX) on = -1;
	::cout << en << ' ' << on;

	return 0;
}
