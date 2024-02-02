#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w, h;
	int ws = 0, hs = 0;
	cin >> h >> w;
	vector<string> paper(h);
	for (int i = 0; i < h; i++) {
		cin >> paper[i];
	}
	for (int i = 0; i<paper.size(); i++) {
		ws += stoi(paper[i]);
	}
	for (int i = 0; i < w; i++) {
		int t = 1;
		for (int j = paper.size()-1; j >= 0;j--) {
			hs = hs + ((paper[j][i] - '0') * t);
			t *= 10;
		}
	}

	if (hs < ws) cout << ws;
	else cout << hs;
	return 0;
}
