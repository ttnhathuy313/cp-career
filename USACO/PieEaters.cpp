#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e6 + 5, INF = 1e9 + 7;
int pref1[N], pref2[N], e[N], g[N], x[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, i, j, k, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> g[i] >> e[i];
        ans = max(ans, g[i]);
        pref1[i] = pref1[i - 1] + e[i];
        pref2[i] = pref2[i - 1] + g[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = n; j >= i; --j) {
            if (ans >= pref2[j] - pref2[i - 1]) break;
            int z = x[j] - x[i], c = pref1[j] - pref1[i - 1];
            if (z <= c){
                ans = pref2[j] - pref2[i - 1];
            }
        }
    }
    cout << ans << endl;
    return 0;

}