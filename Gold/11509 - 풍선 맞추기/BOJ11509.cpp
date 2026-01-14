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
#include <string>
#include <tuple>
#include <climits>
using namespace std;

int n;
int a[1000001], check[1000001];
vector<int> arrow(1000001);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int ret = 0;

	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;
		if (arrow[h] > 0) arrow[h]--;
		else ret++;
		arrow[h - 1]++;
	}

	cout << ret;
}
