#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector<int> qs;
deque<int> arr;
int main() {
	int n, type, el, m, i, j;
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> type;
		qs.push_back(type);
	}

	for (i = 0; i < n; i++) {
		cin >> el;
		if (qs[i] == 0) {
			arr.push_front(el);
		}
	}

	cin >> m;

	for (i = 0; i < m; i++) {
		cin >> el;
		arr.push_back(el);
	}

	for (i = 0; i < m; i++) {
		cout << arr[i] << " ";
	}

	return 0;	
}


