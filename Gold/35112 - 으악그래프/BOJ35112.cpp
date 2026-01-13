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

int n, m;
vector<int> graph[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	if (m == n - 1 || m == n) cout << "Yes";
	else cout << "No";
}
