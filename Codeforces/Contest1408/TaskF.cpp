#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 15000;
int n;
vector <int> st[N];
vector <ii> res;

int Left(int x) {return (x << 1);}
int Right(int x) {return (x << 1) + 1;}

void solve(int id, int L, int R) {
	st[id].clear();
	if (L == R) {
		st[id].push_back(L);
		return;
	}
	int mid = (L + R) >> 1;
	solve(Left(id), L, mid);
	solve(Right(id), mid + 1, R);
	for (int v : st[Left(id)]) st[id].push_back(v);
	int cur = 0;
	for (int v : st[Right(id)]) {
		st[id].push_back(v);
		res.push_back({st[id][cur++], v});
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n;
	int lg = (int)log2(n);
	solve(1, 1, (1 << lg));
	solve(1, n - (1 << lg) + 1, n);
	cout << res.size() << endl;
	for (ii v : res) {
		cout << v.first << ' ' << v.second << endl;
	}

	return 0;
}