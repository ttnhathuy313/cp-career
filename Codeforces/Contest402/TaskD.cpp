#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5005, A = 1e5 + 5;
int n, a[N], b[N], m, g[N], f[N], c[N];
bitset <A> bs;
vector <int> primes;

void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= A - 5; ++i) if (bs[i]) {
		for (int j = i * i; j <= A - 5; j += i) bs[j] = false;
		primes.push_back(i);
	}
}

vector <int> factorize(int a) {
	int PF_idx = 0, PF = primes[0];
	vector <int> res; res.clear();
	while (PF * PF <= a) {
		while (a % PF == 0) {
			res.push_back(PF);
			a /= PF;
		}
		PF = primes[++PF_idx];
	}
	if (a > 1) res.push_back(a);
	return res;
}

int val(int a) {
	if (a == 1) return 0;
	vector <int> D = factorize(a);
	int ret = 0;
	for (int v : D) {
		if (binary_search(b + 1, b + 1 + m, v)) ret--;
		else ret++;
	}
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	sieve();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i)
		cin >> b[i];
	g[1] = a[1];
	for (int i = 2; i <= n; ++i) {
		g[i] = __gcd(a[i], g[i - 1]);
	}
	for (int i = 1; i <= n; ++i) c[i] = val(g[i]);
	int res = 0;
	for (int i = n; i >= 1; --i) {
		f[i] = val(g[i]) * i;
		for (int j = i + 1; j <= n; ++j) {
			f[i] = min(f[i], f[j] + (c[i] - c[j]) * i);
		}
		res = min(res, f[i]);
	}
	cerr << res << endl;
	res = -res;
	for (int i = 1; i <= n; ++i) res += val(a[i]);
	cout << res << endl;

	return 0;
}