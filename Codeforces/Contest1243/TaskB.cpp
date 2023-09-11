#include<bits/stdc++.h>
using namespace std;

#define ii pair < int , int >
 
#define fi first
#define se second
#define fr front()
#define pb push_back
 
#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

 
const int N = 1e3 + 5;
int n, q;
int Count[N];
char pos1[N] , pos2[N];
vector <ii> res;
 
main() {
 	freopen("TaskB.inp", "r", stdin);
 	freopen("TaskB.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--)
    {
        res.clear();
        cin >> n;
        FOR(i , 1 , 256)
            Count[i] = 0;
        FOR(i , 1 , n)
        {
            cin >> pos1[i];
            Count[pos1[i]]++;
        }
        FOR(i , 1 , n)
        {
            cin >> pos2[i];
            Count[pos2[i]]++;
        }
        FOR(i , 1 , 256)
            if(Count[i] % 2 == 1)
            {
                cout << "No" << "\n";
                goto l1;
            }
        cout << "Yes" << "\n";
        FOR(i , 1 , n - 1)
        {
            int x = pos1[i];
            bool ok = false;
            for(int j = i + 1 ; j <= n ; j++)
                if(pos1[i] == pos1[j])
                {
                    res.pb(ii(j , i));
                    swap(pos2[i] , pos1[j]);
                    ok = true;
                    break;
                }
            if(!ok)
            {
                for(int j = i ; j <= n ; j++)
                    if(pos1[i] == pos2[j])
                {
                    res.pb(ii(n , j));
                    res.pb(ii(n , i));
                    swap(pos2[j] , pos1[n]);
                    swap(pos1[n] , pos2[i]);
                    break;
                }
            }
        }
        cout << res.size() << "\n";
        REP(s , res.size())
            cout << res[s].fi << " " << res[s].se << "\n";
        l1:;
    }
}