#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); // ����ȭ ����
	ifstream cin;
	cin.open("input.txt");
	map<char, int> ch;
	map<char, int>::iterator it; // map�� �ݺ��ڰ� �־�� ���� ����
	char a[100];
	cin >> a;
	for (int i = 0; a[i] != '\0'; i++) {
		ch[a[i]]++; // map ���δ� �����Ʈ���� �����Ǿ� �ִ�.
	}

	for (it = ch.begin(); it != ch.end(); it++) {
		cout << it->first << " " << it->second << "\n";
	}

	return 0;
}
