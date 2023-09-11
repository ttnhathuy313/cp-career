#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < ll , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define ll long long
#define oo 1e7

const int N = 2e3 + 2e2;
int n;
int a[N] , b[N];
int dp[N];
int f[N][10];

bool okk(int i , int j)
{
    if((i - j) == 1 || (i - j) == 8 || (i - j) == 9)
        return false;
    return true;
}

main()
{
    freopen("SEQ198.inp","r",stdin);
    freopen("SEQ198.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i , 1 , n)
        cin >> a[i];
    sort(a + 1 , a + 1 + n);
    memset(dp , -1 , sizeof(dp));
    dp[0] = 0;
    FOR(i , 1 , n)
    {
        int k = a[i] % 10;
        for(int mask = (1 << 10) - 1 ; mask >= 0 ; mask--)
            if((mask >> k) & 1)
            {
                int r = 0;
                FOR(j , 0 , 9)
                    if((mask >> j) & 1)
                        b[++r] = j;
                if(dp[mask] != -1)
                {
                    bool ok = true;
                    FOR(j , 1 , r)
                        if(!okk(a[i] , f[mask][b[j]]))
                            ok = false;
                    if(ok)
                    {
                        dp[mask] = dp[mask] + 1;
                        FOR(j , 1 , r)
                            f[mask][b[j]] = f[mask][b[j]];
                        f[mask][k] = a[i];
                    }
                }
                int submask = mask ^ (1 << k);
                if(dp[submask] != -1)
                {
                    bool ok = true;
                    FOR(j , 1 , r)
                        if(b[j] != k && !okk(a[i] , f[submask][b[j]]))
                            ok = false;
                    if(ok)
                    {
                        dp[mask] = max(dp[mask] , dp[submask] + 1);
                        FOR(j , 1 , r)
                            f[mask][b[j]] = f[submask][b[j]];
                        f[mask][k] = a[i];
                    }
                }
            }
    }
    int res = 0;
    REP(i , (1 << 10))
        res = max(res , dp[i]);
    cout << n - res;
}
