#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int dp[2][N][N], a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int n, c;
    cin >> c >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[0][c][c] = 1;
    for (int i = 1; i <= n; ++i) {
        int cur = i & 1;
        int prev = cur ^ 1;
        for (int j = 0; j <= c; ++j) {
            for (int k = 0; k <= c; ++k) {
                dp[cur][j][k] = dp[prev][j][k];
                if (j >= a[i]) dp[cur][j - a[i]][k] |= dp[prev][j][k];
                if (k >= a[i]) dp[cur][j][k - a[i]] |= dp[prev][j][k];
            }
        }
        memset(dp[prev], 0, sizeof dp[prev]);
    }
    int cur = n & 1;
    int min_sum = c + c, idx1, idx2;
    for (int j = 0; j <= c; ++j) {
        for (int k = 0; k <= c; ++k) if (dp[cur][j][k]) {
            if (min_sum == j + k) {
                if (abs(j - k) < abs(idx1 - idx2)) idx1 = j, idx2 = k;
            }
            if (min_sum > j + k) min_sum = j + k, idx1 = j, idx2 = k;
        }
    }
    if (idx1 > idx2) swap(idx1, idx2);
    cout << c - idx1 << ' ' << c - idx2 << '\n';

    return 0;
}