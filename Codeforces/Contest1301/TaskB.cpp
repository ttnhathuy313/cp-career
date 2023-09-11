#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int LOG = log2(N) + 5;
int q , n;
int a[N];
 
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TaskB.inp", "r", stdin);
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        int maxi = 0 , mini = 1e9 , res = -1;
        for (int i = 1; i < n; ++i) {
            if(a[i + 1] == -1 && ~a[i]) {
                maxi = max(maxi , a[i]);
                mini = min(mini , a[i]);
            }
            if(a[i] == -1 && ~a[i + 1])
            {
                maxi = max(maxi , a[i + 1]);
                mini = min(mini , a[i + 1]);
            }
        }
        if(maxi >= mini) {
            int k = (maxi + mini) / 2;
            for (int i = 1; i <= n; ++i)
                if (a[i] == -1)
                    a[i] = k;
            for (int i = 1; i < n; ++i)
                res = max(res , abs(a[i] - a[i + 1]));
            cout << res << " " << k << "\n";
        } else cout << "0 0\n";
    }
}