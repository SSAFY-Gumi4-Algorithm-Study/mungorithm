#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
long long a[100001];
long long psum[100001];
long long ret;

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; i++){
        psum[i] = a[i] + psum[i - 1];
    }

    long long sum = 0;
    for(int i = 1; i <= k; i++){
        sum += a[i] * (i - 1) - psum[i - 1];
    }

    ret = sum;

    for(int i = 1; i + k <= n; i++){
        int r = i + k - 1;
        long long tmp = psum[r] - psum[i];

        sum -= tmp - a[i] * (k - 1);
        sum += a[r + 1] * (k - 1) - tmp;
        ret = min(ret, sum);
    }
    cout << ret;
}
