#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a=1, b=1, c=1, cnt=1;
	int t1, t2, t3;
	cin >> t1 >> t2 >> t3;
	while (1) {
		if (t1 == a && t2 == b && t3 == c) {
			break;
		}
		a++;
		b++;
		c++;
		cnt++;
		if (a > 15) a = 1;
		if (b > 28) b = 1;
		if (c > 19) c = 1;
	}
	cout << cnt;
	return 0;	
}
