#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2005;
int n, comp[N], scc_count, scc_size[N], tin[N], low[N], dfsTime, mark[N], dp[N], trace[N], graph[N][N], already[N], mark2[N], found;
vector <int> adj[N], dag[N], topo, V[N], circuit[N], cyc;
stack <int> st;

void get_any(int u, int id) {
	mark2[u] = id;
	cyc.push_back(u);
	for (int v : adj[u]) if (mark2[v] != id) {
		if (!found) get_any(v, id);
	} else if (already[v] != id) found = true;
	already[u] = id;
	if (!found) cyc.pop_back();
}

void find_path(int id) {
	if (V[id].size() == 1) {
		circuit[id].push_back(V[id][0]);
		return;
	}
	get_any(V[id][0], id);
	// for (int v : cyc) cerr << v << ' '; cerr << endl;
	set <int> VV; VV.clear();
	for (int v : V[id]) VV.insert(v);
	V[id].clear();
	for (int v : cyc) VV.erase(v);
	for (int v : cyc) V[id].push_back(v), circuit[id].push_back(v);
	for (int v : VV) V[id].push_back(v);
	// for (int v : V[id]) cerr << v << ' '; cerr << endl;
	if (cyc.size() != V[id].size()) for (auto it = V[id].begin() + (int)cyc.size(); it != V[id].end(); ++it) {
		bool h0, h1; h0 = h1 = false;
		for (auto jt = V[id].begin(); jt != it; ++jt) {
			if (graph[*it][*jt] == 0) h0 = 1;
			else h1 = 1;
		}
		if (h0 && h1) {
			continue;
		} else {
			V[id].push_back(*it);
			V[id].erase(it);
			it--;
		}
	}
	for (int i = (int)cyc.size(); i < V[id].size(); ++i) {
		int u = V[id][i], cnt = 0;
		// cerr << u << endl;
		// for (int v : circuit[id]) cerr << v << ' '; cerr << endl;
		bool ok = false;
		for (auto it = circuit[id].begin(); it != circuit[id].end(); ++it) {
			auto nit = ++it; it--;
			if (nit == circuit[id].end()) break;
			int x = *it, y = *nit;
			if (graph[u][x] != graph[u][y]) {
				cnt++;
				if (!graph[u][x]) {
					circuit[id].insert(nit, u);
					ok = true;
					break;
				}
			}
		}
	}

}

void dfs(int u, int pre) {
	tin[u] = low[u] = ++dfsTime;
	st.push(u);
	mark[u] = 1;
	for (int v : adj[u]) {
		if (v == pre) continue;
		if (!tin[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		} else if (mark[v] == 1) low[u] = min(low[u], tin[v]);
	}
	if (low[u] == tin[u]) {
		scc_count++;
		while (st.top() != u) {
			int v = st.top(); st.pop();
			scc_size[scc_count]++;
			V[scc_count].push_back(v);
			comp[v] = scc_count;
			mark[v] = 2;
		}
		V[scc_count].push_back(u);
		mark[u] = 2;
		st.pop();
		scc_size[scc_count]++;
		comp[u] = scc_count;
		find_path(scc_count);
		// cerr << "Scc no" << scc_count << " includes : ";
		// for (int v : circuit[scc_count]) cerr << v << ' '; cerr << endl;
	}
}

void dfs_topo(int u) {
	mark[u] = 1;
	for (int v : dag[u]) if (!mark[v])
		dfs_topo(v);
	topo.push_back(u);
}

vector <int> gotrace(int u, int fi) {
	vector <int> D;
	D.clear();
	if (~trace[u]) D = gotrace(trace[u], circuit[trace[u]][0]);
	vector <int> ret; ret.clear();
	bool ok = false;
	for (int v : circuit[u]) {
		if (v == fi) ok = true; 
		if (ok) ret.push_back(v);
	}
	for (int v : circuit[u]) {
		if (v == fi) break;
		ret.push_back(v);
	}
	for (int v : D) ret.push_back(v);
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TOURIST.INP", "r", stdin);
	freopen("TOURIST.OUT", "w", stdout);

	cin >> n;

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			bool vi;
			cin >> vi;
			if (vi) {
				graph[j][i] = 1;
				adj[j].push_back(i);
			} else {
				graph[i][j] = 1;
				adj[i].push_back(j);
			}
		}
	}
	for (int i = 1; i <= n; ++i) if (!tin[i])
		dfs(i, -1);
	for (int i = 1; i <= n; ++i) {
		for (int j : adj[i]) if (comp[i] != comp[j]) {
			int u = comp[i], v = comp[j];
			dag[u].push_back(v);
		}
	}
	memset(mark, 0, sizeof mark);
	for (int i = 1; i <= scc_count; ++i) if (!mark[i]) {
		dfs_topo(i);
	}
	memset(trace, -1, sizeof trace);
	for (int u : topo) {
		dp[u] = scc_size[u];
		for (int v : dag[u]) {
			if (dp[v] + scc_size[u] > dp[u]) {
				trace[u] = v;
				dp[u] = dp[v] + scc_size[u];
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		vector <int> res = gotrace(comp[i], i);
		cout << res.size() << ' ';
		for (int v : res) cout << v << ' ';
		cout << endl;
	}

	return 0;
}