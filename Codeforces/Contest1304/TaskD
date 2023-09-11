#include<bits/stdc++.h>
using namespace std;
 
#define y1 as214
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >
 
#define fi first
#define se second
#define fr front()
#define pb push_back
#define t top()
 
#define FOR(i , x , n) for(ll i = x ; i <= n ; ++i)
#define REP(i , n) for(ll i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(ll i = x ; i >= n ; --i)
 
#define ll long long
#define oo 1e17
#define eps 1e-8
#define div divv
#define pow poww
#define int long long
 
const int N = 1e5 + 5;
const int LOG = 27;
int n , q;
int h[N];
int P[N][LOG];
vector < int > g[N];
 
void DFS(int i , int j)
{
    REP(s , g[i].size())
    {
        int u = g[i][s];
        if(u != j)
        {
            h[u] = h[i] + 1;
            P[u][0] = i;
            DFS(u , i);
        }
    }
}
 
void init_LCA()
{
    for(int i = 1 ; (1 << i) <= n ; ++i)
        FOR(j , 1 , n)
            P[j][i] = P[P[j][i - 1]][i - 1];
}
 
int LCA(int u , int v)
{
                //cerr << u << " " << v << endl;
    int res = 0;
    if(h[u] < h[v])
        swap(u , v);
    int z = log2(h[u]);
    FORD(i , z , 0)
        if(h[u] - (1 << i) >= h[v])
        {
            u = P[u][i];
            res += (1 << i);
        }
    if(u == v) return res;
    FORD(i , z , 0)
        if(P[u][i] != P[v][i])
        {
            u = P[u][i];
            v = P[v][i];
            //cerr << (1 << i) << " " << u << " " << v << endl;
            res += (2 * (1 << i));
        }
    return res + 2;
}
 
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i , 1 , n - 1)
    {
        int x , y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    DFS(1 , -1);
    init_LCA();
    cin >> q;
    while(q--)
    {
        bool ok = false;
        int x , y , a , b , k;
        cin >> x >> y >> a >> b >> k;
        //cerr << LCA(a , x) + 1 + LCA(y , b) << endl;
        if(k - LCA(a , b) >= 0 && abs(LCA(a , b) - k) % 2 == 0)
        {
            ok = true;
        }
        else if(k - LCA(a , x) - 1 - LCA(y , b) >= 0 && abs(LCA(a , x) + 1 + LCA(y , b) - k) % 2 == 0)
        {
            ok = true;
        }
        else if(k - LCA(a , y) - 1 - LCA(x , b) >= 0 && abs(LCA(a , y) + 1 + LCA(x , b) - k) % 2 == 0)
        {
            //cerr << "." << endl;
            ok = true;
        }
        else if (k - LCA(a, b) - LCA(b, x) - 1 - LCA(y, b) >= 0 && abs(k - LCA(a, b) - LCA(b, x) - 1 - LCA(y, b)) % 2 == 0) {
            ok = true;
        }
        else if (k - LCA(a, b) - LCA(b, y) - 1 - LCA(x, b) >= 0 && abs(k - LCA(a, b) - LCA(b, y) - 1 - LCA(x, b)) % 2 == 0) {
            ok = true;
        }
        if(ok)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}