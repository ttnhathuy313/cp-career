#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 1, logg = 60;

int t, a[N], dp[1 << 6], LOG[N];

int32_t main() { 
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.inp", "r", stdin);
      cin >> t;
    for (int i = 1; i < N; ++i) {
        if (i & 1) {
            LOG[i] = LOG[i - 1];
        } else {
            LOG[i] = LOG[i / 2] + 1;
        }
    }
    while(t--) {
        int n, m, cant_merge = 0, ans = 0;
        cin >> m >> n;
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] <= 1e5) {
                dp[LOG[a[i]]]++;
            } else {
                int log = log2(a[i]);
                dp[log]++;
            }
        }
        for (int bit = 0; bit <= logg; bit++) {
            // merge lower bit to form annoying greedy
            if ((m >> bit) & 1) {
                int trace = -1, pre;
                for (int k = 1; k <= bit; k++) {
                    pre = dp[k - 1] >> 1;
                    dp[k] += pre;
                    dp[k - 1] -= pre << 1;
                }
                if (dp[bit]) {
                    dp[bit]--;
                    continue;
                }
                for (int k = bit; k <= logg; k++) {
                    if (dp[k]) {
                        trace = k;
                        break;
                    }
                }
                while  (trace == -1) {
                    cant_merge = 1;
                    break;
                }
                dp[bit]--;
                for (int k = trace; k > bit; k--) {
                    dp[k - 1] += 2;
                    dp[k]--;
                    ans++;
                }
            }
        }
        if (cant_merge) cout << -1 << endl;
        else cout << ans << endl;
    }
}