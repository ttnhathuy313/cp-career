#include <bits/stdc++.h>

using namespace std;
#pragma GCC optimize("Ofast")

const int N = 1e6 + 5, LOG = 21;
int n, a[N], st[4 * N], maxRange[N], dp[N];

struct SegmentTree {
	int n;
	vector <int> st;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.assign(4 * n + 5, N);
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}
	void update(int id, int L, int R, int i, int j, int val) {
		if (L > j || R < i) return;
		if (L >= i && R <= j) {
			st[id] = min(st[id], val);
			return;
		}
		int mid = (L + R) >> 1;
		update(Left(id), L, mid, i, j, val);
		update(Right(id), mid + 1, R, i, j, val);
	}
	int get(int id, int L, int R, int i) {
		if (L > i || R < i) return N;
		if (L == R) {
			return st[id];
		}
		int mid = (L + R) >> 1, res = st[id];
		res = min(res, get(Left(id), L, mid, i));
		res = min(res, get(Right(id), mid + 1, R, i));
		return res;
	}

	void update(int i, int j, int val) {
		update(1, 1, n,  i, j, val);
	}
	int get(int i) {
		return get(1, 1, n, i);
	}
};

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("IZhO17_money.INP", "r", stdin);
	freopen("IZhO17_money.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	maxRange[n] = n;
	for (int i = n - 1; i >= 1; --i) {
		if (a[i] <= a[i + 1]) maxRange[i] = maxRange[i + 1];
		else maxRange[i] = i;
	}
	SegmentTree solver = SegmentTree(n);
	set <int> S; S.clear(); S.insert(a[1]);
	for (int i = 1; i <= n; ++i) dp[i] = N;
	dp[maxRange[1]] = 1;
	for (int i = 2; i <= n; ++i) {
		int val;
		set <int>::iterator it = S.upper_bound(a[i]);
		if (it == S.end()) val = N;
		else val = *it;
		int l = i, r = maxRange[i], far = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[mid] > val) r = mid - 1;
			else l = mid + 1, far = mid;
		}
		dp[far] = min(dp[far], dp[i - 1] + 1);
		S.insert(a[i]);
	}
	cout << dp[n] << endl;


	return 0;
}