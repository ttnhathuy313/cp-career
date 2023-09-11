#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int a[N], n, f[N], mob[N], lst[N], cc, gud[N];
vector <int> adj[N], idx[N], primes;
bitset <N> bs;

void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	for (int i = 2; i <= N - 5; ++i) {
		for (int j = i * i; j <= N - 5; j += i) bs[j] = false;
		primes.push_back(i);
	}
}

int mobius(int a) {
	int PF_idx = 0, PF = primes[0];
	vector <int> d; d.clear();
	while (PF * PF <= a) {
		int cnt = 0;
		while (a % PF == 0) {
			a /= PF;
			cnt++;
		}
		if (cnt > 1) return 0;
		if (cnt == 1) d.push_back(PF);
		PF = primes[++PF_idx];
	}
	if (a) d.push_back(a);
	if ((int)d.size() & 1) return -1;
	else return 1;
}

int dfs(int u, int val) {
	int t = 0;
	lst[u] = cc;
	for (int v : adj[u]) if (gud[a[v]] == cc && lst[v] != cc)
		t += dfs(v, val);
	return t + 1;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.INP", "r", stdin);
	freopen("TaskG.OUT", "w", stdout);

	sieve();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		idx[a[i]].push_back(i);
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= N - 5; ++i) {
		++cc;
		int tmp = 0;
		for (int j = i; j <= N - 5; j += i) gud[j] = cc;
		for (int j = i; j <= N - 5; j += i) {
			for (int u : idx[j]) if (lst[u] != cc) {
				int sz = dfs(u, i);
				tmp += sz * (sz + 1) / 2;
			}
		}
		f[i] = tmp;
	}
	for (int i = 1; i <= N - 5; ++i)
		mob[i] = mobius(i);
	for (int i = 1; i <= N - 5; ++i) {
		int res = f[i];
		for (int j = 2; j <= (N - 5) / i; j ++)
			res += f[i * j] * mob[j];
		if (res > 0) cout << i << ' ' << res << endl;
	}

	return 0;
}