#include<bits/stdc++.h>
using namespace std;

#define y1 ansdasd
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back
#define t top()

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , x) for(int i = 0 ; i < x ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define ll long long
#define oo 1e17
#define int long long

const int N = 3e2 + 5;
int n , val;
int a[N];
int dp[N][N][N];

main()
{
    freopen("bonus.inp","r",stdin);
    freopen("bonus.ans","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> val;
    FOR(i , 1 , n)
        cin >> a[i];
    memset(dp , -1 , sizeof(dp));
    FOR(l , 0 , n + 1)
        FOR(r , 0 , n + 1)
            dp[l][r][0] = 0;
    FOR(r , 1 , n)
    {
        FORD(l , r , 1)
            FOR(k , 1 , val)
            {
                if(l + 2 <= r + 1 && dp[l + 2][r][k - 1] != -1)
                    dp[l][r][k] = max(dp[l][r][k] , dp[l + 2][r][k - 1] + abs(a[l] - a[l + 1]));
                if(r - 2 >= l - 1 && dp[l][r - 2][k - 1] != -1)
                    dp[l][r][k] = max(dp[l][r][k] , dp[l][r - 2][k - 1] + abs(a[r] - a[r - 1]));
                if(l + 1 <= r && dp[l + 1][r - 1][k - 1] != -1)
                    dp[l][r][k] = max(dp[l][r][k] , dp[l + 1][r - 1][k - 1] + abs(a[l] - a[r]));
                if(l + 1 <= r + 1 && dp[l + 1][r][k] != -1)
                    dp[l][r][k] = max(dp[l][r][k] , dp[l + 1][r][k]);
                if(r - 1 >= l - 1 && dp[l][r - 1][k] != -1)
                    dp[l][r][k] = max(dp[l][r][k] , dp[l][r - 1][k]);
            }
    }
    cout << dp[1][n][val];
}

