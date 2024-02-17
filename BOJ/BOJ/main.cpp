#include <iostream>
#include <string>
using namespace std;
struct Deq {
	int data[10000];
	int begin, end;
	Deq() {
		begin = 0;
		end = 0;
	}

	void push_front(int x) {
		// int tmp = data[end-1]; tmp ºÒÇÊ¿ä
		// for (int i = begin; i < end; i++) {
		for (int i = end; i > begin; --i) {
			data[i] = data[i-1];
		}
		// data[++end] = tmp;
		data[begin] = x;

		end++;
	}

	void push_back(int x) {
		data[end++] = x;
	}

	int pop_front() {
		return data[begin++];
	}

	int pop_back() {
		return data[--end];
	}

	int size() {
		return end - begin;
	}

	bool empty() {
		return begin == end;
	}

	int front() {
		return data[begin];
	}

	int back() {
		return data[end-1];
	}
};

int main() {
	string cmd;
	int n;
	cin >> n;

	Deq d;

	while (n--) {
		cin >> cmd;
		if (cmd == "push_front") {
			int x;
			cin >> x;
			d.push_front(x);
		}
		else if (cmd == "push_back") {
			int x;
			cin >> x;
			d.push_back(x);
		}
		else if (cmd == "pop_front") {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.pop_front() << '\n';
			}
		}
		else if (cmd == "pop_back") {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.pop_back() << '\n';
			}
		}
		else if (cmd == "size") {
			cout << d.size() << '\n';
		}
		else if (cmd == "empty") {
			if (d.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
 			}
		}
		else if (cmd == "front") {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.front() << '\n';
			}
		}
		else if (cmd == "back") {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.back() << '\n';
			}
		}
	}
	return 0;
}

