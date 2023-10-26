#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;
#define int long long

const int K = 1005;
struct coord {
    int x, y, z;
    bool operator < (const coord &other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }
} a[K];

map <int, int> cnt[4];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  
    // freopen("input.txt", "r", stdin);

    int n, k;
    cin >> n >> k;
    set <coord> S;
    S.clear();
    for (int i = 1; i <= k; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
        S.insert({a[i].x, a[i].y, a[i].z});
    }
    int res = n * S.size();
    k = 0;
    for (coord d : S) {
        k++;
        a[k] = d;
    }
    int triplet = 0;
    for (int i = 1; i <= k; ++i) {
        int type_i;
        if (a[i].x == 0) {
            type_i = 1;
        }
        else if (a[i].y == 0) {
            type_i = 2;
        }
        else {
            type_i = 3;
        }

        for (int j = 1; j < i; ++j) {
            int type_j;
            if (a[j].x == 0) {
                type_j = 1;
            } else if (a[j].y == 0) {
                type_j = 2;
            }
            else {
                type_j = 3;
            }
            if (type_i == type_j) {
                continue;
            }
            if (a[i].x == a[j].x || a[i].y == a[j].y || a[i].z == a[j].z) {
                res--;
            }
            coord tmp = {a[i].x ^ a[j].x, a[i].y ^ a[j].y, a[i].z ^ a[j].z};
            if (S.find(tmp) != S.end()) {
                triplet++;
            }
        }

    }

    cout << res + triplet / 3 << endl;

    return 0;
}