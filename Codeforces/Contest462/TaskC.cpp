#include<bits/stdc++.h>
 
using namespace std;
#define int long long

const int N = 1e5 + 10, mod = 1e9 + 7;
int c[N], tmp, n, dp[N][2];
vector <int> x[N];
 
void dfs(int v,int p) {
    dp[v][0] = 1;
    dp[v][1] = 0;
    for (int u : x[v]) {
        if (u==p) continue;
        dfs(u,v);
        dp[v][1] = ((dp[v][1] * dp[u][0]) % mod + (dp[v][0] * dp[u][1]) % mod) % mod;
        dp[v][0] = (dp[v][0] * dp[u][0]) % mod;
    }
    if (c[v]) dp[v][1] = dp[v][0];
    else dp[v][0] = (dp[v][0] + dp[v][1]) % mod;
}
 
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.inp", "r", stdin);
	cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> tmp;
        x[i].push_back(tmp);
        x[tmp].push_back(i);
    }
    for (int i = 0; i < n; ++i) cin >> c[i];
    dfs(0,-1);
    cout << dp[0][1] << endl;
    return 0;
}