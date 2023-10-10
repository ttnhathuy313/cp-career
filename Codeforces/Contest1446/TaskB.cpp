#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5005, oo = 1e9;
string a, b;
int n, m, dp[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    cin >> n >> m;
    cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j)
            for (int k = 0; k < 2; ++k) {
                dp[i][j] = -oo;
            }
    }

    int res = 0;

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == b[j]) {
                dp[i][j] = max(dp[i][j], 2);
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j] - 1);
            dp[i][j] = max(dp[i][j], dp[i][j - 1] - 1);
            res = max(res, dp[i][j]);
        }
    }

    cout << res << endl;

    return 0;
}