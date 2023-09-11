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


#define FOR(i , x , n) for(ll i = x ; i <= n ; ++i)
#define REP(i , n) for(ll i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(ll i = x ; i >= n ; --i)

#define ll long long
#define oo 1e17
#define int long long
#define eps 1e-8

const int N = 3e6 + 5;
const int VAL = log2(VAL) + 2;
int n , res , r;
int val[N] , k[N] , par[N];
ii b[N];
iii a[N];
vector < int > ans;
vector < ii > ans1;

int acs(int u)
{
    if(par[u] == u) return u;
    return par[u] = acs(par[u]);
}

void join(int u , int v)
{
    par[acs(u)] = acs(v);
}

main()
{
    freopen("TaskD.inp", "r", stdin);
    freopen("TaskD.ans", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i , 1 , n)
        cin >> b[i].fi >> b[i].se;
    FOR(i , 1 , n)
    {
        cin >> val[i];
        a[++r] = iii(val[i] , ii(n + 1 , i));
    }
    FOR(i , 1 , n)
        cin >> k[i];

    FOR(i , 1 , n)
    {
        FOR(j , i + 1 , n)
            a[++r] = iii(((abs(b[i].fi - b[j].fi) + abs(b[i].se - b[j].se)) * (k[i] + k[j])) , ii(i , j));
    }
    sort(a + 1 , a + 1 + r);
    FOR(i , 1 , n + 1)
        par[i] = i;

    FOR(i , 1 , r)
    {
        int u = a[i].se.fi;
        int v = a[i].se.se;
        if(acs(u) != acs(v))
        {
            res += a[i].fi;
            join(u , v);
            if(u == n + 1)
                ans.pb(v);
            else if(v == n + 1)
                ans.pb(u);
            else
                ans1.pb(ii(u , v));
        }
    }
    cout << res << "\n";
    cout << ans.size() << "\n";
    REP(s , ans.size())
        cout << ans[s] << " ";
    cout << "\n";
    cout << ans1.size() << "\n";
    REP(s , ans1.size())
        cout << ans1[s].fi << " " << ans1[s].se << "\n";
}