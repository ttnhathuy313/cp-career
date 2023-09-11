#include <bits/stdc++.h>

using namespace std;

const int N = 305, MOD = 998244353;
int dp[N][N * 2], l[N], r[N], n, fac[N], C[N][2 * N], ll[N], rr[N];

int modPow(int x, int y) {
	x %= MOD;
	int ret = 1;
	while (y) {
		if (y & 1) ret = 1LL * ret * x % MOD;
		x = 1LL * x * x % MOD;
		y >>= 1;
	}
	return ret;
}

class IncreasingSequences {
	public : 
	int count(vector <int> L, vector <int> R) {
	vector <int> segs;
	segs.clear();
	n = L.size();
	int ml = MOD;
	for (int i = 1; i <= n; ++i) {
		l[i] = L[i - 1], r[i] = R[i - 1];
		segs.push_back(l[i]);
		segs.push_back(r[i] + 1);
		ml = min(ml, l[i]);
	}
	segs.push_back(0);
	sort(segs.begin(), segs.end());
	segs.resize(unique(segs.begin(), segs.end()) - segs.begin());
	vector <int> lens; lens.clear();
	for (int i = 0; i < segs.size() - 1; ++i) {
		lens.push_back(segs[i + 1] - segs[i]);
	}
	sort(lens.begin(), lens.end());
	lens.resize(unique(lens.begin(), lens.end()) - lens.begin());
	for (int i = 0; i < lens.size(); ++i) {
		int v = lens[i];
		for (int j = 0; j <= n; ++j) {
			if (j > v) continue;
			C[j][i] = 1;
			int fac = 1;
			for (int k = 0; k < j; ++k) {
				fac = (1LL * fac * (k + 1)) % MOD;
				C[j][i] = (1LL * C[j][i] * (v - k)) % MOD;
			}
			C[j][i] = (1LL * C[j][i] * modPow(fac, MOD - 2)) % MOD;
		}
	}
	for (int i = 0; i <= 2 * n; ++i) dp[0][i] = 1;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		int id = lower_bound(segs.begin(), segs.end(), l[i]) - segs.begin();
		int ed = lower_bound(segs.begin(), segs.end(), r[i] + 1) - segs.begin() - 1;
		ll[i] = id, rr[i] = ed;
		for (int j = id; j <= ed; ++j) {
			if (j != id) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
			int block_id = lower_bound(lens.begin(), lens.end(), segs[j + 1] - segs[j]) - lens.begin();
			for (int k = i; k >= 1; --k) if (ll[k] <= j && rr[k] >= j) {
				dp[i][j] = (1LL * dp[k - 1][j - 1] * C[i - k + 1][block_id] % MOD + dp[i][j]) % MOD;
			} else break;
			if (j == ed && i == n) res = dp[i][j];
			// cerr << "dp[" << i << "][" << j << "] : " << dp[i][j] << endl;
		}
		for (int j = ed + 1; j < 2 * n; ++j) dp[i][j] = dp[i][j - 1];
	}
	return res;
	}
};

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("500div1.INP", "r", stdin);
	freopen("500div1.OUT", "w", stdout);

	vector <int> segs;
	segs.clear();
	cin >> n;
	int ml = MOD;
	for (int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
		segs.push_back(l[i]);
		segs.push_back(r[i] + 1);
		ml = min(ml, l[i]);
	}
	segs.push_back(0);
	sort(segs.begin(), segs.end());
	segs.resize(unique(segs.begin(), segs.end()) - segs.begin());
	vector <int> lens; lens.clear();
	for (int i = 0; i < segs.size() - 1; ++i) {
		lens.push_back(segs[i + 1] - segs[i]);
	}
	sort(lens.begin(), lens.end());
	lens.resize(unique(lens.begin(), lens.end()) - lens.begin());
	for (int i = 0; i < lens.size(); ++i) {
		int v = lens[i];
		for (int j = 0; j <= n; ++j) {
			if (j > v) continue;
			C[j][i] = 1;
			int fac = 1;
			for (int k = 0; k < j; ++k) {
				fac = (1LL * fac * (k + 1)) % MOD;
				C[j][i] = (1LL * C[j][i] * (v - k)) % MOD;
			}
			C[j][i] = (1LL * C[j][i] * modPow(fac, MOD - 2)) % MOD;
		}
	}
	for (int i = 0; i <= 2 * n; ++i) dp[0][i] = 1;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		int id = lower_bound(segs.begin(), segs.end(), l[i]) - segs.begin();
		int ed = lower_bound(segs.begin(), segs.end(), r[i] + 1) - segs.begin() - 1;
		ll[i] = id, rr[i] = ed;
		for (int j = id; j <= ed; ++j) {
			if (j != id) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
			int block_id = lower_bound(lens.begin(), lens.end(), segs[j + 1] - segs[j]) - lens.begin();
			for (int k = i; k >= 1; --k) if (ll[k] <= j && rr[k] >= j) {
				dp[i][j] = (1LL * dp[k - 1][j - 1] * C[i - k + 1][block_id] % MOD + dp[i][j]) % MOD;
			} else break;
			if (j == ed && i == n) res = dp[i][j];
			// cerr << "dp[" << i << "][" << j << "] : " << dp[i][j] << endl;
		}
		for (int j = ed + 1; j < 2 * n; ++j) dp[i][j] = dp[i][j - 1];
	}
	cout << res << endl;

	return 0;
}