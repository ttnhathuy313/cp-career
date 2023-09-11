#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
#define forn(i, a, b) for (int i = a; i <= b; ++i)
 
const int N = 1e6 + 5;
int q, n, m1, m2, par[N][4];
vector <ii> ans;
 
int acs(int u, int k)
{
    return u == par[u][k] ? u : par[u][k] = acs(par[u][k], k);
}
 
void join(int u, int v, int k)
{
    par[acs(u , k)][k] = acs(v, k);
}
 
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TaskD1.inp", "r", stdin);
    freopen("TaskD1.out", "w", stdout);
    cin >> n >> m1 >> m2;
    forn(i, 1, 2)
        forn(j, 1, n)
            par[j][i] = j;

    forn(i, 1, m1) {
        int u, v;
        cin >> u >> v;
        join(u, v, 1);
    }
    forn(i, 1, m2) {
        int u, v;
        cin >> u >> v;
        join(u, v, 2);
    }
    forn(i, 1, n) forn(j, 1, n) if(acs(i, 1) != acs(j, 1) && acs(i, 2) != acs(j, 2)) {
            join(i, j, 1);
            join(i, j, 2);
            ans.push_back(ii(i, j));
        }
    cout << ans.size() << endl;
    for (auto V : ans) {
        cout << V.first << ' ' << V.second << endl;
    }

    return 0;
}