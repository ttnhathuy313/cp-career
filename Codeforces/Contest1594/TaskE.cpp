#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int MOD = 1e9 + 7, N = 2e5 +5 ;
int n, save[N], near[10][10], tot, k;
map <int, int> attach, in_path;
map <ii, int> memo;
map <string, int> color;
set <int> adj[N];

int modPow(int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		y >>= 1LL;
	}
	return ret;
}

int Left(int x) {
	return (x << 1);
}
int Right(int x) {
	return (x << 1) + 1;
}

void init() {
	int res = 1, p2 = 1;
	save[1] = 1;
	for (int i = 2; i <= k; ++i) {
		p2 = p2 * 2LL;
		res = res * modPow(4LL, p2) % MOD;
		res %= MOD;
		save[i] = res;
	}
	color["white"] = 0;
	color["yellow"] = 1;
	color["green"] = 2;
	color["blue"] = 3;
	color["red"] = 4;
	color["orange"] = 5;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			near[i][j] = 1;
		}
	}
	for (int i = 0; i < 6; i += 2) {
		near[i][i] = near[i + 1][i + 1] = 0;
		near[i][i + 1] = near[i + 1][i] = 0;
	}
}

int dfs(int u, int must_color, int depth) {
	if (depth == k) return 1;
	if (memo.find({u, must_color}) != memo.end()) return memo[{u, must_color}];
	int ret = 1, cnt = 2;
	if (in_path[Left(u)]) {
		cnt--;
		if (attach.find(Left(u)) == attach.end()) {
			int sum = 0;
			for (int i = 0; i < 6; ++i) if (near[must_color][i]) {
				sum = (sum + dfs(Left(u), i, depth + 1)) % MOD;
			}
			ret = ret * sum % MOD;
		} else {
			int cc = attach[Left(u)];
			if (near[must_color][attach[Left(u)]]) ret = ret * dfs(Left(u), cc, depth + 1) % MOD;
			else ret = 0;
		}
	}
	if (in_path[Right(u)]) {
		cnt--;
		if (attach.find(Right(u)) == attach.end()) {
			int sum = 0;
			for (int i = 0; i < 6; ++i) if (near[must_color][i]) {
				sum = (sum + dfs(Right(u), i, depth + 1)) % MOD;
			}
			ret = ret * sum % MOD;
		} else {
			int cc = attach[Right(u)];
			if (near[must_color][attach[Right(u)]]) ret = ret * dfs(Right(u), cc, depth + 1) % MOD;
			else ret = 0;
		}
	}
	if (cnt == 1 || cnt == 2) {
		ret = ret * save[k - depth] % MOD;
		ret = (ret * 4) % MOD;
	}
	if (cnt == 2) {
		ret = ret * save[k - depth] % MOD;
		ret = (ret * 4) % MOD;
	}
	return memo[{u, must_color}] = ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> k;
	init();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x; string t;
		cin >> x >> t;
		int temp = x;
		while (temp) {
			in_path[temp] = 1;
			temp >>= 1;
		}
		attach[x] = color[t];
	}
	int res = 0;
	if (attach.find(1) != attach.end()) {
		res = dfs(1, attach[1], 1);
	} else {
		for (int i = 0; i < 6; ++i) {
			res = (res + dfs(1, i, 1)) % MOD;
		}
	}
	cout << res << endl;

	return 0;
}