#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 3e5 + 5;
int n, k, m, a[N], final[N], sz[N];
priority_queue <ii> pq;

struct dsu_t {
	int n;
	vector <int> lab;
	dsu_t() {}
	dsu_t(int _n) {
		this -> n = _n;
		lab.assign(n + 5, -1);
	}
	int root(int x) {
		return lab[x] == -1 ? x : lab[x] = root(lab[x]);
	}
	void merge(int u, int v) {
		int x = root(u), y = root(v);
		if (x == y) return;
		lab[x] = y;
		return;
	}
} chain, goLeft, goRight;


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> k >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i + n] = a[i];
		sz[i] = 1;
	}
	chain = goLeft = goRight = dsu_t(n);
	for (int i = 1; i < n; ++i) {
		if (a[i] == a[i + 1]) {
			chain.merge(i, i + 1);
			sz[i + 1] = sz[i] + 1;
		}
	}
	for (int i = 1; i <= n; ++i) if (a[i] != a[i + 1]) {
		pq.push({sz[i], i});
	}
	while (!pq.empty()) {
		int cur_sz = pq.top().first, u = pq.top().second;
		pq.pop();
		if (goLeft.lab[u] != -1) continue;
		if (cur_sz < k) break;
		// delete k * times object
		int times = cur_sz / k, t = times * k, lst = -1, id = u;
		while (t--) {
			lst = id;
			cerr << id << ' ';
			int v = goLeft.root(id - 1);
			goLeft.merge(id, id - 1);
			goRight.merge(id, id + 1);
			id = v;
		}
		cerr << endl;
		//merging

		int pre = goLeft.root(lst);
		if (pre != 0) {
			if (a[pre] == a[u]) {
				sz[pre] = cur_sz - times * k;
				pq.push({sz[pre], pre});
			} else {
				int nxt = goRight.root(pre + 1);
				if (a[nxt] == a[pre]) {
					int fin = chain.root(nxt);
					chain.merge(pre, nxt);
					sz[fin] += sz[pre];
					pq.push({sz[fin], fin});
				}
			}
		}
	}
	int cnt = 0;
	for (int i = goRight.root(1); i <= n; i = goRight.root(i + 1)) {
		final[++cnt] = a[i];
	}
	n = cnt;
	for (int i = 1; i <= n; ++i) {
		final[i + n] = final[i]; 
	}
	for (int i = 1; i <= n; ++i) cerr << final[i] << ' ';
		cerr << endl;
	bool check = true;
	for (int i = 2; i <= n; ++i) if (final[i] != final[1]) check = false;
	if (check) {
		cout << (m * n) % k << endl;
		return 0;
	}
	int l = n, r = n + 1, cnt1 = 0, cnt2 = 0;
	while (1) {
		cnt1 = 1;
		while (final[r] == final[l]) r++, cnt2++;
		while (final[l - 1] == final[l]) l--, cnt1++;
		if ((cnt1 + cnt2) % k != 0) {
			int len = ((cnt1 + cnt2) % k) + l - min(r - n, l);
			bool ok = true;
			for (int i = min(r - n, l); i < l; ++i) if (a[i] != a[i + 1])
				ok = false;
			if (!ok) cout << len * (m - 1) + 2 * n - r + min(l, r - n) << endl;
			else {
				cerr << len << endl;
				if (len * (m - 1) % k == 0) cout << 0 << endl;
				else cout << (len * (m - 1) % k) + 2 * n - r + min(l, r - n) << endl;
			}
			return 0;
		} else {
			l--;
			cnt1 = cnt2 = 0;
			if (l == 0) {
				if (m & 1) cout << n << endl;
				else cout << 0 << endl;
				return 0;
			}
		}
	}

	return 0;
}