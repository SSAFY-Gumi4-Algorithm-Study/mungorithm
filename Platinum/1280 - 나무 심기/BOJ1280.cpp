#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

long long cntTree[200003];
long long sumTree[200003];
const int MOD = 1000000007;

int n;

void update(long long tree[], int idx, int val) {
	while (idx <= 200001) {
		tree[idx] += val;
		idx += idx & -idx;
	}
}

long long query(long long tree[], int idx) {
	long long sum = 0;
	while (idx > 0) {
		sum += tree[idx];
		idx -= idx & -idx;
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;

	long long ret = 1;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		x++;

		if (i > 1) {
			long long leftCnt = query(cntTree, x - 1);
			long long leftSum = query(sumTree, x - 1);

			long long totalCnt = query(cntTree, 200001);
			long long totalSum = query(sumTree, 200001);

			long long rightCnt = totalCnt - leftCnt;
			long long rightSum = totalSum - leftSum;

			long long cost = (x * leftCnt - leftSum) + (rightSum - x * rightCnt);
			cost %= MOD;
			ret = (ret * cost) % MOD;
		}

		update(cntTree, x, 1);
		update(sumTree, x, x);
	}
	cout << ret % MOD;
}
          
