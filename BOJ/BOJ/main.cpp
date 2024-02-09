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
		return 0; // �ڽ��� ���� ���� ��
	}

	if (day > n + 1) {
		return -inf; // �ڽ��� ���� ���� ��, ������ �Ѿ ���
	}
	if (d[day] != -1) {
		return d[day]; // ���̳��� ���α׷���-�޸������̼�
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
