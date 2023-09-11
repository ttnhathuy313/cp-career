#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7, N = 1e5 + 5;
bitset <N> bs;
vector <int> primes;
 
void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	for (int i = 2; i <= N - 5; ++i) {
		for (int j = i * i; j <= N - 5; j += i) bs[j] = false;
		primes.push_back(i);
	}
}

int mobius(int a) {
	if (a == 1) return 1;
	int PF_idx = 0, PF = primes[0];
	vector <int> d; d.clear();
	while (PF * PF <= a) {
		int cnt = 0;
		while (a % PF == 0) {
			a /= PF;
			cnt++;
		}
		if (cnt > 1) return 0;
		if (cnt == 1) d.push_back(PF);
		PF = primes[++PF_idx];
	}
	if (a) d.push_back(a);
	if ((int)d.size() & 1) return -1;
	else return 1;
}

int modPow(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = res * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return res;
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	sieve();
	int x, y;
	cin >> x >> y;
	if (y % x != 0) {
		cout << 0 << endl;
		return 0;
	}
	int n = y / x, res = 0;
	int sz = (int)sqrt(n);
	bool square = (sz * sz == n);
	for (int i = 1; i <= sqrt(n); ++i) if (n % i == 0) {
		res += mobius(n / i) * modPow(2, i - 1);
		res = (res + MOD) % MOD;
		if (!(square && i == sz))
			res += mobius(i) * modPow(2, (n / i) - 1);
		res = (res + MOD) % MOD;

	}
	cout << res << endl;

	return 0;
}