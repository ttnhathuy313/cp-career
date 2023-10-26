#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> d(2*1005+1, vector<int>(1005+1, 0));

string kth_balanced(int n, int k) {

    string ans;
    int depth = 0;
    for (int i = 0; i < 2*n; i++) {
        if (depth + 1 <= n && d[2*n-i-1][depth+1] >= k) {
            ans += '(';
            depth++;
        } else {
            ans += ')';
            if (depth + 1 <= n)
                k -= d[2*n-i-1][depth+1];
            depth--;
        }
    }
    return ans;
}

int p[1005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "r", stdin);

    int n = 1000;
    d[0][0] = 1;
    for (int i = 1; i <= 2*n; i++) {
        d[i][0] = d[i-1][1];
        for (int j = 1; j < n; j++)
            d[i][j] = d[i-1][j-1] + d[i-1][j+1];
        d[i][n] = d[i-1][n-1];
    }

    int type;
    while (cin >> type) {
        if (type == 1) {
            int n, k;
            cin >> n >> k;
            string s = kth_balanced(n, k);
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '(') {
                    cout << i + 1 << " ";
                }
            }
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ')') {
                    cout << i + 1 << " ";
                }
            }
            cout << endl;
        } else {
            int n;
            cin >> n;
            string s = "";
            for (int i = 1; i <= 2 * n; ++i) {
                cin >> p[i];
                s += ")";
            }
            for (int i = 1; i <= n; ++i) {
                s[p[i] - 1] = '(';
            }
            int depth = 0, res = 0;
            for (int i = 0; i < 2 * n; ++i) {
                if (s[i] == '(') {
                    depth++;
                } else {
                    res += d[2 * n - i - 1][depth + 1];
                    depth--;
                }
            }
            cout << res + 1 << endl;
        }
    }
}