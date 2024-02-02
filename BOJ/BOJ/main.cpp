#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, s, cnt = 0;
vector<int> arr(21);
int chk[21];
void DFS(int sum, int I) {
	/*if (I == n) {
		return;
	}

	sum += arr[I];
	if (sum == s) {
		cnt++;
	}

	DFS(sum, I + 1);

	sum -= arr[I];
	DFS(sum, I + 1);*/


	if (I == n) return;
	if (sum == s) {
		cnt++;
	}
		
	sum += arr[I]; // �� ������ ������ ���� ��ǥ ���ڿ� ���� ��쿡��
	// ī��Ʈ���� ���Ѵ�. ���� �ڵ�ó�� ������ ���ǹ� ���� �÷�����
	DFS(sum, I + 1);
	sum -= arr[I];
	DFS(sum, I + 1);
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	DFS(0, 0);
	cout << cnt << '\n';
	return 0;
}
