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

	vector<int> oa;
	vector<int> ea;
	int num;

	for (int i = 0; i < n; i++) {
		cin >> num;

		if (num % 2 == 0) ea.push_back(num);
		else oa.push_back(num);
	}
	
	sort(ea.begin(), ea.end());
	sort(oa.begin(), oa.end());

	
	if (oa.size() != 0 && ea.size() != 0) {
		/*for (int i = 0; i < oa.size(); i++) {
			for (int j = 0; j < ea.size(); j++) {
				int tmp = oa[i] - ea[j];
				if (tmp < 0) tmp = -tmp;
				if (tmp < on) on = tmp;
				if (j + 1 < ea.size()) {
					int tmp = ea[j + 1] - ea[j];
					if (tmp < 0) tmp = -tmp;
					if (tmp < en) en = tmp;
				}
			}
			if (i + 1 < oa.size()) {
				int tmp = oa[i + 1] - oa[i];
				if (tmp < 0) tmp = -tmp;
				if (tmp < en) en = tmp;
			}
		}*/

		
	if (ea.size() != 0 && oa.size() == 0) {
		for (int i = 0; i < ea.size(); i++) {
			if (i + 1 < ea.size()) {
				int tmp = ea[i + 1] - ea[i];
				if (tmp < 0) tmp = -tmp;
				if (tmp < en) en = tmp;
			}
		}
	}

	if (oa.size() != 0 && ea.size() == 0) {
		for (int i = 0; i < oa.size(); i++) {
			if (i + 1 < oa.size()) {
				int tmp = oa[i + 1] - oa[i];
				if (tmp < 0) tmp = -tmp;
				if (tmp < en) en = tmp;
			}
		}
	}
	if (en == 2147000000) en = -1;
	if (on == 2147000000) on = -1;
	cout << en << ' ' << on;

	return 0;
}


