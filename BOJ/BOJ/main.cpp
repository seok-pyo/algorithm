#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n+1);
	vector<int> dy(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int res = 0;
	dy[1] = 1;
	int lastIdx = 0;
	for (int i = 2; i <= n; i++) {
		int maxNum = 0;
		for (int j = i - 1; j >= 1; j--) {
			if (arr[j] < arr[i] && maxNum < dy[j]) {
				maxNum = dy[j];
			}
		}
		dy[i] = maxNum + 1;
		lastIdx = i;
		/*if (res < dy[i]) res = dy[i];*/
	}

	// cout << *max_element(dy.begin(), dy.end()) << '\n';
	
	/*auto maxElement = max_element(dy.begin(), dy.end());
	int maxVal = *maxElement;
	int maxIdx = distance(dy.begin(), maxElement);*/
	
	vector<int> result;
	if (lastIdx == 0) result.push_back(arr[1]);
	else result.push_back(arr[lastIdx]);

	for (int i = lastIdx; i >= 1; i--) {
		if (dy[i] == dy[lastIdx] - 1 && arr[lastIdx] > arr[i]) {
			result.push_back(arr[i]);
			lastIdx = i;
			break;
		}
	}
	
	for (int i = result.size()-1; i >= 0; i--) {
		cout << result[i] << ' ';
	}

	return 0;
}