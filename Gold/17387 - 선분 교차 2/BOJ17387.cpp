#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
#include<map>
#include<cmath>
using namespace std;

// 백터의 내적을 구하는 함수
int CCW(int x1, int y1, int x2, int y2, int x3, int y3) {
    long long ret = ((long long)x2 - x1) * ((long long)y3 - y1) - ((long long)x3 - x1) * ((long long)y2 - y1);
    if (ret > 0) return 1;
    else if (ret == 0) return 0;
    else return -1;
}

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int a = CCW(x1, y1, x2, y2, x3, y3);
    int b = CCW(x1, y1, x2, y2, x4,y4);
    int c = CCW(x3, y3, x4, y4, x1, y1);
    int d = CCW(x3, y3, x4, y4, x2, y2);

    // 두 선분이 엇갈리는 경우
    if (a * b < 0 && c * d < 0) {
        cout << 1;
    }

    // 일직선일 때
    else if (a == 0 && b == 0) {
        int minx12 = min(x1, x2);
        int minx34 = min(x3, x4);
        int miny12 = min(y1, y2);
        int miny34 = min(y3, y4);
        int maxx12 = max(x1, x2);
        int maxx34 = max(x3, x4);
        int maxy12 = max(y1, y2);
        int maxy34 = max(y3, y4);
        if (minx12 <= maxx34 && minx34 <= maxx12 && miny12 <= maxy34 && miny34 <= maxy12) {
            cout << 1;
        }
        else cout << 0;
    }

    // 선분의 끝점이 다른 선분 위에 있을 때
    else if ((a * b == 0 && c * d <= 0) || a * b <= 0 && c * d == 0) cout << 1;

    else cout << 0;
}
