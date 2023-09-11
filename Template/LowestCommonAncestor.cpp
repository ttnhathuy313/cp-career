#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, loga = 31;
vector <int> adj[N];
int p[N][loga], depth[N];

void dfs(int u, int par, int dfscount) { //Call dfs(1,0, 0);
    depth[u] = dfscount;
    p[u][0] = par;
    for (int lo = 1; lo < loga; ++lo) if ((1 << lo) <= depth[u]) {
        p[u][lo] = p[p[u][lo - 1]][lo - 1];
    }
    for (int v : adj[u]) if (v != par) dfs(v, u, dfscount + 1);
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = loga; i >= 0; --i) if (depth[u] - depth[v] - (1 << i) >= 0) u = p[u][i];
    if (u == v) return u;
    cerr << u << endl;
    for (int i = loga; i >= 0; --i) if (depth[u] - (1 << i) >= 0 && p[u][i] != p[v][i]) {
        u = p[u][i];
        v = p[v][i];
    }
    return p[v][0];
}

int go(int source, int len) {
    for (int i = loga; i >= 0; i--) if (len - (1 << i) >= 0) len -= (1 << i), source = p[source][i];
    return source;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("LowestCommonAncestor.inp", "r", stdin);
    freopen("LowestCommonAncestor.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,0);
    for (int i = 1; i <= n; ++i) 
        for (int j = i + 1; j <= n; ++j) 
            cout << "The LowestCommonAncestor of " << i << " and " << j << " is " << lca(i, j) << endl;
    return 0;
}