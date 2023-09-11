#include <bits/stdc++.h>

using namespace std;

const int N = 200005, can = 505;
int n, m, phi, dp[N], trace[N], res[N], c[N];
bool banned[N];
vector <int> primes, haveGcd[N], product;
bitset <can> bs;

void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	for (int i = 2; i <= 500; ++i) if (bs[i]) {
		for (int j = i * i; j <= 500; j += i) bs[j] = false;
		primes.push_back(i);
	}
}

void calc_phi() {
	phi = m;
	int PF = primes[0], PF_idx = 0, x = m;
	while (PF * PF <= x) {
		if (x % PF == 0) phi = phi - phi / PF;
		while (x % PF == 0) x /= PF;
		PF = primes[++PF_idx];
	}
	if (x > 1) phi = phi - phi / x;
}

int modPow(int x, int y, int m) {
	int res = 1;
	x %= m;
	while (y) {
		if (y & 1) res = 1ll * res * x % m;
		x = 1ll * x * x % m;
		y >>= 1;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.inp", "r", stdin);
	freopen("TaskC.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		banned[x] = true;
	}
	sieve();
	calc_phi();
	for (int i = 0; i < m; ++i) if (!banned[i]) {
		haveGcd[__gcd(i, m)].push_back(i);
	}
	memset(trace, -1, sizeof trace);
	for (int i = 1; i <= m; ++i) {
		dp[i] = haveGcd[i].size();
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 2 * i; j <= m; j += i) {
			if (dp[i] + (int)haveGcd[j].size() > dp[j]) {
				dp[j] = dp[i] + (int)haveGcd[j].size();
				trace[j] = i;
			}
		}
	}
	int best = -1, val = 0;
	for (int i = 1; i <= m; ++i) if (val < dp[i]) {
		val = dp[i];
		best = i;
	}
	while (~best) {
		for (int d : haveGcd[best]) product.push_back(d);
		best = trace[best];
	}
	product.push_back(1);
	reverse(product.begin(), product.end());
	int sz = (int)product.size() - 1;
	cout << sz << endl;
	for (int i = 0; i < product.size() - 1; ++i) {
		int g = __gcd(product[i], product[i + 1]);
		res[i + 1] = 1ll * modPow(product[i] / g, phi - 1, m) * (product[i + 1] / g) % m;
	}
	c[0] = 1;
	for (int i = 1; i <= sz; ++i) cout << res[i] << ' ';
	for (int i = 1; i <= sz; ++i) {
		c[i] = c[i - 1] * res[i] % m;
	}

	return 0;
}