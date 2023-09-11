#include<bits/stdc++.h>
using namespace std;
#define int long long 
int q , n , x , y;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TaskB.inp", "r", stdin);
    cin >> q;
    while(q--) {
        cin >> n >> x >> y;
        int k = max(x + y - n + 1 , 1LL);
        int m = max(1LL, n - k + 1);
        if(n - x + 1 < y - k + 1) cout << n - (m - 2) << " ";
        else cout << n - (m - 1) << " ";
        m = x + y;
        k = min(x + y - 1 , n);
        if(x < k - y + 1)
            cout << -1 + k << " ";
        else
            cout << k << ' ';
        cout << endl;
    }
}