#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000;
int prime[MAX];
int len = 0;
bool chk[MAX + 1];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 2; i <= MAX; i++) {
		if (chk[i] == false) {
			prime[len++] = i;
			for (int j = i + i; j <= MAX; j += i) {
				chk[j] = true;
			}
		}
	}

	while (true) {
		int num;
		cin >> num;
		if (num == 0) {
			break;
		}
		for (int i = 1; i < len; i++) {
			if (chk[num - prime[i]] == false) {
				cout << num <<  " = " <<  prime[i] << " + " << num - prime[i] << "\n";
				break;
			}
		}
	}

	return 0;	
}
