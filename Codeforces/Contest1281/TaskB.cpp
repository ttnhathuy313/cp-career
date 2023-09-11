#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int q, n, m, cnt[N];
char f1[N] , f2[N];
 
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TaskB.inp", "r", stdin);
    freopen("TaskB.out", "w", stdout);
    cin >> q;
    while(q--)
    {
        cin >> f1 >> f2;
        int n = strlen(f1);
        int m = strlen(f2);
        for (int i = 'A'; i <= 'Z'; ++i)
            cnt[i] = 0;
        int u = 0 , v = 0;
       	for (int i = 0; i < n; ++i) cnt[f1[i]]++;
        for (int i = 0; i < n; ++i) {
        	bool out1 = false;
            for (int j = 'A'; j <= 'Z'; ++j)
                if (cnt[j] != 0) {
                    if(j == f1[i]) {
                        cnt[j]--;
                        break;
                    } else {
                        u = j;
                        v = i;
                       	out1 = true;
                       	break;
                    }
                }
            if (out1) break;
        }
        for(int i = n - 1; i >= v + 1; --i)
            if(f1[i] == u) {
                swap(f1[i] , f1[v]);
                break;
            }
        bool ok = false;
        bool ok1 = false;
        for (int i = 0; i < n; ++i)
        {
            if(i < m)
            {
                if(f1[i] < f2[i])
                {
                    ok = true;
                    break;
                }
                if(f1[i] > f2[i])
                {
                    ok1 = true;
                    break;
                }
            } else {
                ok1 = true;
                break;
            }
        }
        if(ok || (!ok1 && m > n))
            cout << f1 << "\n";
        else
            cout << "---" << "\n";
    }
}