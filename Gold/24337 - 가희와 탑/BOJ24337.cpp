#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

int n, a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> a >> b;

	int mx = max(a, b);

	int num = mx - 1;
	int cnt = a + b - 1;
	if (a + b <= n + 1) {
		if (a == 1) {
			cout << mx << ' ';
			while (cnt < n) {
				cout << 1 << ' ';
				cnt++;
			}
			for (int i = b - 1; i >= 1; i--) {
				cout << i << ' ';
			}
		}
		else {
			cout << '1' << ' ';
			while (cnt < n) {
				cout << 1 << ' ';
				cnt++;
			}
			for (int i = 2; i <= a - 1; i++) {
				cout << i << ' ';
			}

			cout << mx << ' ';
			for (int i = b - 1; i >= 1; i--) {
				cout << i << ' ';
			}
		}
		
	}
	else cout << -1;
}
