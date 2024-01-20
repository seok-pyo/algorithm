#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000;
bool chk[MAX + 1]; // bool �融�� false�� �ʱ�ȭ
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, i, j;
	cin >> n >> m;
	chk[0] = chk[1] = true; // �����佺�׳׽��� ü ���� 0,1�� ����� ����
	for (i = 2; i*i <= MAX; i++) {
		if (!chk[i]) {
			for (j = i+i; j<= MAX; j+=i) {
				chk[j] = true;
			}
		}
	}

	for (i = n; i <= m; i++) {
		if (!chk[i]) cout << i << "\n";
	}

	return 0;	
}
