#include "bits/stdc++.h"
#define cerr if (1) cerr
using namespace std;
using ll = long long;
const int N = 505;
 
vector<char> v = {'E', 'W', 'S', 'N'};
vector<pair<int, int>> mv = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
 
char ch;
int r, c, m;
bitset<N> dp[5005][N], ba[N];
int s[5005];
 
int main() { cin.tie(0)->sync_with_stdio(0);
    cin >> r >> c >> m;
    for (int k = 0; k <= m; k++) for (int i = 0; i <= r; i++) {
        dp[k][i].reset();
    }
    for (int i = 1; i <= r; i++) {
        ba[i].reset();
        for (int j = 1; j <= c; j++) {
            cin >> ch;
            dp[0][i][j] = ba[i][j] = ch == '.';
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> ch;
        int j = 4;
        while (j--) if (v[j] == ch) s[i] = j;
        if (ch == '?') s[i] = 4;
    }
    for (int k = 1; k <= m; k++) {
        for (int i = 1; i <= r; i++) {
            if (s[k] == 0 || s[k] == 4) {
                dp[k][i] |= (dp[k - 1][i] << 1) & ba[i];
            }
            if (s[k] == 1 || s[k] == 4) {
                dp[k][i] |= (dp[k - 1][i] >> 1) & ba[i];
            }
            if (s[k] == 2 || s[k] == 4) {
                dp[k][i] |= dp[k - 1][i - 1] & ba[i];
            }
            if (s[k] == 3 || s[k] == 4) {
                dp[k][i] |= dp[k - 1][i + 1] & ba[i];
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cnt += dp[m][i][j];
        }
    }
    cout << cnt;
}