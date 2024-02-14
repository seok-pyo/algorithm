#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int prev = 1;
	int current = 1;

	for (int i = 2; i <= n; i++) {
		int next = (prev * 2 + current);
		prev = current;
		current = next;
	}

	cout << current << '\n';
	return 0;
}

