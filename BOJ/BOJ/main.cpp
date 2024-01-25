#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		// x와 y에서 1씩 빼고, k에 1을 더해주는 방식이 더 좋다.
		// 나머지 연산으로 다 적용하기
		/*x -= 1;
		y -= 1;*/
		bool ok = false;
		for (int k = x; k <= (n * m); k+=m) {
			if (k % n == y % n) {
				cout << k << '\n';
				ok = true;
				break;
			}

			if (k % n == y) {
				cout << k << '\n';
				ok = true;
				break;
			}
		}
		if (!ok) {
			cout << -1 << '\n';
		}
	}
	return 0;
}
