#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5;
int n;
int a[N], b[N];

int cnt(int x, int y) {
    if (x > y) return 1;
    if (x < y) return -1;
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("RACE.INP", "r", stdin);
    freopen("RACE.ANS", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    int res = -N;
    do {
        int cost = 0;
        for (int i = 1; i <= n; ++i)
            cost += cnt(a[i], b[i]);
        if (cost == 4) {
            for (int i = 1; i <= n; ++i) {
                cerr << b[i] << ' ';
            } cerr << endl;
            return 0;
        }
        res = max(res, cost);
    }while (next_permutation(b + 1, b + 1 + n));
    cout << res << endl;

    return 0;
}
