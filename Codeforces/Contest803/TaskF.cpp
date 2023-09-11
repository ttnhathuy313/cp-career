#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7, N = 1e5 + 5;
bitset <N> bs;
vector <int> primes;
int n, cnt[N];
 
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

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);
	sieve();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	int res = 0;
	for (int i = 1; i <= N - 5; ++i) {
		int sz = 0;
		for (int j = i; j <= N - 5; j += i) sz += cnt[j];
		res += mobius(i) * ((modPow(2, sz) - 1 + MOD) % MOD);
		res = (res + MOD) % MOD;
	}
	cout << res << endl;

	return 0;
}