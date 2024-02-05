#include <iostream>
#include <vector>
using namespace std;

int D[10001];
int card[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	//vector<int> card(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> card[i];
	}

	//vector<int> D(n+1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			D[i] = max(D[i-j] + card[j], D[i]);
		}
	}

	cout << D[n] << '\n';

	return 0;
}
