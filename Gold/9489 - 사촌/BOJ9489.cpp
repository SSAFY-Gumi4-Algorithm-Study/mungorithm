#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cstring>
using namespace std;

int n, k;
vector<int> node;
int parent[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (true) {
        node.clear();
        cin >> n >> k;
        if (n == 0 && k == 0) break;

        int prev = -1;
        int parent_idx = -1;
        int ret = 0;
         
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            node.push_back(num);
            if (i == 0) {
                prev = num;
                parent[num] = -1;
            }
            else {
                if (prev + 1 == num) {
                    parent[num] = node[parent_idx];
                    prev = num;
                }
                else {
                    prev = num;
                    parent_idx++;
                    parent[num] = node[parent_idx];
                }
            }
        }
        if (k == node[0]) {
            ret = 0;
        }
        else {
            for (int i = 0; i < node.size(); i++) {
                if (parent[parent[node[i]]] == parent[parent[k]] && parent[node[i]] != parent[k]) ret++;
            }
        }
        cout << ret << '\n';
    }
}
