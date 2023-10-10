#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 105;
int n, a[N], dp_sum[N][19], cnt[19], lis[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        if (c >= '2' && c <= '9') {
            a[i] = c - '0';
        } else if (c == 'A') {
            a[i] = 1;
        } else if (c == 'T') {
            a[i] = 10;
        } else if (c == 'J') {
            a[i] = 11;
        } else if (c == 'Q') {
            a[i] = 12;
        } else if (c == 'K') {
            a[i] = 13;
        }
    }
    sort(a + 1, a + 1 + n);
    int res = 0, max_lis = 0;
    dp_sum[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        int v = min(a[i], 10LL);  
        res += dp_sum[i - 1][15 -v] * 2;
        res += cnt[a[i]] * 2;
        cnt[a[i]]++;
        for (int j = 0; j <= 15; ++j) {
            dp_sum[i][j] += dp_sum[i - 1][j];
            if (j >= v) {
                dp_sum[i][j] += dp_sum[i - 1][j - v];
            }
        }
        lis[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (a[j] + 1 == a[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        max_lis = max(max_lis, lis[i]);
    }
    int cur_len = 0, cur_val = 1;
    for (int i = 1; i <= 14; ++i) {
        if (cnt[i] > 0) {
            cur_len++;
            cur_val *= cnt[i];
        } else {
            // cerr << "add at " << i << " : " << cur_val << ' ' << cur_len << endl;
            if (cur_len >= 3) res += cur_val * cur_len;
            cur_len = 0;
            cur_val = 1;
        }
    }
    cout << res << endl;

    return 0;
}