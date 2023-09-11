#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
const int WB = 500;
const int WL = 207;
int f[N], g[N], id[N], n, q, wf[N], fa[N][22], dep[N], index;
int pos[N], ans[N], bc[WL], cnt[N];
bool vis[N];
struct Edge {
    int v, w;
};
vector<Edge> adj[N];
struct Query{
    int l, r, id;
    bool operator < (const Query& rhs) const {
        return pos[l]<pos[rhs.l] || (pos[l]==pos[rhs.l]&&r<rhs.r);
    }
}qs[N];
int lca(int x, int y) {
    if(dep[x]<dep[y]) swap(x, y);
    if(dep[x]!=dep[y]) {
        int dis = dep[x]-dep[y];
        for(int i=20; i>=0; --i) {
            if(dis>=(1<<i)) dis-=(1<<i), x=fa[x][i];
        }
    }
    if(x==y) return x;
    for(int i=20; i>=0; --i) {
        if(fa[x][i]!=fa[y][i]) x=fa[x][i], y=fa[y][i];
    }
    return fa[x][0];
}
void dfs(int u, int w) {
    id[f[u]=++index]=u;
    wf[u]=w;
    for(Edge e : adj[u]) {
        if(e.v!=fa[u][0]) {
            fa[e.v][0]=u;
            dep[e.v] = dep[u]+1;
            dfs(e.v, e.w);
        }
    }
    id[g[u]=++index]=u;
}
void add(int x) {
//    printf("add %d\n", x);
    int w = wf[x];
    int b = w/WB;
    if(cnt[w]==0) {
        ++bc[b];
    }
    ++cnt[w];
}
void del(int x) {
//    printf("del %d\n", x);
    int w = wf[x];
    int b = w/WB;
    if(cnt[w]==1) {
        --bc[b];
    }
    --cnt[w];
}
void modify(int x) {
    if(wf[x]>=100000) return;
    if(vis[x]) {
        del(x);
        vis[x] = false;
    } else {
        add(x);
        vis[x] = true;
    }
}
int query() {
    for(int i=0; i<WL; ++i) {
        if(bc[i]!=WB) {
            for(int j=i*WB; j<(i+1)*WB; ++j) {
                if(!cnt[j]) return j;
            }
        }
    }
    assert(false);
}
int main() {
    freopen("100962F.inp", "r", stdin);
    freopen("100962F.ans", "w", stdout);
    scanf("%d%d", &n, &q);
    for(int i=1; i<n; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1, N);
    for(int j=1; j<=20; ++j) {
        for(int i=1; i<=n; ++i) {
            fa[i][j]=fa[fa[i][j-1]][j-1];
        }
    }
    int B = sqrt(index);
    for(int i=1; i<=index; ++i) {
        pos[i] = (i-1)/B;
    }
    for(int i=0; i<q; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        if(f[l]>f[r]) swap(l, r);
        qs[i] = {lca(l, r)==l?f[l]:g[l], f[r], i};
//        printf("qq: %d %d\n", qs[i].l, qs[i].r);
    }
//    printf("dfs xv:\n");
//    for(int i=1; i<=index; ++i) printf("%d%c", id[i], i==index?'\n':' ');
    sort(qs, qs+q);
    int L, R;
    L=1; R=0;
    for(int i=0; i<q; ++i) {
        while(L>qs[i].l) modify(id[--L]);
        while(R<qs[i].r) modify(id[++R]);
        while(L<qs[i].l) modify(id[L++]);
        while(R>qs[i].r) modify(id[R--]);
        int x = id[L], y = id[R];
        int llca = lca(x, y);
        if(llca==x||llca==y) {
            modify(llca);
            ans[qs[i].id] = query();
            modify(llca);
        } else {
            ans[qs[i].id] = query();
        }
//        printf("ans[%d]=%d, lca=%d, L=%d, R=%d\n", qs[i].id, ans[qs[i].id], llca, L, R);
    }
    for(int i=0; i<q; ++i) {
        printf("%d\n", ans[i]);
    }
}