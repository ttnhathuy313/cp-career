#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
int cnt[N][27];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    for (int i = 1; i <= n; ++i) {
        cnt[i][s[i] - 'A']++;
        for (int j = 0; j < 26; ++j) {
            cnt[i][j] += cnt[i - 1][j];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        vector <char> v = {'A', 'T', 'G', 'C'};
        vector <pair <int, int>> res;
        for (int i = 0; i < 4; ++i) {
            res.push_back({-cnt[r][v[i] - 'A'] + cnt[l - 1][v[i] - 'A'], i});
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < 4; ++i) {
            cout << v[res[i].second];
        }
        cout << endl;
    }


    return 0;
}