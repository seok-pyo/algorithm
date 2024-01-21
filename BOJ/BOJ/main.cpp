#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int h, sum =0;
	vector<int> arr(9);
	int r1 = 0, r2 = 0;

	for (int i = 0; i < 9; i++) {
		cin >> h;
		arr[i] = h;
		sum += h;
	}
	bool flag = true;

	for (int i = 0; i < 8; i++) {
		if (flag) {
			for (int j = i + 1; j <= 8; j++) {
				if (sum - (arr[i] + arr[j]) == 100) {
					arr[i] = 0;
					arr[j] = 0;
					flag = false;
					break;
				}
			}
		}
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i <= 8; i++) {
		if (arr[i] != 0) {
			cout << arr[i] << "\n";
		}
	}

	return 0;	
}
