#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int d[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*int n;
	cin >> n;
	int li = sqrt(n);
	vector<int> dy(li+1);
	for (int i = 1; i <= li; i++) {
		int res = n % (i * i);
		int tmp = n / (i * i);
		dy[i] = tmp;
		if (res == 0) continue;
		
		for (int j = i - 1; j >= 1; j--) {
			int moc = res / (j * j);
			res = res % (j * j);
			tmp += moc;
			if (res == 0) continue;
		}
		 f(dy[i] > tmp) 
		dy[i] = tmp;
	}
	
	int fa = *min_element(dy.begin()+1, dy.end());
	cout << fa << '\n';*/

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		d[i] = i;
		for (int j = 1; j * j <= i; j++) {
			if (d[i] > d[i - j * j] + 1) {
				d[i] = d[i - j * j] + 1;
			}
		}
	}
	cout << d[n] << '\n';
	return 0;
}
