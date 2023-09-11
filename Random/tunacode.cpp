#include <bits/stdc++.h>
using namespace std;
 
struct pppp {
    int x1, y1, y2, type;
    bool operator < (const pppp &o) const {
        return x1 < o.x1;
    }
};
 
vector <pppp> event;
pair <int, int> it[33333 << 2];
int n, ans = 0;
 
void update(int id, int l, int r, int i, int j, int v) {
    if(r <= i || j <= l) {
        return;
    }
    if(i <= l && r <= j) {
        it[id].first += v;
        // if (i == 1 && j == 4) cerr << l << ' ' << r << ' ' << it[id].first << ' ' << endl;
    } else {
        int m = (l + r) >> 1;
        update(id << 1, l, m, i, j, v);
        update((id << 1) | 1, m, r, i, j, v);
    }
    if(!it[id].first) it[id].second = it[id << 1].second + it[(id << 1) | 1].second;
    else it[id].second = r - l;
}
 
int main() {
    n = 4;
    update(1, 1, n, 1, 4, 1);
    update(1, 1, n, 1, 2, -1);
    cout << it[1].second << endl;
} 