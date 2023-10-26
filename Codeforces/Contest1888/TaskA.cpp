#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int cnt[30];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; ++i) {
            cnt[s[i] - 'a']++;
        }
        int odd = 0;
        for (int i = 0; i < 30; ++i) if (cnt[i] & 1) {
            odd++;
        }
        if (odd > 1 && k == 0) {
            cout << "NO\n";
            continue;
        }
        if (k < odd - 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }

}