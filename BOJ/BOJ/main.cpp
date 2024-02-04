#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int prev = 1;
	int current = 1;

	for (int i = 2; i <= n; i++) {
		int next = (prev + current) % 10007;
		prev = current;
		current = next;
	}
	
	cout << current <<'\n';

	return 0;
}
