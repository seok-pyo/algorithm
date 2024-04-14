#include <iostream>;

using namespace std;

int fact(int n) {
	if (n == 1 || n == 0) return 1;
	return n * fact(n - 1);
}

int fact_for(int n) {
	int res = 1;
	for (int i = n; i > 1; i--) {
		res *= i;
	}
	return res;
}

int n = 5;
int main() {
	cout << fact(n) << '\n';
	cout << fact_for(n) << '\n';
	return 0;
}