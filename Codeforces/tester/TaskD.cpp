#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 2e5 + 5;
int n, k, cnt[N], a[N], lst[N];
bool mark[N];
vector <int> ind[N];
 
struct Node {
	int lazy, sum;
};
 
struct SegmentTree {
	vector <Node> st;
	int n;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.assign(4 * n + 5, {0, 0});
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}
 
	void push(int id, int L, int R) {
		int mid = (L + R) >> 1;
		st[Left(id)].lazy += st[id].lazy;
		st[Left(id)].sum += st[id].lazy * (mid - L + 1);
		st[Right(id)].lazy += st[id].lazy;
		st[Right(id)].sum += st[id].lazy * (R - mid);
		st[id].lazy = 0;
	}
 
	void update(int id, int L, int R, int i, int j, int val) {
		if (L > j || R < i) return;
		if (L >= i && R <= j) {
			st[id].sum += (R - L + 1) * val;
			st[id].lazy += val;
			return;
		}
		int mid = (L + R) >> 1;
		push(id, L, R);
		update(Left(id), L, mid, i, j, val);
		update(Right(id), mid + 1, R, i, j, val);
		st[id].sum = st[Left(id)].sum + st[Right(id)].sum;
	}
 
	int query(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return 0;
		if (L >= i && R <= j) return st[id].sum;
		int mid = (L + R) >> 1;
		push(id, L, R);
		return query(Left(id), L, mid, i, j) + query(Right(id), mid + 1, R, i, j);
	}
 
	void update(int i, int j, int val) {
		update(1, 1, n, i, j, val);
	}
	int get(int l, int r) {
		return query(1, 1, n, l, r);
	}
} Solver;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		ind[a[i]].push_back(i);
	}
	Solver = SegmentTree(n);
	memset(lst, -1, sizeof lst);
	set <ii> avail; avail.clear();
	int cur = 1, beg = k, dem = 0, start = 0;
	for (int i = n; i >= 1; --i) {
		cnt[a[i]]++;
		if (cnt[a[i]] == 1) {
			lst[a[i]] = i;
			dem++;
		}
		Solver.update(i, i, k - dem);
		if (dem == k) avail.insert({a[i], i});
	}
	int pre = 0;
	for (int turn = 1; turn <= k; ++turn) {
		ii now = *(avail.begin());
		cout << now.first << ' ';
		mark[now.first] = 1;
		// cerr << now.first << ' ' << now.second << endl;
		Solver.update(lst[now.first] + 1, n, -1);
		for (int i = pre + 1; i <= now.second; ++i) {
			// cerr << "	erase " << a[i] << ' ' << i << endl;
			avail.erase({a[i], i});
		}
		pre = now.second;
		int cur = lst[now.first] + 1;
		while (cur <= n && Solver.get(cur, cur) == 0) {
			if (!mark[a[cur]]) {
				// cerr << "	insert " << a[cur] << ' ' << cur << endl;
				avail.insert({a[cur], cur});
			}
			cur++;
		}
		for (int i : ind[now.first]) {
			if (avail.find({a[i], i}) != avail.end())
				// cerr << "	erase " << a[i] << ' ' << i << endl;
				avail.erase({a[i], i});
		}
	}

	return 0;
}