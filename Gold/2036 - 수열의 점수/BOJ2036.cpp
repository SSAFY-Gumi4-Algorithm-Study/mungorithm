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
vector<int> p, m;
int o, z;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 0) z++;
		else if (num == 1) o++;
		else if (num > 0) p.push_back(num);
		else m.push_back(num);
	}

	sort(p.rbegin(), p.rend());
	sort(m.begin(), m.end());
	
	long long ret = 0;

	int pSize = p.size();
	int mSize = m.size();

	for (int i = 0; i < pSize - 1; i += 2) {
		ret += (long long)p[i] * p[i + 1];
	}
	if (p.size() % 2 == 1) ret += p.back();

	for (int i = 0; i < mSize - 1; i += 2) {
		ret += (long long)m[i] * m[i + 1];
	}
	if (m.size() % 2 == 1 && !z) ret += m.back();

	ret += o;
	cout << ret;
}
