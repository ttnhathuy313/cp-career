#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5, MOD = 1e9 + 7, A = 1e6 + 5;
int n, a[N], dp[N], cnt[A], div[N], ans[N], mob[N];
bitset <A> bs;
vector <int> primes;

void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= A - 5; ++i) {
		for (int j = i * i; j <= A - 5; j += i) bs[j] = false;
		primes.push_back(i);
	}
}

int mobius(int x) {
	int PF_idx = 0, PF = primes[PF_idx], cnt = 0;
	while (PF * PF <= x) {
		if (x % PF == 0) cnt++;
		while (x % PF == 0) {
			x /= PF;
		}
		PF = primes[++PF_idx];
	}
	if (x > 1) cnt++;
	if (cnt & 1) return -1;
	else return 1;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	sieve();
	cerr << mobius(2) << endl;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1] * 2 % MOD;
	}
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i] * i % MOD;
	}
	for (int i = 1; i <= A - 5; ++i) {
		for (int j = i; j <= A - 5; j += i) {
			div[i] += cnt[j];
		}
	} // AlogA


	return 0;
}