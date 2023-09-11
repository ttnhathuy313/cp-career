#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'
typedef pair <int, int> ii;

const int N = 1e5 + 5, block_sz = 700;
int n, k, p[N], ans[N], Left[N], Right[N], cnt[N];
map <int, int> nen;

struct Query {
	int l, r, id;
	Query() {}
	Query(int _l, int _r, int _id) : l(_l), r(_r), id(_id) {}
};
bool operator < (const Query a, const Query b) {
	int i = a.l / block_sz, j = b.l / block_sz;
	if (i != j) return a.l < b.l;
	else {
		if (i & 1) return a.r > b.r;
		else return a.r < b.r;
	}
}
vector <Query> Q;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		int t;
		cin >> t;
		if (t == 1) p[i] = 1;
		else p[i] = -1;
	}
	set <int> val; val.clear();
	val.insert(0);
	for (int i = 1; i <= n; ++i) {
		int v;
		cin >> v;
		p[i] *= v;
		p[i] += p[i - 1];
		cerr << p[i] << ' ';
		val.insert(p[i]);
	}
	cerr << endl;
	int i = 0;
	for (int v : val) {
		nen[v] = i++;
	}
	memset(Left, -1, sizeof Left);
	memset(Right, -1, sizeof Right);
	for (int i = 0; i <= n; ++i) { // p[i] - p[j] = k
		if (val.find(p[i] + k) != val.end())
			Right[i] = nen[p[i] + k];
		if (val.find(p[i] - k) != val.end())
			Left[i] = nen[p[i] - k];
		p[i] = nen[p[i]];
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		int l, r;
		cin >> l >> r; --l;
		Q.push_back({l, r, i});
	}
	sort(Q.begin(), Q.end());
	int res = 0, L = 0, R = -1;
	for (Query q : Q) {
		while (R < q.r) {
			R++;
			if (~Left[R]) {
				res += cnt[Left[R]];
			}
			cnt[p[R]]++;
		}
		while (L > q.l) {
			L--;
			if (~Right[L]) res += cnt[Right[L]];
			cnt[p[L]]++;
		}
		while (L < q.l) {
			cnt[p[L]]--;
			if (~Right[L]) res -= cnt[Right[L]];
			L++;
		}
		while (R > q.r) {
			cnt[p[R]]--;
			if (~Left[R]) res -= cnt[Left[R]];
			R--;
		}
		ans[q.id] = res;
	}
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << endl;
	}

	return 0;
}