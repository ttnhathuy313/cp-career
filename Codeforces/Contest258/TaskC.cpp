#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5, MOD = 1e9 + 7;
int n, a[N], pref[N];
vector <int> primes;
bitset <N> bs;

void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= N - 5; ++i) if (bs[i]) {
		for (int j = i * i; j <= N - 5; ++j) bs[j] = false;
		primes.push_back(i);
	}
}
 
vector <ii> factorize(int a) {
	int PF_idx = 0, PF = primes[0];
	vector <ii> res; res.clear();
	while (PF * PF <= a) {
		int cnt = 0;
		while (a % PF == 0) {
			a /= PF;
			res.push_back({PF, 1});
			cnt++;
		}
		PF = primes[++PF_idx];
	}
	if (a > 1) res.push_back({a, 1});
	return res;
}

int modPow(int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return ret;
}

void mult(int &a, int b) {
	a = a * b % MOD;
}

void add(int &a, int b) {
	a = (a + b) % MOD;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pref[a[i]]++;
	}
	int res = 0;
	for (int i = 1; i <= N - 5; ++i)
		pref[i] += pref[i - 1];
	for (int i = 1; i <= N - 5; ++i) {
		int tmp = 1;
		vector <int> divisors; divisors.clear();
		for (int j = 1; j <= sqrt(i); ++j) if (i % j == 0) {
			divisors.push_back(j);
			if (i / j != j) divisors.push_back(i / j);
		}
		sort(divisors.begin(), divisors.end());
		for (int k = 0; k < divisors.size() - 1; ++k) {
			int cur = modPow(k + 1, pref[divisors[k + 1] - 1] - pref[divisors[k] - 1]);
			mult(tmp, cur);
		}
		mult(tmp, modPow((int)divisors.size(), pref[N-5] - pref[i - 1]) - modPow((int)divisors.size() - 1, pref[N-5] - pref[i - 1]) + MOD);
		add(res, tmp);
	}
	cout << res << endl;

	return 0;
}