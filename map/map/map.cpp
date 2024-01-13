#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); // 동기화 해제
	ifstream cin;
	cin.open("input.txt");
	map<char, int> ch;
	map<char, int>::iterator it; // map은 반복자가 있어야 접근 가능
	char a[100];
	cin >> a;
	for (int i = 0; a[i] != '\0'; i++) {
		ch[a[i]]++; // map 내부는 레드블랙트리로 구성되어 있다.
	}

	for (it = ch.begin(); it != ch.end(); it++) {
		cout << it->first << " " << it->second << "\n";
	}

	return 0;
}
