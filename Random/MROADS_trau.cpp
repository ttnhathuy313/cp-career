#include<bits/stdc++.h>
using namespace std;

#define y1 hasjdnasd
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define pb push_back
#define fr front()

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)
#define REP(i , x) for(int i = 0 ; i < x ; ++i)

#define ll long long
#define oo 1e17
#define int long long

const int N = 1e5 + 5;
int n , m , mod = 1e9 + 7 , res = 1;
int prefix[N] , suffix[N];
int dp[N][3];
bool mark[N];
bool ok;
vector < int > inv;
vector < int > g[N];

/// dp[i][0] là số cách thỏa mà thằng i không được chọn làm đại diện , dp[i][1] là số cách thỏa mà thằng i được chọn làm đại diện.

int mul(int a , int b)
{
    return (a * b) % mod;
}

int add(int a , int b)
{
    return (a + b) % mod;
}

void DFS(int i , int j)
{
    vector < int > inv;
    inv.clear();
    int res = 0;
    mark[i] = true;
    REP(s , g[i].size())
    {
        int u = g[i][s];
        if(u != j)
        {
            if(mark[u])
                ok = false;
            else
            {
                DFS(u , i);
                inv.pb(u);
            }
        }
    }
    int sz = inv.size();
    prefix[0] = 1;
    suffix[sz + 1] = 1;
    FOR(i , 1 , sz)
    {
        int u = inv[i - 1];
        prefix[i] = mul(prefix[i - 1] , dp[u][0]);
    }
    FORD(i , sz , 1)
    {
        int u = inv[i - 1];
        suffix[i] = mul(suffix[i + 1] , dp[u][0]);
    }
    FOR(k , 1 , sz)
    {
        int u = inv[k - 1];
        dp[i][1] = add(dp[i][1] , mul(mul(prefix[k - 1] , suffix[k + 1]) , add(dp[u][0] , dp[u][1])));
    }
    dp[i][0] = add(dp[i][0] , prefix[sz]);
}

main()
{
    freopen("MROADS.inp","r",stdin);
    freopen("MROADS.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    FOR(i , 1 , m)
    {
        int x , y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    FOR(i , 1 , n)
        if(!mark[i])
        {
            ok = true;
            DFS(i , -1);
            if(ok)
                res = mul(res , add(dp[i][0] , dp[i][1]));
            else
                res = mul(res , 2);
        }
    cout << res;
}
