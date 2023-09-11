#include <bits/stdc++.h>

using namespace std; 
#define int long long

const int N = 1e6 + 5;
int a, b, q, t;
 
void solve() {
    cin >> a >> b >> q;
    int g = __gcd(a, b);
    if (a > b) {
        swap(a, b);
    }
    a /= g;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = l - r - 1;
        if ((l / b) % a == 0) ans += - l + min(r, (l / b) * b + b - 1) + 1;
        if ((r / b) % a == 0 && l / b != r / b) ans += - (r / b * b) + r + 1;
        r = r / b - 1;
        l = l / b + 1; 
        if (l <= r) {
            int v;
            if (l % a != 0) v = l + a - l % a;
            else v = l;
            ans += ((((r - (r % a)) - v) / a) + 1) * b;
        }
        ans *= -1;
        cout << ans << " ";
    }
    cout << endl;
}
    
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TaskC.inp", "r", stdin);

    cin >> t;
    while (t--) {
        solve();
    }
}