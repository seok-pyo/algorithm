#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int l, c;
bool chk[16];

//bool check(string &password) {

bool check(vector<char> &password) {
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

//void DFS(vector<char> &alpha, string password, int i) {
	/*if (password.length() == l) {
		if (check(password)) {
			cout << password << '\n';
		}
		return;
	}
	if(i == alpha.size()) return;
	DFS(alpha, password + alpha[i], i + 1);
	DFS(alpha, password, i + 1);*/

void DFS(vector<char> &alpha, int L, vector<char> &beta, int s) {
	if (L == l) {
		if (check(beta)) {
			for (int i = 0; i < beta.size(); i++) {
				cout << beta[i];
			}
			cout << '\n';
		}
		return;
	}
	else {
		if (beta.size() > l) return;
		for (int i = s; i < c; i++) {
			if (!chk[i]) {
				chk[i] = true;
				beta.push_back(alpha[i]);
				DFS(alpha, L + 1, beta, i+1);
				chk[i] = false;
				beta.pop_back();
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> l >> c;
	vector<char> a(c);
	vector<char> b;
	for (int i = 0; i < c; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	/*DFS(a, "", 0);*/
	DFS(a, 0, b, 0);

	return 0;
}
