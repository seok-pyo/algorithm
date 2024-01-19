#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a = 0;
	int n;
	while (cin >> n) {
		for (int i = 1;; i++) {
			a = (10*(a) + 1) % n;
			if (a == 0) {
				cout << i << '\n';
				break;
			}
		}
	}
	return 0;	
}
