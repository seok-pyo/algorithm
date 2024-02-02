#include <iostream>
//#include <algorithm>
//#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
char b[111];
int main() {
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);*/
	int n = 20;
	int m;
	scanf_s("%d", &m);
	int s = 0;
	int x;
	while (m--) {
		scanf_s("%s", b);
		if (!strcmp(b, "add")) {
			scanf_s("%d", &x);
			x--;
			s = (s | (1 << x));
		}
		else if (!strcmp(b, "remove")) {
			scanf_s("%d", &x);
			x--;
			s = (s & ~(1 << x));
		}
		else if (!strcmp(b, "check")) {
			scanf_s("%d", &x);
			x--;
			int res = (s & (1 << x));
			if (res) {
				puts("1");
			}
			else {
				puts("0");
			}
		}
		else if (!strcmp(b, "toggle")) {
			scanf_s("%d", &x);
			x--;
			s = (s ^ (1 << x));
		}
		else if (!strcmp(b, "all")) {
			s = (1 << n) - 1;
		}
		else if(!strcmp(b, "empty")) {
			s = 0;
		}
	}
	
	return 0;
}
