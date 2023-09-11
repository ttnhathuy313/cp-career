#include <bits/stdc++.h>

using namespace std;
typedef pair <long double, long double> ii;
typedef pair <long double, ii> iii;

const long long N = 1005, oo = 1e18;
long double n, m, O[N], dist[N], mark[N];
vector <ii> adj[N];
vector <iii> E;

bool check(long double T) {
	for (int i = 0; i <= n; ++i) {
		adj[i].clear();
	}
	for (iii e : E) {
		long double w = e.first;int u = e.second.first, v = e.second.second;
		adj[v].push_back({T - w, u});
	}
	for (int i = 1; i <= n; ++i) {
		dist[i] = O[i];
	}
	memset(mark, 0, sizeof mark);
	for (int times = 0; times < n; ++times) {
		long double dis = oo + 8;
		int u = -1;
		for (int i = 1; i <= n; ++i) if (!mark[i] && dist[i] < dis) {
			dis = dist[i];
			u = i;
		}
		if (u == -1) break;
		mark[u] = 1;
		for (ii d : adj[u]) {
			long double w = d.first;int v = d.second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
			}
		}
	}
	for (iii e : E) {
		int u = e.second.first;int v = e.second.second;
		long double w = T - e.first;
		if (dist[v] + w < dist[u]) {
			return false;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (dist[i] != O[i] && O[i] != (long double)1e9) return false;
		if (abs(dist[i]) > 1e9) return false;
	}
	return true;
}

void solve() {
	E.clear();
	memset(O, 0, sizeof O);
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;
		long double val = 0;
		if (s == "?") {
			O[i] = (long double)1e9;
			continue;
		}
		for (int j = 0; j < s.size(); ++j)
			val = val * 10 + s[j] - '0';
		O[i] = val;
	}
	for (int i = 1; i <= m; ++i) {
		long double u, v, c;
		cin >> u >> v >> c;
		E.push_back({c, {u, v}});
	}
	long double l = 0, r = (long double)1e9, ans = -1, cnt = 120;
	while (cnt--) {
		long double mid = (l + r) / 2;
		if (check(mid)) r = mid, ans = mid;
		else l = mid;
	}
	cout<< fixed << setprecision(9) << ans << endl;
	check(ans);
	for (int i = 1; i <= n; ++i)
		cout << fixed << setprecision(9) << dist[i] << ' ';
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("BerlandPost.INP", "r", stdin);
	freopen("BerlandPost.OUT", "w", stdout);

	while (cin >> n >> m) {
		solve();
	}

	return 0;
}