#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int P = 1e5 + 5, N = 305, MOD = 1e9 + 7;
bitset <P> bs;
int n, a[N], fac[N], C[N][N];
vector <int> primes;

void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= P - 5; ++i) if (bs[i]) {
		for (int j = i * i; j <= P - 5; j += i) bs[j] = false;
		primes.push_back(i);
	}
}

vector <ii> factorize(int n) {
	vector <ii> ret; ret.clear();
	int PF = primes[0], PF_idx = 0;
	while (PF * PF <= n) {
		int cnt = 0;
		while (n % PF == 0) {
			cnt++;
			n /= PF;
		}
		if (cnt) ret.push_back({PF, cnt});
		PF = primes[++PF_idx];
	}
	if (n > 1) ret.push_back({n, 1});
	return ret;
}

void add(int &a, int b) {
	a = (a + b) % MOD;
}
void mult(int &a, int b) {
	a = a * b % MOD;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	sieve();
	map <vector <int>, int> mp;
	mp.clear();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		vector <ii> d = factorize(a[i]);
		vector <int> represent; represent.clear();
		for (ii v : d) if (v.second & 1) 
			represent.push_back(v.first);
		sort(represent.begin(), represent.end());
		mp[represent]++;
	}
	n = 0;
	memset(a, 0, sizeof a);
	for (auto v : mp) {
		a[++n] = v.second;
	}
	cerr << n << endl;
	for (int i = 1; i <= n; ++i) cerr << a[i] << ' '; cerr << endl;
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = fac[i - 1];
		mult(fac[i], i);
	}
	

	return 0;
}