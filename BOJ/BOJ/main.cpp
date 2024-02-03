// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int on = 2147000000, en = 2147000000;
	int n;

	cin >> n;

	vector<int> oa;
	vector<int> ea;
	int num;

	for (int i = 0; i < n; i++) {
		cin >> num;

		if (num % 2 == 0) ea.push_back(num);
		else oa.push_back(num);
	}
	
	

	return 0;
}


