#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5e5 + 5, MOD = 1e9 + 7;
int n, m, k[N], mark[N], basis[N], mask[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.ANS", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		for (int j = 0; j < k[i]; ++j) {
			int x;
			cin >> x; x--;
			mask[i] |= (1 << x);
		}
	}
	vector <int> id; id.clear();
	for (int i = 1; i <= n; ++i) {
		int msk = mask[i];
		for (int j = 0; j < m; ++j) if (msk & (1 << j)) {
			if (!basis[j]) {
				basis[j] = msk;
				id.push_back(i);
				break;
			}
			msk ^= basis[j];
		}
	}
	int res = 1;
	for (int i = 0; i < id.size(); ++i) {
		res = res * 2;
		res %= MOD;
	}
	cout << res << ' ' << id.size() << endl;
	for (int v : id) cout << v << ' ';

	return 0;
}