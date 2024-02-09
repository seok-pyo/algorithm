#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 100000000;
int t[20];
int p[20];
int d[20];
int n;
int dynamic(int day) {
	if (day == n + 1) {
		return 0; // 자신을 넣지 않을 때
	}

	if (day > n + 1) {
		return -inf; // 자신을 넣지 않을 때, 범위가 넘어간 경우
	}
	if (d[day] != -1) {
		return d[day]; // 다이나믹 프로그래밍-메모이제이션
	}
	int t1 = dynamic(day + 1); // x
	int t2 = p[day] + dynamic(day + t[day]); // o
	d[day] = max(t1, t2);
	return d[day];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
		d[i] = -1;
	}
	cout << dynamic(1) << '\n';
	return 0;
}
