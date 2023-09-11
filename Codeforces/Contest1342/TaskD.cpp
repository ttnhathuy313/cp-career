#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, oo = 1e18;
int n, m, a[N], p[N], b[N];
multiset <int> s;
vector <int> ans[N];

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);
	cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s.insert(a[i]);
    }
    p[0] = oo;
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    	p[i] = p[i - 1];
        p[i] = min(p[i] , b[i]);
    }
    int nn = max(n, m);
    for (int i = 1; i <= nn; ++i) {
        int pre = m;
        for (int j = 1; j <= nn; ++j) {
            int l = 1, r = pre;
            auto res = s.end();
            while (l <= r) {
                int mid = (l + r) >> 1, k = mid;
                auto it = s.lower_bound(mid);
                if (it != s.end()) {
                    mid = *(it);
                    if (mid <= r) {
                        if (p[mid] - j >= 0)
                            l = mid + 1, res = it;
                        else r = mid - 1;
                    } else r = k - 1;
                } else r = k - 1;
            }
            if (res == s.end()) break;
            int u = *res;
            s.erase(res);
            pre = u;
            ans[i].push_back(u);
        }
        if (s.size() == 0) {
            cout << i << "\n";
            for (int j = 1; j <= i; ++j) {
                cout << ans[j].size() << " ";
                for (int v : ans[j]) cout << v << ' ';
                cout << "\n";
            }
            return 0;
        }
    }
    return 0;
}