#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;

struct SegmentTree {
	vector <int> st;
	int n;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.assign(4 * n + 5, oo);
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}

	void update(int id, int L, int R, int i, int val) {
		if (L > i || R < i) return;
		if (L == R) {
			st[id] = val;
			return;
		}
		int mid = (L + R) >> 1;
		update(Left(id), L, mid, i, val);
		update(Right(id), mid + 1, R, i, val);
		st[id] = min(st[Left(id)], st[Right(id)]);
	}

	int get(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return oo;
		if (L >= i && R <= j) return st[id];
		int mid = (L + R) >> 1;
		return min(get(Left(id), L, mid, i, j), get(Right(id), mid + 1, R, i, j));
	}

	void update(int i, int val) {update(1, 1, n, i, val);}
	int get(int i, int j) {return get(1, 1, n, i, j);}
} IT;

const int N = 1e5 + 5;
int pref[N], dp[N];

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	s = ' ' + s;
	IT = SegmentTree(n);
	memset(pref, 0, sizeof pref);
	for (int i = 1; i <= n; ++i) dp[i] = N;
	for (int i = 2; i <= n; ++i) {
		if (s[i] == s[i - 1]) pref[i]++;
	}
	for (int i = 1; i <= n; ++i) {
		pref[i] += pref[i - 1];
	}
	dp[0] = -1;
	IT.update(1, -1);
	for (int i = 1; i <= n; ++i) {
		int l = max(1, i - k + 1), r = i - 1, ans = i;	
		dp[i] = dp[i - 1] + 1;
		if (pref[i] - pref[l] == 0) {
			IT.update(i + 1, dp[i]);
			continue;
		}
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (pref[i] - pref[mid] == 0) r = mid - 1, ans = mid;
			else l = mid + 1;
		}
		l = max(1, i - k + 1);
		if (ans - 1 < l) {
			IT.update(i + 1, dp[i]);
			continue;
		}
		dp[i] = min(dp[i], IT.get(l, ans - 1) + 1);
		IT.update(i + 1, dp[i]);
	}
	cout << dp[n] << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskL.inp", "r", stdin);
	freopen("TaskL.out", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}