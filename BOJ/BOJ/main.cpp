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
	int n;
	cin >> n;
	int a = 0;
	int cnt = 0;
	while (1) {
		a = (10*(a) % n + 1) % n;
		cnt++;
		if (a == 0) {
			break;
		}
	}
	cout << cnt;
	return 0;	
}
