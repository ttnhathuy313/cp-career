#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define int long long 

const int N = 5005, MOD = 1e9 + 7;
int n, a[N], dp[N][N], p2[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "r", stdin);
    p2[0] = 1;
    for (int i = 1; i <= 5000; i++) p2[i] = (p2[i - 1] * 2) % MOD;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= N - 5; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i]) dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % MOD;
        }
        for (int j = 1; j < i; ++j) {
            if (a[i] + a[j] < N) dp[i][a[j] + a[i]]++;
        }
        for (int j = 0; j <= a[i]; ++j) {
            res += dp[i - 1][j] % MOD;
            res %= MOD;
        }
    }
    int total = p2[n] - n - 1 - n * (n - 1) / 2 + MOD * MOD;
    total %= MOD;
    cout << (total - res + MOD) % MOD << endl;

}