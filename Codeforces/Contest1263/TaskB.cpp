#include<bits/stdc++.h>

using namespace std;


#define fi first
#define se second
#define fr front()
#define pb push_back


#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define ll long long
#define oo 1e17
#define int long long
#define pow poww

const int N = 1e5 + 5;
int q;
string a[N];
map <string, int> cnt;

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TaskB.inp", "r", stdin);
    cin >> q;
    int n;
    while(q--) {
        int res = 0;
        cin >> n;
        cnt.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        for (int i = 1; i <= n; ++i) if(cnt[a[i]] >= 2)
        {
            cnt[a[i]]--;
            res++;
            while(1)
            {
                a[i][3]++;
                if(a[i][3] > '9')
                    a[i][3] = '0';
                if(cnt[a[i]] == 0)
                {
                    cnt[a[i]]++;
                    break;
                }
            }
        }
        cout << res <<endl;
        for (int i = 1; i <= n; ++i)
            cout << a[i] << endl;
    }
}