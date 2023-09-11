#include <bits/stdc++.h>
 
using namespace std;
#define int long long
typedef pair<int, int> ii;
 
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define endl '\n'
 
const int oo = 1e18;
 
struct Node {
	int lazy, minVal;
	Node() {}
	Node(int _lazy, int _minVal) : lazy(_lazy), minVal(_minVal) {}
};
 
struct SegmentTree {
	vector <Node> st;
	int n;
 
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}
 
	SegmentTree() {}
	SegmentTree(int n) {
		this -> n = n;
		st.resize(4 * n + 5);
		REP(i, 4 * n + 5) st[i] = Node(0, 0);
	}
 
	void push(int id) {
		st[Left(id)].lazy += st[id].lazy;
		st[Left(id)].minVal += st[id].lazy;
		st[Right(id)].lazy += st[id].lazy;
		st[Right(id)].minVal += st[id].lazy;
		st[id].lazy = 0;
	}
 
	void update(int id, int L, int R, int i, int j, int val) {
		if (L > j || R < i) return;
		if (L >= i && R <= j) {
			st[id].lazy += val;
			st[id].minVal += val;
		} else {
			int mid = (L + R) >> 1;
			push(id);
			update(Left(id), L, mid, i, j, val);
			update(Right(id), mid + 1, R, i, j, val);
			st[id].minVal = min(st[Left(id)].minVal, st[Right(id)].minVal);
		}
	}
 
	int query(int id, int L, int R, int i, int j) {
		if (i > j) return 0;
		if (L > j || R < i) return oo;
		if (L >= i && R <= j) return st[id].minVal;
		int mid = (L + R) >> 1;
		push(id);
		return min(query(Left(id), L, mid, i, j), query(Right(id), mid + 1, R, i, j));
	}
 
	void update(int i, int j, int val) {update(1, 1, n, i, j, val);}
	int query(int i, int j) {return query(1, 1, n, i, j);}
};
 
const int N = 1e5 + 5;
int a[N], f[N], n, M, sum[N];
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	clock_t tStart = clock();
	freopen("chiatao.inp", "r", stdin);
 
	cin >> n >> M;
	int s = 0;
	FOR(i, 1, n) {
		cin >> a[i];
		s += a[i];
		if (a[i] > M) {
			cout << 0 << endl;
			return 0;
		}
		sum[i] = sum[i - 1] + a[i];
	}
	a[0] = M;
	SegmentTree IT(n);
	int j = 1;
	stack <int> S;
	S.push(0);
	FOR(i, 1, n) {
		while (sum[i] - sum[j - 1] > M) j++;
		while (!S.empty() && a[S.top()] < a[i]) {
			int u = S.top(); S.pop();
			int v = S.top();
			IT.update(v + 1, u, -a[u]);
		}
		IT.update(S.top() + 1, i, a[i]);
		S.push(i);
		f[i] = IT.query(j, i);
		IT.update(i + 1, i + 1, f[i]);
	}
	cout << s - f[n] << endl;
 
	fprintf(stderr, "Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}