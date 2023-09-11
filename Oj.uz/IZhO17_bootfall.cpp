#include <bits/stdc++.h>

using namespace std;

const int N = 505, MOD = 1e9 + 7;
int dp[N * N], cnt[N * N], a[N], n, tmp[N * N], h2[N * N], t2[N * N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("IZhO17_bootfall.INP", "r", stdin);
	// freopen("IZhO17_bootfall.OUT", "w", stdout);

	cin >> n;
	int s = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s += a[i];
	}
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = s; j >= 0; --j) if (a[i] <= j) {
			dp[j] += dp[j - a[i]];
		}
	}
	h2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = s; j >= 0; --j) if (a[i] <= j) {
			(h2[j] += h2[j - a[i]]) %= MOD;
		}
	}
	if (s & 1) {
		cout << 0 << endl;
		return 0;
	}
	if (dp[s / 2] == 0 && h2[s / 2] == 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= s; ++j) tmp[j] = dp[j];
		tmp[a[i]]--;
		for (int j = a[i] + 1; j <= s; ++j)
			tmp[j] -= tmp[j - a[i]];
		for (int j = 0; j <= s; ++j) t2[j] = h2[j];
		t2[a[i]] = (t2[a[i]] - 1 + MOD) % MOD;
		for (int j = a[i] + 1; j <= s; ++j)
			t2[j] = (t2[j] - t2[j - a[i]] + MOD) % MOD;
		s -= a[i];
		// if (i == 3) cerr << "#" << (s - 155) / 2 << endl;
		for (int j = 0; j <= s / 2; ++j) if (tmp[j] != 0 && t2[j] != 0) {
			// if (s - 2 * j == 155) cerr << i << endl;
			cnt[s - 2 * j]++;
		}
		s += a[i];
	}
	vector <int> res; res.clear();
	for (int i = 1; i <= s; ++i) if (cnt[i] == n)
		res.push_back(i);
	cout << res.size() << endl;
	for (int v : res) cout << v << ' ';

	return 0;
}