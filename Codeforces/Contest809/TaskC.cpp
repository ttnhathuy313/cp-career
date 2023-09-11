#include <bits/stdc++.h>

using namespace std;
#define int long long
#define rep(i, a) for (int i = 0; i < a; ++i)
#define forn(i, a, b) for (int i = a; i <= b; ++i)
typedef vector <int> vi;

const int N = 50, MOD = 1e9 + 7;
int dp[N][2][2][2][2][2], val[N][2][2][2][2][2];

vi dig(int a) {
	vi ret; ret.clear();
	while (a) {
		ret.push_back(a % 2);
		a /= 2;
	}
	while (ret.size() < 32)
		ret.push_back(0);
	ret.push_back(0);
	reverse(ret.begin(), ret.end());
	return ret;
}

void solve() {
	int x11, x22, y11, y22, kk;
	cin >> x11 >> y11 >> x22 >> y22 >> kk; x11--; x22--; y11--; y22--;
	vi x1 = dig(x11), x2 = dig(x22), y1 = dig(y11), y2 = dig(y22), k = dig(kk);
	// number index from 1 to 32, dummy at beginning
	memset(dp, 0, sizeof dp);
	dp[0][0][0][0][0][0] = 1;
	memset(val, 0, sizeof val);
	int n = 32;
	rep(i, n) rep(fx1, 2) rep(fx2, 2) rep(fy1, 2) rep(fy2, 2) rep(fk, 2) {
		int vall = dp[i][fx1][fx2][fy1][fy2][fk];
		if (vall == 0) continue;
		int sum = val[i][fx1][fx2][fy1][fy2][fk];
		// cerr << i << ' ' << fx2 << ' ' << fx2 << ' ' << fy1 << ' ' << fy2 << ' ' << fk << " : " << sum << endl; 
		int lx = (fx1 ? 0 : x1[i + 1]), rx = (fx2 ? 1 : x2[i + 1]);
		int ly = (fy1 ? 0 : y1[i + 1]), ry = (fy2 ? 1 : y2[i + 1]);
		int lk = 0, rk = (fk ? 1 : k[i + 1]);
		forn(nx, lx, rx) forn(ny, ly, ry) {
			int nk = nx ^ ny;
			if (nk > rk) continue;
			(dp[i + 1][fx1 | (nx > x1[i + 1])][fx2 | (nx < x2[i + 1])][fy1 | (ny > y1[i + 1])][fy2 | (ny < y2[i + 1])]
			[fk | (nk < k[i + 1])] += vall) %= MOD;
			(val[i + 1][fx1 | (nx > x1[i + 1])][fx2 | (nx < x2[i + 1])][fy1 | (ny > y1[i + 1])][fy2 | (ny < y2[i + 1])]
			[fk | (nk < k[i + 1])] += sum + vall * nk * (1 << (n - i - 1))) %= MOD;
			
		}
	}
	int res = 0;
	rep(fx1, 2) rep(fx2, 2) rep(fy1, 2) rep(fy2, 2) {
		res = (res + val[n][fx1][fx2][fy1][fy2][1] + dp[n][fx1][fx2][fy1][fy2][1]) % MOD;
	}
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}