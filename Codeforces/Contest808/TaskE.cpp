#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, w[N], c[N], m, n1, n2;
vector <int> g[5];

int f(int i, int tot) {
	int j = tot - 2 * i;
	return g[2][i] + g[1][min(n1, j)];
}

int solve(int tot) {
	if (tot == 1) {
		return g[1][min(n1, 1LL)];
	}
	int bound = min(tot / 2, n2);
	int l = 0, r = bound, ans = 0, idx = -1;
	// for (int i = l; i <= r; ++i) {
	// 	cerr << f(i, tot) << ' ';
	// } cerr << endl;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int curans = f(mid, tot);
		ans = max(ans, curans);
		int lans = (mid == 0 ? 0 : f(mid - 1, tot)), rans = (mid == bound ? 0 : f(mid + 1, tot));
		if (lans == curans || rans == curans || lans == rans) {
			idx = mid;
			break;
		}
		if (lans > rans) {
			r = mid - 1;
		} else l = mid + 1;
	}
	if (idx == -1) return ans;
	int target = f(idx, tot);
	l = idx, r = bound; int id = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (f(mid, tot) == target) l = mid + 1, id = mid;
		else r = mid - 1;
	}
	if (id < bound && f(id + 1, tot) > target) {
		int l = id, r = bound , idx = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			int curans = f(mid, tot);
			ans = max(ans, curans);
			int lans = (mid == 0 ? 0 : f(mid - 1, tot)), rans = (mid == bound ? 0 : f(mid + 1, tot));
			if (lans > rans) {
				r = mid - 1;
			} else l = mid + 1;
		}
		return ans;
	}
	l = 0, r = idx, id = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (f(mid, tot) == target) r = mid - 1, id = mid;
		else l = mid + 1;
	}
	l = 0, r = id, idx = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int curans = f(mid, tot);
		ans = max(ans, curans);
		int lans = (mid == 0 ? 0 : f(mid - 1, tot)), rans = (mid == bound ? 0 : f(mid + 1, tot));
		if (lans > rans) {
			r = mid - 1;
		} else l = mid + 1;
	}
	return ans;
}

void precomputation() {
	n1 = g[1].size(), n2 = g[2].size();
	for (int i = 1; i <= 3; ++i)
		sort(g[i].begin(), g[i].end());
	g[1].push_back(0); g[2].push_back(0);
	reverse(g[1].begin(), g[1].end());
	reverse(g[2].begin(), g[2].end());
	reverse(g[3].begin(), g[3].end());
	for (int i = 1; i <= n1; ++i)
		g[1][i] += g[1][i - 1];
	for (int i = 1; i <= n2; ++i)
		g[2][i] += g[2][i - 1];
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i] >> c[i];
		g[w[i]].push_back(c[i]);
	}
	precomputation();
	int cur = 0, sz = m, res = solve(m);
	for (int i = 0; i < g[3].size(); ++i) {
		cur += g[3][i];
		sz -= 3;
		if (sz < 0) break;
		res = max(res, solve(sz) + cur);
	}
	cout << res << endl;

	return 0;
}