#include<bits/stdc++.h>

using namespace std;
#define int long long

typedef pair <int, int> ii;
const int N = 2e5 + 6;
const int LOG = log2(N) + 5;
int n, m, k, ans1;
int dist1[N], dist2[N];
int a[N];
queue <int> q;
vector <int> adj[N];
multiset <ii> mul;
vector <int> ans[N];

void BFS(int i, int dist[]) {
    q.push(i);
    dist[i] = 0;
    int res = -1;
    if(a[i] == 1)
        ans[0].push_back(i);
    while(!q.empty()) {
        int u = q.front();
        if(i == n && res < dist[u]) {
            res = dist[u];
            if(dist[u] != 0) {
                for (int v : ans[dist[u] - 1]) {
                    if(a[v] == 1) {
                        mul.erase(mul.find(ii(dist1[v] , v)));
                    }
                }
            }
        }
        if(i == n && a[u] == 1) {
            mul.erase(ii(dist1[u] , u));
            auto it = mul.end();
            if(!mul.empty()) {
                it--;
                ii v = *(it);
                ans1 = max(ans1 , dist[u] + v.first + 1LL);
            }
            mul.insert(ii(dist1[u] , u));
        }
        q.pop();
        for (int v : adj[u]) {
            if(dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                ans[dist[v]].push_back(v);
                q.push(v);
            }
        }
    }
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("taskd.inp","r",stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dist1, 0x1f , sizeof(dist1));
    memset(dist2, 0x1f , sizeof(dist2));
    BFS(1, dist1);
    for (int i = 1; i <= n; ++i)
        if(a[i] == 1)
            mul.insert(ii(dist1[i] , i));
    for (int i = 0; i <= n; ++i)
        ans[i].clear();
    BFS(n, dist2);
    ans1 = min(ans1, dist1[n]);
    cout << ans1;
    return 0;
}