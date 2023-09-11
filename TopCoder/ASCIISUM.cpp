#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 20, MOD = 1e9 + 7;
ll n, dp[N][N * N][2][N], f[40000];

class ASCIISum {
	public : 
	int total(ll n) {
	vector <ll> digit; digit.clear();
	while (n) {
		digit.push_back(n % 10);
		n /= 10;
	}
	n = digit.size();
	digit.push_back(0);
	reverse(digit.begin(), digit.end());
	dp[0][0][0][0] = 1;
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j <= i * 9; ++j) {
			for (ll flag = 0; flag < 2; ++flag)
				for (ll pos = 0; pos <= i; ++pos) {
					ll l = 0, r = (flag ? 9 : digit[i + 1]);
					for (ll nxt = l; nxt <= r; ++nxt) {
						dp[i + 1][j + nxt][flag | (nxt < digit[i + 1])][(pos == 0 && nxt > 0) ? i + 1 : pos] += dp[i][j][flag][pos];
						dp[i + 1][j + nxt][flag | (nxt < digit[i + 1])][(pos == 0 && nxt > 0) ? i + 1 : pos] %= MOD;
					}
			}
		}
	}
	ll res = 0;
	for (ll s = 1; s <= 1500; ++s) {
		ll tmp = s;
		while (1) {
			// cerr << "	" << tmp << endl;
			ll val = 0, t = tmp, numdig = 0;
			while (t) {
				val += t % 10;
				numdig++;
				t /= 10;
			}
			ll nxt = val + numdig * 48;
			if (nxt == tmp) break;
			else tmp = nxt;
		}
		f[s] = tmp;
	}
	for (ll s = 1; s <= n * 9; ++ s) {
		for (ll pre = 1; pre <= n; ++pre) {
			ll len = n - pre + 1;
			ll cnt = dp[n][s][0][pre] + dp[n][s][1][pre]; cnt %= MOD;
			ll val = s + 48 * len;
			res = (res + 1LL * f[val] * cnt % MOD) % MOD;
		}
	}
	return (int)res;
	}
};

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("ASCIISUM.INP", "r", stdin);
	freopen("ASCIISUM.OUT", "w", stdout);

	cin >> n;
	vector <ll> digit; digit.clear();
	while (n) {
		digit.push_back(n % 10);
		n /= 10;
	}
	n = digit.size();
	digit.push_back(0);
	reverse(digit.begin(), digit.end());
	dp[0][0][0][0] = 1;
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j <= i * 9; ++j) {
			for (ll flag = 0; flag < 2; ++flag)
				for (ll pos = 0; pos <= i; ++pos) {
					ll l = 0, r = (flag ? 9 : digit[i + 1]);
					for (ll nxt = l; nxt <= r; ++nxt) {
						dp[i + 1][j + nxt][flag | (nxt < digit[i + 1])][(pos == 0 && nxt > 0) ? i + 1 : pos] += dp[i][j][flag][pos];
						dp[i + 1][j + nxt][flag | (nxt < digit[i + 1])][(pos == 0 && nxt > 0) ? i + 1 : pos] %= MOD;
					}
			}
		}
	}
	ll res = 0;
	for (ll s = 1; s <= 1500; ++s) {
		ll tmp = s;
		while (1) {
			// cerr << "	" << tmp << endl;
			ll val = 0, t = tmp, numdig = 0;
			while (t) {
				val += t % 10;
				numdig++;
				t /= 10;
			}
			ll nxt = val + numdig * 48;
			if (nxt == tmp) break;
			else tmp = nxt;
		}
		f[s] = tmp;
	}
	for (ll s = 1; s <= n * 9; ++ s) {
		for (ll pre = 1; pre <= n; ++pre) {
			ll len = n - pre + 1;
			ll cnt = dp[n][s][0][pre] + dp[n][s][1][pre]; cnt %= MOD;
			ll val = s + 48 * len;
			res = (res + 1LL * f[val] * cnt % MOD) % MOD;
		}
	}
	cout << res << endl;

	return 0;
}