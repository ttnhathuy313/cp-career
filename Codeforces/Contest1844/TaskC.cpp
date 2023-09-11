#include <iostream>

using namespace std;
#define int long long

const int N = 2e5 + 5, oo = 1e18;
int n, dp[N][2], c[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
            dp[i][0] = dp[i][1] = -oo;
        }
        dp[0][0] = dp[0][1] = -oo;
        int res = -oo;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = max(dp[i - 1][1], c[i]);
            if (~dp[i - 1][1])
                dp[i][0] = max(dp[i][0], dp[i - 1][1] + c[i]);
            dp[i][1] = dp[i - 1][0];
            res = max(res, dp[i][0]);
        }
        cout << res << endl;
    }
}