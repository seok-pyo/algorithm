#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

int arr[1001];
int dy[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fstream cin;
	cin.open("input.txt");
	
	int n, i, j, num, max, res = 0, tmp = 0;

	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> num;
		arr[i] = num;
	}
		
	dy[1] = 1;

	for (i = 2; i <= n; i++) {
		max = 0;
		for (j = i-1; j >= 1; j--) {
			if (arr[i] > arr[j]) {
				tmp = dy[j];
			}
			if (max < tmp) max = tmp;
		}
		dy[i] = max + 1;

	}

	for (i = 1; i <= n; i++) {
		res = res < dy[i] ? dy[i] : res;
	}

	cout << res;	
	return 0;
}
