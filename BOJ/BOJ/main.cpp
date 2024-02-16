#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

queue <int> Q;
int main() {
	string command;
	int n;
	int integer;

	cin >> n;

	while (n--) {
		cin >> command;
		if (command == "push") {
			cin >> integer;
			Q.push(integer);
		}
		else if (command == "pop") {
			if (Q.size() == 0) {
				cout << -1 << '\n';
			}
			else {
				cout << Q.front() << '\n';
				Q.pop();
			}
		}
		else if (command == "size") {
			cout <<  Q.size() << '\n';
		}
		else if (command == "empty") {
			if (Q.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 <<'\n';
			}
		}
		else if (command == "front") {
			if (Q.empty()) {
				cout << -1 << '\n';
			} else {
				cout << Q.front() << '\n';
			}
		}
		else if (command == "back") {
			if (Q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout <<  Q.back() << '\n';
			}
		}
	}
	return 0;
}

