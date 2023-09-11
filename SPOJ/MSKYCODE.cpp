#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e4 + 5;
int cnt[N], a[N], n, f[N];
bitset <N + 5> bs;
vector <int> primes;

void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= N; ++i) {
		for (long long j = i * i; j <= N; j += i) bs[j] = false;
		primes.push_back(i);
	}
}

vector <int> Factorize(int a) {
	int PF_idx = 0, PF = primes[0];
	vector <int> res; res.clear();
	while (PF * PF <= a) {
		int cnt = 0;
		while (a % PF == 0) {
			cnt++;
			a /= PF;
		}
		if (cnt == 1) res.push_back(PF);
		else if (cnt > 1) res.push_back(-1);
		PF = primes[++PF_idx];
	}
	if (a) res.push_back(a);
	return res;
}

void solve() {
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i <= n; ++i) { 
		cin >> a[i];
		cnt[a[i]]++;
	}
	memset(f, 0, sizeof f);
	int mx = 0;
	int res = 0;
	for (int i = 1; i <= n; ++i) mx = max(mx, a[i]);
	for (int i = 2; i <= mx; ++i) {
		vector <int> d = Factorize(i);
		bool ok = true;
		for (int k = 0; k < d.size(); ++k) {
			if (d[k] == -1) ok = false;
		}
		if (!ok) continue;
		for (int j = 1; j * i <= mx; j++) {
			f[i] += cnt[i * j];
		}
		if (((int)d.size()) & 1) res -= f[i] * (f[i] - 1) * (f[i] - 2) * (f[i] - 3);
		else res += f[i] * (f[i] - 1) * (f[i] - 2) * (f[i] - 3);
	}
	res += n * (n - 1) * (n - 2) * (n - 3);
	res /= 24;
	cout << res << endl;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("MSKYCODE.INP", "r", stdin);
	freopen("MSKYCODE.OUT", "w", stdout);
	
	sieve();
	while (cin >> n) {
		solve();
	}

	return 0;
}