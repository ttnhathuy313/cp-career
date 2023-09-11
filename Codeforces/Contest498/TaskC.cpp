#include <bits/stdc++.h>

using namespace std;
#define int long long
 
const int oo = 1e9 + 7;

struct Edge {
    Edge() {x = y = c = f = 0;}
    Edge(int _x, int _y, int _c, int _f) : x(_x), y(_y), c(_c), f(_f) {}
    int x, y, c, f;
};

struct MaxFlow {
    int n, m, s, t, maxFlow;
    vector <int> excess, cnt, seen, h;
    vector <vector <int>> adj;
    vector <Edge> EdgeList;
    queue <int> ex_vertex;

    MaxFlow() {}
    MaxFlow(int n) {
        this -> n = n;
        excess.assign(n + 5, 0);
        cnt.assign(2 * n + 10, 0);
        seen.assign(n + 5, 0);
        h.assign(n + 5, 0);
        adj.assign(n + 5, vector <int> (0, 0));
        EdgeList.clear();
        while (!ex_vertex.empty()) ex_vertex.pop();
        maxFlow = -0;
    }

    void addEdge(int u, int v, int c) {
        adj[u].push_back(1LL * EdgeList.size());
        EdgeList.push_back(Edge(u, v, c, 0));
        adj[v].push_back(1LL * EdgeList.size());
        EdgeList.push_back(Edge(v, u, 0, 0));
    }

    void push(int index) {
        int Delta = min(EdgeList[index].c - EdgeList[index].f, excess[EdgeList[index].x]);
        EdgeList[index].f += Delta;
        EdgeList[index ^ 1].f -= Delta;
        excess[EdgeList[index].x] -= Delta;
        excess[EdgeList[index].y] += Delta;
    }
     
    void setH(int u, int newH) {
        cnt[h[u]]--;
        h[u] = newH;
        cnt[newH]++;
    }
     
    void Lift(int u) {
        int minH = 2 * n + 10;
        for (int index : adj[u]) if (EdgeList[index].c > EdgeList[index].f) {
            minH = min(minH, h[EdgeList[index].y]);
        }
        int OldH = h[u];
        setH(u, minH + 1);
        if (OldH > 0 && OldH < n && cnt[OldH] == 0) {
            for (int v = 1; v <= n; ++v) if (v != s && OldH < h[v] && h[v] <= n) {
                setH(v, n + 1);
                seen[v] = 0;
            }
        }
    }

    void init() {
        for (int i = 1; i <= n; ++i) h[i] = 1;
        h[s] = n; h[t] = 0;
        cnt[n] = 1; cnt[0] = 1; cnt[1] = n - 2;
        for (int id : adj[s]) {
            int sf = EdgeList[id].c;
            EdgeList[id].f += sf;
            EdgeList[id ^ 1].f = -sf;
            excess[EdgeList[id].y] += sf;
            excess[s] -= sf;
        }
        for (int i = 1; i <= n; ++i) if (i != s && i != t && excess[i] > 0) ex_vertex.push(i);
    }
     
    int getMaxFlow(int source, int sink) {
        s = source, t = sink;
        init();
        while (!ex_vertex.empty()) {
            int z = ex_vertex.front();
            ex_vertex.pop();
            while (seen[z] < adj[z].size()) {
                Edge e = EdgeList[adj[z][seen[z]]];
                if (e.c > e.f && h[e.x] > h[e.y]) {
                    bool NeedQueue = (e.y != s && e.y != t && excess[e.y] == 0);
                    push(adj[z][seen[z]]);
                    if (NeedQueue) ex_vertex.push(e.y);
                    if (excess[z] == 0) break;
                }
                seen[z]++;
            }
            if (excess[z] > 0) {
                Lift(z);
                seen[z] = 0;
                ex_vertex.push(z);
            }
        }
        maxFlow = excess[t];
        return excess[t];
    }
};
 
const int N = 105;
int eu[N], ev[N], id[N], cnt[N], a[N], n, m;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TaskC.inp", "r", stdin);
    freopen("TaskC.out", "w", stdout);

    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= m; ++i) cin >> eu[i] >> ev[i];
        int res = 0;
        vector <int> primes;
        for (int i = 1; i <= n; ++i) {
            int u = a[i];
            for(int p = 2; p * p <= u; ++p) {
                if (u % p == 0) {
                    primes.push_back(p);
                    while (u % p == 0) u /= p;
                }
            }
            if (u > 1) primes.push_back(u);
        }
        sort(primes.begin(), primes.end());
        primes.resize(unique(primes.begin(), primes.end()) - primes.begin());
        for(int p : primes) {
            int nleft = 0, nright = 0;
            for (int i = 1; i <= n; ++i)
                if (a[i] % p == 0) {
                    if (i % 2 == 1) id[i] = ++nleft; else id[i] = ++nright;
                    cnt[i] = 0;
                    while (a[i] % p == 0) {
                        ++cnt[i];
                        a[i] /= p;
                    }
                }
            else {
                id[i] = 0;
                cnt[i] = 0;
            }
            if (nleft && nright) {
                MaxFlow flow(nleft + nright + 2);
                int source = 0, sink = nleft + nright + 1;
                for (int i = 1; i <= n; ++i)if (id[i]) {
                    if (i % 2 == 1) flow.addEdge(source, id[i], cnt[i]);
                    else flow.addEdge(id[i] + nleft, sink, cnt[i]);
                }
                for (int i = 1; i <= m; ++i) {
                    int u = eu[i], v = ev[i];
                    if (u % 2 == 0) swap(u, v);
                    if (id[u] && id[v])
                        flow.addEdge(id[u], id[v] + nleft, 1000);
                }
                res += flow.getMaxFlow(source, sink);
            }
        }
        cout << res << endl;
    }
    return 0;
}