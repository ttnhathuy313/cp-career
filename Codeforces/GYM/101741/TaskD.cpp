#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int oo = 1e18 + 7;

struct Node {
	int lazy, mi;
	Node() {}
	Node(int _lazy, int _mi) : lazy(_lazy), mi(_mi) {}
};

struct SegmentTree {
	int n;
	vector <Node> st;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.resize(4 * n + 6);
		for (int i = 1; i <= 4 * n + 5; ++i) {
			st[i] = Node(0, 0);
		}
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}

	void push(int id) {
		st[Left(id)].mi += st[id].lazy;
		st[Left(id)].lazy += st[id].lazy;
		st[Right(id)].mi += st[id].lazy;
		st[Right(id)].lazy += st[id].lazy;
		st[id].lazy = 0;
	}

	void update(int id, int L, int R, int i, int j, int val) {
		if (L > j || R < i) return;
		if (L >= i && R <= j) {
			st[id].lazy += val;
			st[id].mi += val;
			return;
		}
		int mid = (L + R) >> 1;
		push(id);
		update(Left(id), L, mid, i, j, val);
		update(Right(id), mid + 1, R, i, j, val);
		st[id].mi = min(st[Left(id)].mi, st[Right(id)].mi);
	}

	int get(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return oo;
		if (L >= i && R <= j) 
			return st[id].mi;
		int mid = (L + R) >> 1;
		push(id);
		int ret = min(get(Left(id), L, mid, i, j), get(Right(id), mid + 1, R, i, j));
		st[id].mi = min(st[Left(id)].mi, st[Right(id)].mi);
		return ret;
	}

	void update(int i, int j, int val) {
		update(1, 1, n, i, j, val);
	}
	int get(int i, int j) {
		if (j < i) return oo;
		return get(1, 1, n, i, j);
	}
} IT;

const int N = 2e5 + 5;
int dp[N], n;

void solve() {
	vector <ii> a; a.clear();
	for (int i = 1; i <= n; ++i) {
		int t, d;
		cin >> t >> d;
		a.push_back(ii(t, d));
	}
	a.push_back(ii(-oo, oo));
	sort(a.begin(), a.end());
	IT = SegmentTree(n);
	stack <int> st;
	while (!st.empty()) st.pop();
	st.push(0);
	multiset <int> S; S.clear();
	int cursor = 0; S.insert(oo);
	for (int i = 1; i <= n; ++i) {
		while (st.size() > 1 && a[st.top()].second < a[i].second) {
			int pre = st.top();
			st.pop();
			IT.update(st.top() + 1, pre, 2 * (a[i].second - a[pre].second));
		}
		IT.update(i, i, 2 * a[i].second);
		st.push(i);
		while (cursor < i && dp[cursor] < a[i].first) {
			S.erase(S.find(a[cursor].second));
			cursor++;
		}
		S.insert(a[i].second);
		dp[i] = IT.get(cursor + 1, i);
		dp[i] = min(dp[i], *(S.rbegin()) * 2 + a[i].first);
		IT.update(i + 1, i + 1, dp[i]);
	}
	cout << dp[n] << endl;
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);
	freopen("TaskD.out", "w", stdout);

	while (cin >> n) {
		solve();
	}

	return 0;
}