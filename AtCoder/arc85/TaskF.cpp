#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int dp[N], b[N], cnt[N], n, q, st[4 * N];
vector <int> endPoints[N];

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
	if (i == 0) return 0;
	if (L > i || R < i) return N;
	if (L == R) return st[id];
	int mid = (L + R) >> 1;
	if (i <= mid) return min(st[id], get(Left(id), L, mid, i));
	else return min(st[id], get(Right(id), mid + 1, R, i));
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= 4 * n; ++i)
		st[i] = N;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		cnt[i] = cnt[i - 1] + (b[i] == 0 ? 1 : 0);
	}
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		endPoints[r].push_back(l);
	}
	for (int i = 1; i <= n; ++i) {
		update(1, 1, n, i, i, get(1, 1, n, i - 1) + (b[i] == 0 ? 0 : 1));
		for (int l : endPoints[i]) {
			update(1, 1, n, l, i, get(1, 1, n, l - 1) + cnt[i] - cnt[l - 1]);
		}
	}
	cout << get(1, 1, n, n) << endl;

	return 0;
}