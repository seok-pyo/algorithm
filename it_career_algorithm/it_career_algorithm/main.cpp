#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

int dy[50];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin;
	cin.open("input.txt");
	cin >> n;

	dy[1] = 1;
	dy[2] = 2;

	for (int i = 3; i <= n; i++) {
		dy[i] = dy[i - 2] + dy[i - 1];
	}
	cout << dy[n];

	return 0;
}
