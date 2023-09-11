#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second
typedef pair <int, int> ii;

struct Node {
	int lazy, mx;
};

struct SegmentTree {
	int n;
	vector <Node> st;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.assign(4 * n + 5, {0, 0});
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}
 
	void push(int id) {
		st[Left(id)].lazy += st[id].lazy;
		st[Left(id)].mx += st[id].lazy;
		st[Right(id)].lazy += st[id].lazy;
		st[Right(id)].mx += st[id].lazy;
		st[id].lazy = 0;
	}
 
	void update(int id, int L, int R, int i, int j, int val) {
		if (L > j || R < i) return;
		if (L >= i && R <= j) {
			st[id].lazy += val;
			st[id].mx += val;
			return;
		}
		int mid = (L + R) >> 1;
		push(id);
		update(Left(id), L, mid, i, j, val);
		update(Right(id), mid + 1, R, i, j, val);
		st[id].mx = max(st[Left(id)].mx, st[Right(id)].mx);
	}
 
	int query(int id, int L, int R, int i, int j) {
		if (L > j || R < i) return -1;
		if (L >= i && R <= j) return st[id].mx;
		push(id);
		int mid = (L + R) >> 1;
		return max(query(Left(id), L, mid, i, j), query(Right(id), mid + 1, R, i, j));
	}
	void update(int i, int j, int val) {
		update(1, 0, n, i, j, val);
	}
	int get(int i, int j) {
		return query(1, 0, n, i, j);
	}
};

const int N = 3e5 + 5;
int n, w, h, res;
ii p[N];

void solve() {
	sort(p + 1, p + 1 + n);
	SegmentTree IT(n + 5);
	stack <int> up, down;
	while (!up.empty()) up.pop();
	while (!down.empty()) down.pop();
	up.push(0); down.push(0);
	IT.update(0, n, h);
	for (int i = 1; i <= n; ++i) {
		int v = IT.get(0, i - 1);
		res = max(res, v + p[i].x);
		// cerr << "ans at " << i << " is " << v + p[i].x << endl;
		if (p[i].y > h / 2) {
			if (up.top() == 0) {
				IT.update(0, i - 1, p[i].y - h);
				up.push(i);
				goto mark;
			}
			IT.update(up.top(), i - 1, p[i].y - h);
			while (!up.empty() && up.top() != 0 && p[i].y < p[up.top()].y) {
				int u = up.top(); up.pop();
				int v = up.top();
				IT.update(v, u - 1, p[i].y - p[u].y);
			}
			up.push(i);	
		} else {
			if (down.top() == 0) {
				IT.update(0, i - 1, -p[i].y);
				down.push(i);
				goto mark;
			}
			IT.update(down.top(), i - 1, -p[i].y);
			while (!down.empty() && down.top() != 0 && p[i].y > p[down.top()].y) {
				int u = down.top(); down.pop();
				int v = down.top();
				IT.update(v, u - 1, p[u].y - p[i].y);
			}
			down.push(i);
		}
		mark:;
		IT.update(i, i, -p[i].x);
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> w >> h >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].x >> p[i].y;
		// cerr << "(" << p[i].x << ", " << p[i].y << ")" << endl;
	}
	for (int i = 1; i <= 109; ++i) cerr << ":no:";
	n++;
	p[n] = {w, h};
	solve();
	for (int i = 1; i <= n; ++i)
		swap(p[i].x, p[i].y);
	swap(w, h);
	solve();
	cout << (res << 1) << endl;

	return 0;
}