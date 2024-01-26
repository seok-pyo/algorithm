#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int l, c;
bool check(string& password) {
	int ja = 0;
	int mo = 0;
	for (char x : password) {
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
			mo++;
		}
		else {
			ja++;
		}
	}
	return ja >= 2 && mo >= 1;
}

void DFS(vector<char> &alpha, string password, int i) {
	if (password.length() == l) {
		if (check(password)) {
			cout << password << '\n';
		}
		return;
	}
	if(i == alpha.size()) return;
	DFS(alpha, password + alpha[i], i + 1);
	DFS(alpha, password, i + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> l >> c;
	vector<char> a(c);
	for (int i = 0; i < c; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	DFS(a, "", 0);

	return 0;
}
