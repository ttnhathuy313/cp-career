#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 105, oo = 1e9;
int a[N], b[N], prime[10005], suf[N], n, dp[N][(1 << 10)], realid[N], ans[N], ip[10005];
vector <int> cost[(1 << 10)];
ii trace[N][(1 << 10)];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n;
	vector <ii> A; A.clear();
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = a[i];
		A.push_back({a[i], i});
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < n; ++i) {
		a[i + 1] = A[i].first;
		realid[i + 1] = A[i].second;
	}
	int id = 0;
	for (int i = 2; i <= 1000; ++i) {
		for (int j = 2; j <= sqrt(i); ++j) if (i % j == 0) goto label;
		prime[++id] = i;
		ip[i] = id;
		label:;
	}
	memset(suf, 0, sizeof suf);
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			suf[i] += abs(prime[11 + j - i] - a[j]);
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int mask = 0; mask < (1 << 10); ++mask) dp[i][mask] = oo;
	}
	for (int i = 1; i <= 100; ++i) {
		int mask = 0;
		bool ok = true;
		for (int j = 2; j <= i; ++j) if (i % j == 0 && ip[j]) {
			if (ip[j] <= 10) mask |= (1 << (ip[j] - 1));
			else ok = false;
		}
		if (!ok) continue;
		cost[mask].push_back(i);
	}
	dp[0][(1 << 10) - 1] = 0; // pos, available
	for (int i = 0; i < n; ++i) {
		for (int mask = 0; mask < (1 << 10); ++mask) if (dp[i][mask] != oo) {
			for (int submask = mask; ; submask = (submask - 1) & mask) {
				for (int v : cost[submask]) {
					if (dp[i + 1][mask ^ submask] > dp[i][mask] + abs(v - a[i + 1])) {
						dp[i + 1][mask ^ submask] = dp[i][mask] + abs(v - a[i + 1]);
						trace[i + 1][mask ^ submask] = {mask, v};
					}
				}
				if (submask == 0) break;
			}
		}
	}
	int res = oo, pos = -1;
	ii mem;
	for (int i = 1; i <= n; ++i) {
		for (int mask = 0; mask < (1 << 10); ++mask) {
			if (res > dp[i][mask] + suf[i + 1]) {
				res = dp[i][mask] + suf[i + 1];
				mem = {i, mask};
				pos = i;
			}
		}
	}
	cerr << mem.first << ' ' << mem.second << endl;
	int cur = mem.second;
	while (pos) {
		int v = trace[pos][cur].second;
		ans[realid[pos]] = v;
		cur = trace[pos][cur].first;
		pos--;
	}
	for (int i = mem.first + 1; i <= n; ++i) {
		ans[realid[i]] = prime[10 + i - mem.first];
	}
	int tot = 0;
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
		tot += abs(ans[i] - b[i]);
	}
	cerr << tot << endl;

	return 0;
}