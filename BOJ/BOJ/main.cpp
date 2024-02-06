// 재귀 시도(시간 초과)
#include <iostream>
#include <vector>
using namespace std;
int arr[1001];
int n;
int cnt = 0;
void DFS(vector<int>& ck, int S, int idx) {
	cnt = max(cnt, static_cast<int>(ck.size()));
	
	for (int i = idx + 1; i <= n; i++) {
		if (arr[i] > S) {
			ck.push_back(arr[i]);
			DFS(ck, arr[i], i);
			ck.pop_back();
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	vector<int> chk;
	chk.push_back(arr[1]);
	DFS(chk, arr[1], 1);
	
	cout << cnt << '\n';
	return 0;
}

// 재귀 시도2 (시간초과)
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1001;

int arr[MAX_N];
int n;
int cnt = 1;

void DFS(int S, int idx, int length) {
    cnt = max(cnt, length);

    for (int i = idx + 1; i <= n; i++) {
        if (arr[i] > S) {
            DFS(arr[i], i, length + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        DFS(arr[i], i, 1);
    }

    cout << cnt << '\n';

    return 0;
}
