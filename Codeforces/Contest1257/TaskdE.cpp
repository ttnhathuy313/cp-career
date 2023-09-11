#include<bits/stdc++.h>
using namespace std;

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define abcxyz(i , x , n) for(int i = x ; i >= n ; --i)
#define REP(i , x) for(int i = 0 ; i < x ; ++i)

#define ll long long
#define inf 1e9

const int N = 2e5 + 5;
const int lOgArIt = log2(N + 1333) + 2;
int n , m , k , ans , res1;
int a[N + 6969] , b[N] , c[N] , prefix[N] , result[N];
int concac1[N + 123] , dem[N] , cnt2[N];


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("task.inp","r",stdin);
    cin >> n >> m >> k;
    FOR(i , 1 , n)
    {
        cin >> a[i];
        concac1[a[i]]++;
    }
    FOR(i , 1 , m)
    {
        cin >> b[i];
        cnt2[b[i]]++;
    }
    FOR(i , 1 , k)
    {
        cin >> c[i];
        dem[c[i]]++;
    }
    int y = 0;
    int x = n + m + k;
    int z = n;
    result[x + 1] = k;
    abcxyz(i , x , 1)
    {
        if(dem[i] == 1)
            k--;
        else if(concac1[i] == 0)
            y++;
        result[i] = min(result[i + 1] , k + y);
    }


    ans = inf;
    FOR(i , 0 , x)
    {
        if(concac1[i] == 0 && i != 0 && dem[i] == 0)
            res1++;
        if(concac1[i] == 1)
            z--;
        ans = min(ans , res1 + z + result[i + 1]);
    }
    cout << ans;
}