#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); // 동기화 해제
	ifstream cin;
	cin.open("input.txt");
	map<string, int> ch;
	map<string, int>::iterator it; // map은 반복자가 있어야 접근 가능
	string a;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		ch[a]++;
	}

	int max = 0;
	string res;
	for (it = ch.begin(); it != ch.end(); it++) {
		// cout << it->first << " " << it->second << "\n";
		if (it->second > max) {
			max = it->second;
			res = it->first;
		}
	}
	cout << res << " : " << max << "\n";
	return 0;
}
