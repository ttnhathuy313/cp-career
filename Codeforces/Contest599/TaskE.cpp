#include <bits/stdc++.h>

/* 
 	Things to accomplish : 
 		 - Transform (mask, submask) into ternary mask for easier saving
 		 - Save the check for a (mask, submask)
 		 - Dumb check the graph
 		 - Calculate dp
*/

using namespace std;
#define int long long

const int N = 15, T = 1594325;
int dp[N][(1 << 13)], check[T], n, m, q, lca[N][N], need[N], comp[N], sz, par[N], tot[(1 << 13)], lg[(1 << 13)], local[(1 << 13)];
vector <int> adj[N], vertices, near[N];

int bi(string s) {
	reverse(s.begin(), s.end());
	int res = 0;
	for (int i = 0; i < s.size(); ++i) if (s[i] == '1')
		res += (1 << i);
	return res;
}

string show(int d) {
	string ret; ret.clear();
	while (d) {
		ret = char((d % 2) + '0') + ret;
		d /= 2;
	}
	return ret;
}


int tern(int mask, int submask) {
	int ret = 0;
	for (int i = n - 1; i >= 0; --i) {
		int cnt = 0;
		if (mask & (1 << i)) cnt++;
		if (submask & (1 << i)) cnt++;
		ret = ret * 3 + cnt;
	}
	return ret;
}

void dfs(int u) {
	comp[u] = sz;
	vertices.push_back(u);
	for (int v : adj[u]) if (!comp[v]) {
		dfs(v);
	}
}

void prepare(int u, int pre) {
	par[u] = pre;
	for (int v : adj[u]) {
		if (v == pre) continue;
		prepare(v, u);
	}
}

int dumb_lca(int u, int v) {
	vector <int> mark(n, 0);
	while (u != -1) {
		mark[u] = 1;
		u = par[u];
	}
	if (mark[v]) return v;
	while (!mark[v]) {
		v = par[v];
	}
	return v;
}

bool check_state(int mask, int submask, int root) {
	mask ^= (1 << root);
	int i = lg[mask & (-mask)];
	if (submask & (1 << i)) return true;
	else return false;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> m >> q;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= q; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		--u; --v;
		if (lca[u][v] && lca[u][v] != c) {
			cout << 0 << endl;
			return 0;
		}
		near[u].push_back(v);
		near[v].push_back(u);
		lca[u][v] = lca[v][u] = c;
	}
	for (int i = 0; i < (1 << n); ++i) {
		lg[i] = (int)log2(i);
	}
	memset(check, -1, sizeof check);
	for (int mask = 0; mask < (1 << n); ++mask) {
		bool c1 = true;
		for (int i = 0; i < n; ++i) if (mask & (1 << i)) {
			for (int j : near[i]) if (lca[i][j]) {
				if ((mask & (1 << j)) && (mask & (1 << i))) {
					if (!(mask & (1 << (lca[i][j] - 1)))) c1 = false;
				}
			}
		}
		local[mask] = c1;
	}
	for (int mask = 0; mask < (1 << n); ++mask) { // This phase has complexity is : O(n * 3 ^ n)
		memset(need, 0, sizeof need);
		if (!local[mask]) continue;		
		for (int i = 0; i < n; ++i) if (mask & (1 << i)) {
			for (int j : near[i]) if (lca[i][j]) {
				if (need[j] == 0) {
					need[j] = lca[i][j] - 1;
					continue;
				} else {
					if (lca[i][j] - 1 != need[j]) need[j] = -1;
				}
			}
		}
		int neg = (~mask) & ((1 << n) - 1);
		for (int submask = neg;; submask = (submask - 1) & neg) if (local[submask]) {
			int cur = 0;
			for (int i = 0; i < n; ++i) if (submask & (1 << i)) if (need[i]) {
				if (need[i] == -1) cur = -1;
				else {
					if (cur == 0) {
						cur = need[i];
					} else if (need[i] != cur) {
						cur = -1;
					}
				}
			}
			check[tern(neg, submask)] = cur;
			if (submask == 0) break;
		}
	}
	// Phase of dumb check and base case considering
	for (int i = 0; i < n; ++i) if (!comp[i]) {
		sz++; vertices.clear();
		dfs(i);
		int mask = 0;
		for (int v : vertices) mask |= (1 << v);
		for (int u : vertices) { // fix this as the root
			memset(par, 0, sizeof par);
			prepare(u, -1);
			bool ok = true;
			for (int x = 0; x < n; ++x) {
				for (int y = 0; y < n; ++y) if (comp[x] == sz && comp[y] == sz && lca[x][y]) {
					if (dumb_lca(x, y) != lca[x][y]) ok = false;
				}
			}
			if (ok) dp[u][mask] = 1;
		}
	} // end phase
	for (int mask = 1; mask < (1 << n); ++mask) {
		for (int submask = mask; submask; submask = (submask - 1) & mask) if (submask != mask) {
			int rem = mask ^ submask, cur = (~submask) & ((1 << n) - 1);
			int id = check[tern(cur, rem)];
			if (id == -1) continue;
			if (id) {
				if (check_state(mask, submask, id) && (submask & (1 << id)) == 0) {
					// if (mask == 14 && id == 1) cerr << show(submask) << ' ' << tot[submask] << endl;
					dp[id][mask] += dp[id][rem] * tot[submask];
				}
			} else {
				for (int i = 0; i < n; ++i) if (mask & (1 << i)) if ((submask & (1 << i)) == 0) {
					if (check_state(mask, submask, i)) {
						if (mask == 7 && id == 0) cerr << show(submask) << ' ' << tot[submask] << ' ' << show(rem) << ' ' << dp[i][rem] << endl;
						dp[i][mask] += dp[i][rem] * tot[submask];
					}
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			cerr << "dp[" << i << "][" << show(mask) << "] : " << dp[i][mask] << endl;
			tot[mask] = tot[mask] + dp[i][mask];
		}
	}
	cout << dp[0][(1 << n) - 1] << endl;

	return 0;
}