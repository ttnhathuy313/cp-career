#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 4e4 + 5;
int n, q;
vector <int> st[4 * N];

int Left(int id) {
	return (id << 1);
}

int Right(int id) {
	return (id << 1) + 1;
}

void add(int id, int L, int R, int i, int j, int x) {
	if (L > j || R < i) return;
	if (L >= i && R <= j) {
		st[id].push_back(x);
		return;
	}
	int mid = (L + R) >> 1;
	add(Left(id), L, mid, i, j, x);
	add(Right(id), mid + 1, R, i, j, x);
}

bitset<N> result, cur;

void dfs(int id, int L, int R) {
	bitset <N> next = cur, temp = cur;
	for (int x : st[id]) {
		next |= (next << x);
	}
	cur = next;
	if (L == R) {
		result |= next;
		cur = temp;
		if (L == 2) {
			cerr << cur[2] << endl;
		}
		return;
	}
	int mid = (L + R) >> 1;
	dfs(Left(id), L, mid);
	dfs(Right(id), mid + 1, R);
	cur = temp;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> q;
	for (int i = 1; i <= q; ++i) {
		int l, r, x;
		cin >> l >> r >> x;
		add(1, 1, n, l, r, x);
	}
	result[0] = cur[0] = 1;
	dfs(1, 1, n);
	vector <int> res;
	res.clear();
	for (int i = 1; i <= n; ++i) if (result[i] == 1) {
		res.push_back(i);
	}
	cout << res.size() << endl;
	for (int i : res) {
		cout << i << ' ';
	}

	return 0;
}