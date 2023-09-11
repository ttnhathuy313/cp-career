#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 505 >> 1, M = 1e6 + 5, MOD = 998244353;
int n, m, c[M], lst[N], f[N][N], head[N], tail[N];
vector <int> pos[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		cin >> c[i];
	m = unique(c + 1, c + 1 + m) - c - 1;
	if (m > 2 * n) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= m; ++i) {
		if (!lst[c[i]]) {
			head[c[i]] = i;
		}
		pos[c[i]].push_back(i);
		lst[c[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		tail[i] = lst[i];
		// cerr << "Color " << i << " begins at " << head[i] << " and ends at " << tail[i] << endl;
	}
	for (int i = 0; i <= m; ++i)
		f[i + 1][i] = 1;
	for (int len = 1; len <= m; ++len) {
		for (int L = 1; L <= m - len + 1; ++L) {
			int R = L + len - 1;
			int v = M;
			for (int i = L; i <= R; ++i) v = min(v, c[i]);
			if (!(L <= head[v] && tail[v] <= R)) continue;
			int left, right; left = right = 0;
			for (int rr = tail[v]; rr <= R; ++rr) {
				if (c[rr] < v) continue;
				right = (right + (f[tail[v] + 1][rr] * f[rr + 1][R]) % MOD) % MOD;
			}
			for (int ll = head[v]; ll >= L; --ll) {
				if (c[ll] < v) continue;
				left = (left + (f[ll][head[v] - 1] * f[L][ll - 1]) % MOD) % MOD;
			}
			f[L][R] = left * right % MOD;
			for (int i = 1; i < pos[v].size(); ++i) {
				f[L][R] = (f[L][R] * f[pos[v][i - 1] + 1][pos[v][i] - 1]) % MOD;
			}
		}
	}
	cout << f[1][m] << endl;

	return 0;
}