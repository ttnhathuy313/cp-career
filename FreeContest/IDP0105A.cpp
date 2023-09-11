#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5 + 5;
int n, a[N], p[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("IDP0105A.INP", "r", stdin);
	// freopen("IDP0105A.OUT", "w", stdout);

	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		p[i] = p[i - 1] + max(0LL, a[i]);
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << p[r] - p[l - 1] << endl;
	}

	return 0;
}