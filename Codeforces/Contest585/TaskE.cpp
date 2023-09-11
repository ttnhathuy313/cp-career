#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;
typedef long long ll;

const int MOD = 1e9 + 7, N = 5e5 + 5, A = 1e7 + 5, P = 4005;
bitset <N> bs;
vector <int> primes;
int n, cnt[A], a[N], p[N];
 
void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	for (int i = 2; i <= P - 5; ++i) if (bs[i]) {
		for (int j = i * 2; j <= P - 5; j += i) bs[j] = false;
		primes.push_back(i);
	}
}

vector <int> PrimeFactorization(int a) {
	int PF_idx = 0, PF = primes[0];
	vector <int> d; d.clear();
	while (PF * PF <= a) {
		int cnt = 0;
		while (a % PF == 0) {
			a /= PF;
			cnt++;			
		}
		if (cnt) d.push_back(PF);
		PF = primes[++PF_idx];
	}
	if (a > 1) d.push_back(a);
	return d;
}
 
int mobius(int a) {
	if (a == 1) return 1;
	vector <int> d = PrimeFactorization(a);
	if ((int)d.size() & 1) return -1;
	else return 1;
}

vector <ii> mobFactor(int a) {
	vector <int> d;
	vector <ii> res;
	res.clear(); d = PrimeFactorization(a);
	int sz = d.size();
	for (int mask = 0; mask < (1 << sz); ++mask) {
		int t = 1;
		for (int i = 0; i < sz; ++i) if (mask & (1 << i))
			t *= d[i];
		res.push_back(ii(t, __builtin_popcount(mask)));
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	sieve();
	cin >> n;
	p[0] = 1;
	for (int i = 1; i <= n + 155; ++i) {
		p[i] = 1LL * p[i - 1] * 2 % MOD;
	}
	ll res = 0, overall = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		vector <ii> D = mobFactor(a[i]);
		for (ii v : D) {
			res += ((p[cnt[v.first] + 1] - p[cnt[v.first]]) * ((v.second & 1) ? -1 : 1) + MOD) % MOD;
			res %= MOD;
			if (res < 0) res = (res + MOD) % MOD;
			else res %= MOD;
			cnt[v.first]++;
		}
	}
	for (int i = 1; i <= n; ++i) {
		vector <ii> D = mobFactor(a[i]);
		ll tmp = res;
		for (ii v : D) {
			tmp -= ((p[cnt[v.first]] - p[cnt[v.first] - 1]) * ((v.second & 1) ? -1 : +1) + MOD) % MOD;
			if (tmp < 0) tmp = (tmp + MOD) % MOD;
			else tmp %= MOD;
		}
		overall += (res - 2 * tmp > 0 ? res - 2 * tmp : res - 2 * tmp + 2 * MOD);
		overall %= MOD;
	}
	cout << overall << endl;

	return 0;
}