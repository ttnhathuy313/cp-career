#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 5e4 + 5, Q = 2e5 + 5, MOD = 1e9 + 7, KK = 30;
int n, l[Q], r[Q], q, a[N], K, ans[Q], dpl[N][KK], dpr[N][KK], f[KK];
vector <int> st[4 * N];

int Left(int x) {return (x << 1);};
int Right(int x) {return (x << 1) + 1;}

void addQuery(int id, int L, int R, int i) {
	int mid = (L + R) >> 1;
	if (l[i] <= mid && r[i] > mid) {
		st[id].push_back(i);
		return;
	}
	if (r[i] <= mid) addQuery(Left(id), L, mid, i);
	else addQuery(Right(id), mid + 1, R, i);
}

void solve_left(int A, int B) {
	for (int i = A; i <= B; ++i) {
		for (int k = 1; k <= K; ++k)
			dpl[i][k] = 0;
	}
	for (int k = K; k >= 1; --k) {
		for (int i = 1; i <= K; ++i)
			f[i] = 0;
		for (int i = B; i >= A; --i) {
			dpl[i][k] += f[a[i]] + (a[i] == k); // use a[i]
			for (int j = 1; j <= a[i]; ++j)
				f[j] = (f[j] + f[a[i]] + (a[i] == k)) % MOD;
			if (i != B) dpl[i][k] += dpl[i + 1][k]; // not use a[i]

			dpl[i][k] %= MOD;
		}
	}
}

void solve_right(int A, int B) {
	for (int i = A; i <= B; ++i) {
		for (int k = 1; k <= K; ++k)
			dpr[i][k] = 0;
	}
	for (int k = K; k >= 1; --k) {
		for (int i = 1; i <= K; ++i)
			f[i] = 0;
		for (int i = A; i <= B; ++i) {
			dpr[i][k] += f[a[i]] + (a[i] == k); // use a[i]
			for (int j = K; j >= a[i]; --j) {
				f[j] = (f[j] + f[a[i]] + (a[i] == k)) % MOD;
			}
			if (i != A) dpr[i][k] += dpr[i - 1][k]; // not use a[i]

			dpr[i][k] %= MOD;
		}
	}
	for (int i = A; i <= B; ++i) {
		for (int j = K; j >= 1; --j) (dpr[i][j] += dpr[i][j + 1]) %= MOD;
	}
}

void solve(int id, int L, int R) {
	int mid = (L + R) >> 1;
	solve_left(L, mid);
	solve_right(mid + 1, R);
	for (int i : st[id]) {
		for (int j = 1; j <= K; ++j) {
			// cerr << j << ' ' << dpl[l[i]][j] * dpr[r[i]][j] << ' ' << dpl[l[i]][j] << ' ' << dpr[r[i]][j] << endl;
			(ans[i] += dpl[l[i]][j] * dpr[r[i]][j]) %= MOD;
			ans[i] += dpl[l[i]][j];
		}	
		ans[i] += dpr[r[i]][1];
		ans[i] %= MOD;
	}
	// exit(0);

	if (L == R) return;
	solve(Left(id), L, mid);
	solve(Right(id), mid + 1, R);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("nondec.in", "r", stdin);
	freopen("nondec.out", "w", stdout);

	cin >> n >> K;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}	
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> l[i] >> r[i];
	}
	for (int i = 1; i <= q; ++i) if (l[i] != r[i])
		addQuery(1, 1, n, i);
	solve(1, 1, n);
	for (int i = 1; i <= q; ++i) {
		if (l[i] != r[i]) cout << ans[i] + 1 << endl;
		else cout << "2\n";
	}

	return 0;
}