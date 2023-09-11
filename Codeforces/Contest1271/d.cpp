#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int N = 5e3 + 5, VAL = 3e5 + 5, oo = 1e9 + 7;
iii a[N];
int n, m, k, dp[N], f[N], b[N];
vector <int> adj[VAL];
priority_queue <ii> q;
bool ok[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TaskD.inp", "r", stdin);
    freopen("TaskD.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].first >> a[i].second.first >> a[i].second.second;
    for (int i = 1; i <= m; ++i) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i)
        adj[i].push_back(i);
    b[0] = k;
    bool die = false;
    for (int i = 1; i <= n; ++i) {
        dp[i] = b[i - 1] - a[i].first;
        b[i] = b[i - 1] + a[i].second.first;
        if(dp[i] < 0)
        {
            die = true;
            break;
        }
        cerr << "dp[" << i << "] : " << dp[i] << endl;
    }
    if (die) {
        cout << -1 << endl;
        return 0;
    }
    int res = 0;
    f[n + 1] = oo;
    dp[n + 1] = b[n];
    dp[1] = 0;
    for (int i = n; i >= 1; --i) {
        f[i] = min(dp[i + 1], f[i + 1]);
        for (int v : adj[i]) {
            q.push(ii(a[v].second.second, v));
        }
        while(!q.empty()) {
            int id = q.top().second;
            int val = q.top().first;
            if(f[i] <= dp[i])
                break;
            q.pop();
            if(ok[id] == 0) {
                f[i]--;
                ok[id] = 1;
                res += val;
            }
        }
    }
    cout << res << endl;
    return 0;
}