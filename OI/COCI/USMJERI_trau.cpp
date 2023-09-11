#include <bits/stdc++.h>
 
using namespace std;
 
#define X first
#define Y second
 
typedef pair <int, int> pii;
 
const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 5;
const int LOG = 20;
 
int n, m;
vector <int> veze[MAXN];
vector <pii> obojano[MAXN];
int lca[LOG][MAXN];
int dubina[MAXN];
int jednak[MAXN];
int finito[MAXN];
 
void dfs_lca(int cvor, int pcvor, int tdubina) {
    dubina[cvor] = tdubina;
    for (auto ncvor : veze[cvor]) {
        if (ncvor == pcvor) continue;
        dfs_lca(ncvor, cvor, tdubina + 1);
        lca[0][ncvor] = cvor;
    }
}
 
int nadi_lca(int a, int b) {
    if (dubina[a] < dubina[b]) swap(a, b);
 
    for (int i = LOG - 1; i >= 0; i--) {
        if (dubina[a] - (1 << i) < dubina[b]) continue;
        a = lca[i][a];
    }
 
    if (a == b) return a;
 
    for (int i = LOG - 1; i >= 0; i--) {
        if (lca[i][a] == lca[i][b]) continue;
        a = lca[i][a]; b = lca[i][b];
    }
 
    return lca[0][a];
}
 
int spoji(int cvor, int pcvor) {
    for (auto ncvor : veze[cvor]) {
        if (ncvor == pcvor) continue;
        int nspoji = spoji(ncvor, cvor);
        jednak[cvor] = min(jednak[cvor], nspoji);
        if (nspoji < dubina[cvor]) {
            obojano[cvor].push_back({ncvor, 0});
            obojano[ncvor].push_back({cvor, 0});
        }
    }
    return jednak[cvor];
}
 
int dfs(int cvor, int boja) {
    if (finito[cvor] != -1) return finito[cvor] == boja;
    finito[cvor] = boja;
 
    for (auto ncvor : obojano[cvor]) {
        if (!dfs(ncvor.X, boja ^ ncvor.Y)) return false;
    }
 
    return true;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("USMJERI.INP", "r", stdin);
    freopen("USMJERI.ANS", "w", stdout);
 
    memset(finito, -1, sizeof(finito));
 
    cin >> n >> m;
 
    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        veze[a].push_back(b);
        veze[b].push_back(a);
    }
 
    dfs_lca(1, -1, 1);
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            lca[i][j] = lca[i - 1][lca[i - 1][j]];
        }
    }
 
    for (int i = 0; i < MAXN; i++) jednak[i] = dubina[i];
 
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        int zajednicki = nadi_lca(a, b);
        jednak[a] = min(jednak[a], dubina[zajednicki]);
        jednak[b] = min(jednak[b], dubina[zajednicki]);
        if (a != zajednicki && b != zajednicki) {
            obojano[a].push_back({b, 1});
            obojano[b].push_back({a, 1});
        }
    }
 
    spoji(1, -1);
 
    long long nacini = 1;
    for (int i = 2; i <= n; i++) {
        if (finito[i] != -1) continue;
        if (!dfs(i, 0)) {
            nacini = 0;
            break;
        }
        nacini *= 2;
        nacini %= MOD;
    }
 
    cout << nacini << '\n';
 
    /*
    for (int i = 1; i <= n; i++) cout << dubina[i] << " "; cout << '\n';
    for (int i = 1; i <= n; i++) cout << jednak[i] << " "; cout << '\n';
    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        for (auto nx : obojano[i]) {
            cout << nx.first << " " << nx.second << " , ";
        }
        cout << '\n';
    }
    */
 
    return 0;
}