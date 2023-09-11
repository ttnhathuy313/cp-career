#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, a[N], b[N], res, t[N];
vector <int> adj[N], ans, neg;

void dfs(int u, int pre) {
	for (int v : adj[u]) {
		if (v == pre) continue;
		dfs(v, u);
		if (a[v] < 0) {
			neg.push_back(v);
		} else {
			ans.push_back(v);
			a[u] += a[v];
		}
	}
	res += a[u];
}

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}


signed main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n;
	// n = 1000;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		// a[i] = Rand(-200, 200);
		t[i] = a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		// if (i == 1) b[i] = -1;
		// else b[i] = Rand(1, i - 1);
		if (b[i] == -1) continue;
		adj[i].push_back(b[i]);
		adj[b[i]].push_back(i);
	}
	for (int u = 1; u <= n; ++u) if (b[u] == -1) {
		neg.clear();
		dfs(u, -1);
		ans.push_back(u);
		reverse(neg.begin(), neg.end());
		for (int v : neg) ans.push_back(v);
	}
	cout << res << endl;
	for (int v : ans) cout << v << ' ';

	int check = 0;
	for (int v : ans) {
		check += t[v];
		if (~b[v]) t[b[v]] += t[v];
	}
	if (check != res) cerr << "LMAO" << endl;

	return 0;
}