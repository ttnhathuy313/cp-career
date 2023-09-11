#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int N = 2e5 + 5;
int n, m, c[N], mark[N], cc[N], take[N], val[N];
vector <int> adj[N], tadj[N], ans;
vector <iii> EdgeList;
bool s;

void addxor(int u, int v) {
	int nu, nv;
	if (u <= n) nu = u + n;
	else nu = u - n;
	if (v <= n) nv = v + n;
	else nv = v - n;
	// cerr << u << ' ' << nv << "   ;   " << v << ' ' << nu << endl;
	adj[nu].push_back(v);
	adj[nv].push_back(u);
	adj[u].push_back(nv);
	adj[v].push_back(nu);
}

bool solve() {
	for (int i = 1; i <= 2 * n; ++i)
		adj[i].clear();
	memset(cc, 0, sizeof cc);
	memset(val, 0, sizeof val);
	for (iii d : EdgeList) {
		int u = d.second.first, v = d.second.second;
		if (d.first == 0) {
			addxor(u, v);
		} else addxor(u + n, v);
	}
	int cnt = 0;
	memset(mark, -1, sizeof mark);
	for (int i = 1; i <= 2 * n; ++i) if (mark[i] == -1) {
		queue <int> q;
		++cnt;
		while (!q.empty()) q.pop();
		q.push(i);
		mark[i] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			cc[u] = cnt;
			val[cnt] += (u <= n);
			for (int v : adj[u]) {
				if (mark[v] == -1) {
					q.push(v);
					mark[v] = mark[u] ^ 1;
				}
			}
		}
	}
	for (int i = 1; i <= cnt; ++i) tadj[i].clear();
	for (int i = 1; i <= n; ++i) {
		if (cc[i] == cc[i + n]) {
			return false;
		}
		tadj[cc[i]].push_back(cc[i + n]);
		tadj[cc[i + n]].push_back(cc[i]);
	}
	memset(take, 0, sizeof take);
	vector <int> res; res.clear();
	memset(mark, -1, sizeof mark);
	for (int i = 1; i <= cnt; ++i) if (mark[i] == -1) {
		queue <int> q;
		while (!q.empty()) q.pop();
		q.push(i);
		mark[i] = 0;
		int ff = 0, sum = 0;
		vector <int> V; V.clear();
		while (!q.empty()) {
			int u = q.front(); q.pop();
			V.push_back(u);
			sum += val[u];
			ff += mark[u] * val[u];
			for (int v : tadj[u]) {
				if (mark[v] == -1) {
					q.push(v);
					mark[v] = mark[u] ^ 1;
				} else {
					if (mark[v] != mark[u] ^ 1) {
						return false;
					}
				}
			}
		}
		if (ff > sum / 2) {
			for (int u : V) if (mark[u] == 0) take[u] = 1;
		} else for (int u : V) if (mark[u] == 1) take[u] = 1;

	}
	for (int i = 1; i <= n; ++i) if (take[cc[i]])
		res.push_back(i);
	if (res.size() == 0) {
		cout << 0 << endl;
		exit(0);
	}
	if (res.size() < ans.size() || !s) ans = res;
	return 1;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		char c;
		cin >> c;
		if (c == 'B') EdgeList.push_back({0, {u, v}});
		else EdgeList.push_back({1, {u, v}});
	}
	s |= solve();
	if (1) {
		for (iii &v : EdgeList) {
			v.first ^= 1;
		}
		s |= solve();
	}
	if (!s) {
		cout << -1 << endl;
		return 0;
	}

	cout << ans.size() << endl;
	for (int v : ans) cout << v << ' ';

	return 0;
}