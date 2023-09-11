#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int n, k;
char s[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    sort(s + 1, s + n + 1);
    set <char> sc;
    for (int i = 1; i <= k; i++) {
        sc.insert(s[i]);
    }
    if (sc.size() != 1) {
    	set <char>::iterator it = sc.end();
    	it--;
        cout << *it << endl;
        return;
    }
    string ans;
    ans = ans + s[k];
    int i = k; ++i;
    while (k != n) {
        sc.clear();
        int lim = min(i + k - 1, n);
        while (i <= lim) {
            sc.insert(s[i]);
        	i++;
        }

    	set <char>::iterator it = sc.end();
        --it;
        ans += *it;
        if (i == n + 1) {
            break;
        }
    }
    string ra = ans;
    ans.clear();
    for (int i = k; i <= n; i++) {
        ans += s[i];
    }
    cout << min(ra, ans) << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}