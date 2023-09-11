#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define N 1000001

using namespace std;

typedef long long ll;

const ll INF = 1e18, MOD = 1e9 + 7, MOD2 = 1e6 + 3;

vector <int> g[N];
bitset <N + 2> dp;

int sz[N], n, pr[N];

int dfs (int x, int p) {
    sz[x] = 1;
    pr[x] = p;

    for (int to : g[x]) {
        if (to == p) continue;
        sz[x] += dfs (to, x);
    }

    return sz[x];
}

ll dfs_count (int x, int p) {
    ll sum = sz[x] - 1;
    for (int to : g[x]) {
        if (to == p) continue;
        sum += dfs_count (to, x);
    }

    return sum;
}

int knapsack (int x) {
    int p = pr[x];
    for (int to : g[x]) {
        if (to == p) continue;
        if (sz[to] >= n / 2) {
            return sz[to];
        }
    }

    if (sz[x] <= n / 2) {
        return n - sz[x];
    }

    vector <int> items (n + 2);
    vector <int> v;
    for (int to : g[x]) {
        if (to != p) items[sz[to]]++;
    }
    items[n-sz[x]]++;

    for (int x = 1; x < n; x++) {
        int b = 1;
        for (int i = 0; (1 << (i + 1)) - 1 <= items[x]; i++) {
            v.push_back ((1 << i) * x);
            b <<= 1;
        }
        if (items[x] - b + 1) {
            v.push_back (x * (items[x] - b + 1));
        }
    }

    dp.reset ();
    dp[0] = 1;
    int mn = 0, sm = 0;

    for (int a : v) {
        dp |= (dp << a);
    }

    for (int i = 0; 2 * i < n; i++)
        if (dp[i]) mn = i;

    return mn;
}

int main () {
    ios::sync_with_stdio (false);
    cin.tie (NULL);
    freopen("POLARIZATION.INP", "r", stdin);
    freopen("POLARIZATION.ANS", "w", stdout);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back (v);
        g[v].push_back (u);
    }

    dfs (0, -1);

    pair <int, int> ans {0, 0};
    for (int i = 0; i < n; i++) {
        int x = knapsack (i);
        if (abs (n - 2 * ans.first) > abs (n - 2 * x))
            ans = {x, i};
    }

    memset (sz, 0, sizeof (sz));
    dfs (ans.second, -1);
    cout << n - 1 << ' ';
    ll x = dfs_count (ans.second, -1) + (ll) ans.first * (n - ans.first - 1);
    cout << x << endl;
}