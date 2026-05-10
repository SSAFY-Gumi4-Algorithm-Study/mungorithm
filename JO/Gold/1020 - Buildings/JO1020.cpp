#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <cstring>
#include <stack>
using namespace std;

int n;

struct State {
    int x, h, type;
    
    bool operator < (const State& other) const {
        return x < other.x;
    }
};

vector<State> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int a, b, h;
        cin >> a >> b >> h;
        v.push_back({ a, h, 1 });
        v.push_back({ b, h, -1 });
    }

    sort(v.begin(), v.end());

    multiset<int> heights;
    heights.insert(0);

    int prevx = v[0].x;
    long long ret = 0;

    for (int i = 0; i < v.size();) {
        int curx = v[i].x;
        long long maxH = *heights.rbegin();
        ret += (curx - prevx) * maxH;

        while (i < v.size() && v[i].x == curx) {
            if (v[i].type == 1) {
                heights.insert(v[i].h);
            }
            else {
                auto it = heights.find(v[i].h);
                if (it != heights.end()) heights.erase(it);
            }
            i++;
        }
        prevx = curx;
    }

    cout << ret;
}
