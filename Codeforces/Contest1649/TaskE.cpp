#include <bits/stdc++.h>

using namespace std;
#define int long long

struct FenwickTree {
	int n;
	vector <int> fw;
	FenwickTree() {}
	FenwickTree(int _n) {
		this -> n = _n;
		fw.assign(n + 5, 0);
	}

	void add(int id, int x) {
		while (id <= n) {
			fw[id] += x;
			id += (id & -id);
		}
	}

	int get(int id) {
		int ret = 0;
		while (id) {
			ret += fw[id];
			id -= (id & -id);
		}
		return ret;
	}

} solver;

const int N = 2e5 + 5, MOD = 998244353;
int n, m, s[N], t[N], fac[N], cnt[N];

int modPow(int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = ret * x % MOD;
		y >>= 1;
		x = x * x % MOD;
	}
	return ret;
}

int inv(int x) {
	return modPow(x, MOD - 2);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> m;
	int maxVal = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		cnt[s[i]]++;
		maxVal = max(maxVal, s[i]);
	}
	fac[0] = 1;
	for (int i = 1; i <= max(n, m); ++i) {
		fac[i] = fac[i - 1] * i % MOD;
	}
	solver = FenwickTree(N);

	for (int i = 1; i <= m; ++i) {
		cin >> t[i];
	}

	int V = 1;
	for (int i = 1; i <= maxVal; ++i) {
		solver.add(i, cnt[i]);
		V = V * fac[cnt[i]] % MOD;
	}
	V = fac[n] * inv(V) % MOD;
	int res = 0, curTot = n;
	for (int i = 1; i <= m; ++i) {
		res = res + (V * inv(curTot) % MOD) * solver.get(t[i] - 1) % MOD;
		res %= MOD;
		V = V * inv(curTot) % MOD;
		V = V * cnt[t[i]] % MOD;
		solver.add(t[i], -1);
		curTot--;
		if (cnt[t[i]] == 0) break;
		if (i == n && n < m)
			res = (res + 1) % MOD;
		cnt[t[i]]--;
	}
	cout << res % MOD << endl;

	return 0;
}