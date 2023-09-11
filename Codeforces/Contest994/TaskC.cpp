#include<bits/stdc++.h>

using namespace std;
#define int long long

int x1, x2, x3, x4, x1r, x2r, x3r, x4r;
int y1, y2, y3, y4, y1r, y2r, y3r, y4r;
 
bool inter(int x, int y) {
    if (x1 > x3) swap(x1, x3);
    if (y1 > y3) swap(y1, y3);
    return (x1 <= x && x <= x3 && y1 <= y && y <= y3);
}
 
bool inter_r(int x, int y) {
    if (x1r == x3r)
        return (abs(y - (y1r + y3r) / 2) + abs(x - (x2r + x4r) / 2) <= abs(y1r - y3r) / 2);
    return (abs(y - (y2r + y4r) / 2) + abs(x - (x1r + x3r) / 2) <= abs(y2r - y4r) / 2);
}
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    cin >> x1r >> y1r >> x2r >> y2r >> x3r >> y3r >> x4r >> y4r;
    for (int i = -100; i <= 100; i++) {
        for (int j = -100; j <= 100; j++) {
            if (inter_r(i, j) && inter(i, j)) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;

}