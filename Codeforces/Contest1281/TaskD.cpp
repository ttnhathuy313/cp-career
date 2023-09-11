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
#define oo 1e9
#define pow poww

const int N = 1e2 + 5;
int q;
int n , m;
char f[N][N];

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("task.inp","r",stdin);
    cin >> q;
    while(q--)
    {
        cin >> n >> m;
        bool ok = false;
        bool ok1 = false;
        FOR(i , 1 , n)
            FOR(j , 1 , m)
            {
                cin >> f[i][j];
                if(f[i][j] == 'A')
                    ok = true;
                if(f[i][j] == 'P')
                    ok1 = true;
            }
        if(!ok)
            cout << "MORTAL" << "\n";
        else
        {
            int res = 4;
            if(!ok1)
                res = 0;
            FOR(i , 1 , n)
            {
                bool ok = true;
                FOR(j , 1 , m)
                {
                    if(f[i][j] == 'P')
                        ok = false;
                    else if(i == 1 || i == n)
                        res = min(res , 3);
                }
                if(ok)
                {
                    if(i == 1 || i == n)
                        res = min(res , 1);
                    else
                        res = min(res , 2);
                }
            }
            FOR(i , 1 , m)
            {
                bool ok = true;
                FOR(j , 1 , n)
                {
                    if(f[j][i] == 'P')
                        ok = false;
                    else if(i == 1 || i == m)
                        res = min(res , 3);
                }
                if(ok)
                {
                    if(i == 1 || i == m)
                        res = min(res , 1);
                    else
                        res = min(res , 2);
                }
            }
            if(f[1][1] == 'A' || f[1][m] == 'A' || f[n][m] == 'A' || f[n][1] == 'A')
                res = min(res , 2);
            cout << res << "\n";
        }
    }
}