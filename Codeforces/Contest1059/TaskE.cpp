#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;
#define int long long

const int N = 1e5 + 5, LOGA = 20;
int n, L, S, l[N], s[N], w[N], Par[N][LOGA], d[N], sumW[N][LOGA], res;
vector <int> adj[N];

void dfs1(int u, int pre) {
	sumW[u][0] = w[u];
	if (pre != -1) Par[u][0] = pre, d[u] = d[pre] + 1, sumW[u][0] += w[pre];
	for (int i = 1; i < LOGA; ++i) if ((1 << i) <= d[u]) {
		Par[u][i] = Par[Par[u][i - 1]][i - 1];
		sumW[u][i] = sumW[u][i - 1] + sumW[Par[u][i - 1]][i - 1] - w[Par[u][i - 1]];
	}
	for (int k = 0; k < adj[u].size(); ++k) {
		int v = adj[u][k];
		if (v == pre) continue;
		dfs1(v, u);
	}
}

int traverse(int u, int depth) {
	int res = w[u];
	for (int i = LOGA - 1; i >= 0; --i) if ((1 << i) <= depth) {
		res += sumW[u][i];
		res -= w[u];
		u = Par[u][i];
		depth -= (1 << i);
	}
	return res;
}

void dfs(int u, int pre) {
	l[u] = -1;
	for (int k = 0; k < adj[u].size(); ++k) {
		int v = adj[u][k];
		if (v == pre) continue;
		dfs(v, u);
	}
	int nchild = 0;
	for (int k = 0; k < adj[u].size(); ++k) {
		int v = adj[u][k];
		if (v == pre) continue;
		nchild++;
		if (l[v] == 0) continue;
		int lo = 1, r = d[v], ans = -1;
		while (lo <= r) {
			int mid = (lo + r) >> 1;
			if (traverse(v, mid) - w[v] <= s[v]) lo = mid + 1, ans = mid;
			else r = mid - 1;
		}
		ans = min(ans, l[v]);
		if (ans != -1 && ans - 1 > l[u]) {
			s[u] = s[v] - w[u];
			l[u] = ans - 1;
		}
	}
	if (l[u] == -1) {
		res++;
		l[u] = L - 1;
		s[u] = S - w[u];
	}
	//cerr << "Vertex " << u << " l : " << l[u] << " rem : " << s[u] << endl;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.out", "w", stdout);

	cin >> n >> L >> S;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
		if (w[i] > S) {
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		adj[i].push_back(p);
		adj[p].push_back(i);
	}
	dfs1(1, -1);

	dfs(1, -1);
	cout << res << endl;

	return 0;
}