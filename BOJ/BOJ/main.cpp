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
		// x�� y���� 1�� ����, k�� 1�� �����ִ� ����� �� ����.
		// ������ �������� �� �����ϱ�
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
