#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5, LOG = 32;
ii parent[N];
int bipartite[N], Rank[N], n, a[N], res[N];
vector <int> b[32], c[32];

void make_set(int v) {
    parent[v] = make_pair(v, 0);
    Rank[v] = 0;
    bipartite[v] = true;
}

pair<int, int> find_set(int v) {
    if (v != parent[v].first) {
        int parity = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second ^= parity;
    }
    return parent[v];
}

bool add_edge(int a, int b) {
    pair<int, int> pa = find_set(a);
    a = pa.first;
    int x = pa.second;

    pair<int, int> pb = find_set(b);
    b = pb.first;
    int y = pb.second;

    if (a == b) {
        if (x == y)
            return false;
    } else {
        if (Rank[a] < Rank[b])
            swap (a, b);
        parent[b] = make_pair(a, x^y^1);
        bipartite[a] &= bipartite[b];
        if (Rank[a] == Rank[b])
            ++Rank[a];
    }
    return true;
}

bool is_bipartite(int v) {
    return bipartite[find_set(v).first];
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		res[i] = -1;
	}
	for (int i = 1; i <= n; ++i) make_set(i);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 32; ++j) if ((a[i] & (1 << j)) == 0) {
			b[j].push_back(i);
		} else c[j].push_back(i);
	}
	int res = 0;
	for (int j = 0; j < LOG; ++j) {
		if (b[j].size() > 2 || c[j].size() > 2) continue;
		if (b[j].size() == 1 && c[j].size() == 1) {
			res += (1 << j);
			continue;
		}
		int u = b[j][0], v, xx = c[j][0], yy;
		if (b[j].size() == 2) {
			v = b[j][1];
			pair<int, int> pa = find_set(u);
		    int a = pa.first;
		    int x = pa.second;

		    pair<int, int> pb = find_set(v);
		    int b = pb.first;
		    int y = pb.second;
		    if (a == b && x == y) continue;
		    add_edge(u, v);
		}
		if (c[j].size() == 2) {
			yy = c[j][1];
			pair<int, int> pa = find_set(xx);
		    int a = pa.first;
		    int x = pa.second;

		    pair<int, int> pb = find_set(yy);
		    int b = pb.first;
		    int y = pb.second;
		    if (a == b && x == y) continue;
		    add_edge(xx, yy);
		}
		res += (1 << j);
	}
	cout << res << endl;
	for (int i = 1; i <= n; ++i) {
		if (parent[i].second == 0) cout << "1";
		else cout << "2";
	}
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}