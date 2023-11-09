#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;
#define int long long 

const int N = 3005;
int dp_l[N][N], dp_r[N][N], n, k, ans[N];
string s;

struct CHT {
    // convex hull trick for increasing positive slope, to find maximum ax + b

    vector <pair <int, int>> lines;
    CHT() {
        lines.clear();
    }
    
    void add_line(int a, int b) {
        while (lines.size() >= 2) {
            int x1 = lines[lines.size() - 2].first;
            int y1 = lines[lines.size() - 2].second;
            int x2 = lines[lines.size() - 1].first;
            int y2 = lines[lines.size() - 1].second;
            if ((y2 - y1) * (x1 - a) >= (b - y1) * (x1 - x2)) {
                lines.pop_back();
            } else {
                break;
            }
        }
        lines.push_back({a, b});
    }
    int query(int x) {
        int l = 0, r = lines.size() - 1;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int value_left = lines[mid].first * x + lines[mid].second;
            int value_right = (mid == lines.size() - 1 ? -1e18 : lines[mid + 1].first * x + lines[mid + 1].second);
            ans = max(ans, value_left);
            ans = max(ans, value_right);
            if (value_left <= value_right) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

};

void calc() {
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= k + 1; ++j) {
            dp_l[i][j] = dp_r[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= min(i, k); ++j) {
            if (s[i - 1] == '0') {
                dp_l[i][j] = max(dp_l[i - 1][j] + 1, 1LL);
            } else {
                if (j > 0) dp_l[i][j] = dp_l[i - 1][j - 1] + 1;
            }
        }
    }


    for (int i = n; i >= 1; --i) {
        for (int j = 0; j <= min(n - i + 1, k); ++j) {
            if (s[i - 1] == '1') {
                dp_r[i][j] = max(dp_r[i + 1][j] + 1, 1LL);
            } else {
                if (j > 0) dp_r[i][j] = dp_r[i + 1][j - 1] + 1;
            }
        }
    }


    vector <pair <int, int>> lines;
    vector <int> coeff(n + 4, -1);

    for (int i = n; i >= 0; --i) {
        for (int j = 0; j <= k; ++j) {
            dp_r[i][j] = max(dp_r[i][j], dp_r[i + 1][j]);
            if (j > 0) dp_r[i][j] = max(dp_r[i][j], dp_r[i][j - 1]);
        }
        for (int j = 0; j <= min(i, k); ++j) {
            coeff[dp_l[i][j]] = max(coeff[dp_l[i][j]], dp_r[i + 1][k - j]);
        }
    }
    CHT cht;
    for (int i = 0; i <= n; ++i) if (~coeff[i]) {
        cht.add_line(i, coeff[i]);
    }
    // for (auto line : cht.lines) {
    //     cout << line.first << " " << line.second << endl;
    // }
    // cerr << "!!!!" << endl;
    for (int i = 1; i <= n; ++i) {
        ans[i] = max(ans[i], cht.query(i));
    }
}

void solve() {
    cin >> n >> k >> s;
    for (int i = 1; i <= n; ++i) {
        ans[i] = -1;
    }
    calc();
    reverse(s.begin(), s.end());
    calc();
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}