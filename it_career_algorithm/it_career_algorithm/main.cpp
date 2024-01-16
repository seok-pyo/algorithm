#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int n, v, m;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		//cin >> v;
		//arr.push_back(v); // 000 + 1 2 5 �� �߰������� �Է¹޴´�.
		cin >> arr[i];
	}
	
	cin >> m;
	vector<int> dy(m + 1, 1000); // �ּҰ��� ���ϱ� ���ؼ� 1000���� �ʱ�ȭ
	dy[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= m; j++) {
			dy[j] = min(dy[j], dy[j - arr[i]] + 1);
		}
	}
	cout << dy[m];
	return 0;
}

