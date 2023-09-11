#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int N = 2e5 + 5;
int n, m, ans[N], p[N], pos[N];
vector <ii> q[N];
vector <iii> List;

struct fenwick {
	int n;
	vector <int> fw;
	fenwick() {}
	fenwick(int _n) {
		this -> n = _n;
		fw.assign(n + 5, 0);
	}
	void inc(int x) {
		while (x <= n) {
			fw[x]++;
			x += (x & -x);
		}
	}
	int get(int x) {
		int res = 0;
		while (x) {
			res += fw[x];
			x -= (x & -x);
		}
		return res;
	}
};

void solve() {
	fenwick st = fenwick(n);
	int tot = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = p[i]; j <= n; j += p[i]) if (pos[j] < i) {
			tot ++;
			st.inc(pos[j]);
		}
		for (ii v : q[i]) {
			ans[v.second] += tot - st.get(v.first - 1);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	for (int i = 1; i <= m; ++i) {
		int l, r;
		cin >> l >> r;
		List.push_back({i, {l, r}});
		q[r].push_back({l, i});
		ans[i] += (r - l + 1);
	}
	solve();
	reverse(p + 1, p + 1 + n);
	for (int i = 1; i <= n; ++i) {
		q[i].clear();
		pos[p[i]] = i;
	}
	for (iii d : List) {
		int i = d.second.first, j = d.second.second;
		i = n - i + 1, j = n - j + 1;
		q[i].push_back({j, d.first});
	}
	solve();
	for (int i = 1; i <= m; ++i)
		cout << ans[i] << endl;

	return 0;
}