#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2e5 + 5;
int n, dp[N], cost[N], d[N], lab[N], res;

struct obj {
	int sum_d, sum_cost;
	bool operator < (const obj other) const {
		return sum_d * other.sum_cost > other.sum_d * sum_cost;
	}
	bool operator != (const obj other) const {
		return ii(sum_d, sum_cost) != ii(other.sum_d, other.sum_cost);
	}
} a[N];

int root(int x) {
	if (lab[x] == -1) return x;
	else return lab[x] = root(lab[x]);
}

int scheduling_cost(vector <int32_t> p, vector <int32_t> c, vector <int32_t> time) {
	memset(lab, -1, sizeof lab);	
	n = p.size();
	priority_queue <pair <obj, int>> pq;
	while (!pq.empty()) pq.pop();
	for (int i = 0; i < n; ++i) {
		cost[i] = c[i];
		d[i] = time[i];
		a[i] = {d[i], cost[i]};
		res += d[i] * cost[i];
		pq.push({a[i], i});
	}
	while (!pq.empty()) {
		obj cur = pq.top().first; int u = pq.top().second;
		pq.pop();
		if (cur != a[u] || u == 0) continue;
		int v = root(p[u]);
		res += a[v].sum_d * a[u].sum_cost;
		a[v].sum_d += a[u].sum_d; a[v].sum_cost += a[u].sum_cost;
		lab[u] = v;
		pq.push({a[v], v});
	}
	return res;
}


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("JOB.INP", "r", stdin);
	freopen("JOB.OUT", "w", stdout);

	int n;
	cin >> n;
	vector <int32_t> p, c, time;
	p.assign(n, 0); c.assign(n, 0); time.assign(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	for (int i = 0; i < n; ++i)
		cin >> c[i];
	for (int i = 0; i < n; ++i)
		cin >> time[i];
	cout << scheduling_cost(p, c, time) << endl;

	return 0;
}