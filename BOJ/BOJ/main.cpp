#include <iostream>
#include <vector>
using namespace std;
int n;
// bool 자료형으로 수정
bool prime(int x) {
	// 범위로 조건문 수정
	if (x <= 1) return false;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int num, cnt = 0;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (prime(num)) cnt++;
	}

	cout << cnt;
	return 0;	
}
