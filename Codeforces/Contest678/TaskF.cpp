#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
#define int long long
#define endl '\n'
typedef pair <int, int> ii;

const int N = 3e5 + 5, oo = 2e18;
int n, block_size, ans[N], a[N], b[N], type[N], time_end[N], n1, n2, process[N], n3, del[N];
ii lines[N];

struct Line {
	int a, b;
	Line() {}
	Line(int _a, int _b) : a(_a), b(_b) {}
	int val(int x) {
		return a * x + b;
	}
} st[N];

int bad(Line a, Line b, Line c) {
	return (c.b - a.b) * (b.a - c.a) <= (c.b - b.b) * (a.a - c.a);
}
void addLine(Line a) {
	if (n3 && st[n3 - 1].a == a.a && st[n3 - 1].b == a.b) n3--;
	while (n3 >= 2 && bad(a, st[n3 - 1], st[n3 - 2]))
		n3--;
	st[n3++] = a;
}
int query(int x) {
	int ans = -oo, l = 0, r = n3 - 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		ans = max(ans, st[mid].val(x));
		int lmid = (mid == 0 ? -oo : st[mid - 1].val(x)), rmid = (mid == n3 - 1 ? -oo : st[mid + 1].val(x));
		if (lmid > rmid) r = mid - 1; 
		else if (rmid > lmid) l = mid + 1;
		else break;
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	clock_t T = clock();

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> type[i] >> a[i];
		if (type[i] == 1) cin >> b[i];
	}
	block_size = 3000;
	vector <int> willadd, cur;
	cur.clear();
	for (int L = 1; L <= n; L += block_size) {
		willadd.clear(); n3 = 0;
		int R = min(n, L + block_size - 1);
		for (int i = L; i <= R; ++i) if (type[i] == 2 && a[i] < L) willadd.push_back(a[i]), del[a[i]] = 2;
		vector <ii> V; V.clear();
		for (int r : cur) if (del[r] == 0) V.push_back({a[r], b[r]});
		sort(V.begin(), V.end());
		for (ii d : V) addLine(Line(d.first, d.second));

		for (int j = L; j <= R; ++j) {
			if (type[j] == 1) willadd.push_back(j);
			if (type[j] == 2) del[a[j]] = 1;
			if (type[j] == 3) {
				ans[j] = -oo;
				for (int r : willadd) if (del[r] != 1) ans[j] = max(ans[j], a[r] * a[j] + b[r]);
				ans[j] = max(ans[j], query(a[j]));
			}
		}

		for (int r : willadd) if (del[r] == 0) cur.push_back(r);
	}

	for (int i = 1; i <= n; ++i) if (type[i] == 3) {
		if (ans[i] == -oo) cout << "EMPTY SET" << endl;
		else cout << ans[i] << endl;
	}

	return 0;
}