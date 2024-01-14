#include <iostream>
#include <vector>
#include <deque>
#include <fstream>
using namespace std;
deque<int> arr;
vector<int> res;
vector<int> qs;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, b, idx, i, tmp;

	cin >> n;
	qs.resize(n + 1);
	for (i = 1; i <= n; i++) {
		cin >> b;
		qs[i] = b;
		arr.push_back(i);
	}

	idx = arr.front();
	arr.pop_front();
	res.push_back(idx);

	while (!arr.empty()) {
		if (qs[idx] > 0) {
			for (i = 0; i < qs[idx] - 1; i++) {
				tmp = arr.front();
				arr.pop_front();
				arr.push_back(tmp);
			}
			idx = arr.front();
			arr.pop_front();
		}
		else {
			for (i = 0; i < -qs[idx]; i++) {
				tmp = arr.back();
				arr.pop_back();
				arr.push_front(tmp);
			}
			idx = arr.front();
			arr.pop_front();
		}
		res.push_back(idx);
	}

	for (i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

	return 0;	
}
