#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef tuple <int, int, int> ti;

const int N = 3e5 + 5, MOD1 = 1e9 + 7, MOD2 = 1e9 + 207, base1 = 3e5 + 17, base2 = 3e5 + 19;
int basePow1[N], basePow2[N], res, a[N], n;

struct THash {
	int val1, val2, len = 0;
	THash() {val1 = val2 = len = 0;}
	void add(int x) {
		val1 = (val1 + basePow1[len] * x) % MOD1;
		val2 = (val2 + basePow2[len] * x) % MOD2;
		len++;
	}
	void pop(int x) {
		len--;
		val1 = (val1 - basePow1[len] * x + MOD1 * MOD1) % MOD1;
		val2 = (val2 - basePow2[len] * x + MOD2 * MOD2) % MOD2;
	}
	bool operator < (THash other) const {
		return (len < other.len && val1 < other.val1 && val2 < other.val2);
	}
};

void get(int l, int r) {
	if (l > r) return;
	int mid = (l + r) >> 1;
	map <ti, int> cnt;
	cnt.clear();
	stack <int> st; while (!st.empty()) st.pop();
	THash cur;
	for (int i = mid; i >= l; --i) {
		if (st.size() > 0 && st.top() == a[i]) {
			st.pop();
			cur.pop(a[i]);
		} else {
			st.push(a[i]);
			cur.add(a[i]);
		}
		ti mt = make_tuple(cur.val1, cur.val2, cur.len);
		cnt[mt]++;
	}
	cur = THash(); while (!st.empty()) st.pop(); int tmp = 0;

	for (int i = mid + 1; i <= r; ++i) {
		if (st.size() > 0 && st.top() == a[i]) {
			st.pop();
			cur.pop(a[i]);
		} else {
			st.push(a[i]);
			cur.add(a[i]);
		}
		ti mt = make_tuple(cur.val1, cur.val2, cur.len);
		tmp += cnt[mt];
	}
	res += tmp;
	if (l == r) return;
	get(l, mid); get(mid + 1, r);
}

void solve() {
	res = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	get(1, n);
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.inp", "r", stdin);
	freopen("TaskF.out", "w", stdout);

	basePow1[0] = 1;
	for (int i = 1; i < N; ++i) basePow1[i] = basePow1[i - 1] * base1 % MOD1;
	basePow2[0] = 1;
	for (int i = 1; i < N; ++i) basePow2[i] = basePow2[i - 1] * base2 % MOD2;
	int q;
	cin >> q;
	while (q--) solve();

	return 0;
}