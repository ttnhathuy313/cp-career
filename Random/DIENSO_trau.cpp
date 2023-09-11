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

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define oo 1e18
#define eps 1e-8
#define pow poww
#define int long long

const int N = 1e6 + 5;
int n;
int psum[N] , ssum[N];
char f[N];

main()
{
    freopen("dienso.inp","r",stdin);
    freopen("DIENSO.ANS", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i , 1 , n)
    {
        cin >> f[i];
        if(f[i] == '<')
            psum[i] = psum[i - 1] + 1;
        else
            psum[i] = 0;
    }
    FORD(i , n , 1)
    {
        if(f[i] == '>')
            ssum[i] = ssum[i + 1] + 1;
        else
            ssum[i] = 0;
    }
    int res = 0;
    FOR(i , 1 , n + 1)
        res += max(psum[i - 1] , ssum[i]);
    cout << res;
}
