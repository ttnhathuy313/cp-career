#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'
typedef pair <int, int> ii;

const int N = 1e5 + 5;
const long long INF64 = 3e18;
int res[N], t, savelog[N], mu[N];
bitset <N> bs;
vector <int> primes;

void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	for (int i = 2; i <= N - 5; ++i) if (bs[i]) {
		for (int j = i * 2; j <= N - 5; j += i) bs[j] = false;
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
			d.push_back(PF);
			cnt++;			
		}
		PF = primes[++PF_idx];
	}
	if (a > 1) d.push_back(a);
	return d;
}
 
int mobius(int a) {
	if (~mu[a]) return mu[a];
	if (a == 1) return mu[a] = 1;
	vector <int> d = PrimeFactorization(a);
	int pre = -1;
	for (int v : d) {
		if (v == pre) return mu[a] = 0;
		pre = v;
	}
	if ((int)d.size() & 1) return mu[a] = -1;
	else return mu[a] = 1;
}

long long binPow(long long a, int b){
    long long res = 1;
    while (b){
        if (b & 1){
            if (res < INF64 / a) res *= a;
            else return INF64;
        }
        if (b > 1){
            if (a < INF64 / a) a *= a;
            else return INF64;
        }
        b >>= 1;
    }
    return res;
}

int get_sqrt(long long n){
    int l = 1, r = 1000000000;
    while (l < r - 1){
        int m = (l + r) / 2;
        if (m * 1ll * m <= n)
            l = m;
        else
            r = m;
    }
    return (r * 1ll * r <= n ? r : l);
}


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	sieve();
	cin >> t;
	vector <ii> q; q.clear();
	for (int i = 1; i <= t; ++i) {
		int d;
		cin >> d;
		q.push_back({d, i});
	}
	sort(q.begin(), q.end(), greater <ii>());
	savelog[3] = 1000000;
	savelog[4] = 31622;
	savelog[5] = 3981;
	memset(mu, -1, sizeof mu);
	for (int i = 1; i <= 64; ++i) mu[i] = mobius(i);
	for (int i = 6; i <= 100; ++i) savelog[i] = 1000;
	for (ii d : q) {
		int id = d.second;
		int n = d.first;
		savelog[2] = get_sqrt(n);
		res[id] = n - savelog[2];
		int pw = 63 - __builtin_clzll(n);
		for (int i = 3; i <= pw; ++i) {
			if (mu[i] == 0) continue;
			while (binPow(savelog[i], i) > n)
				savelog[i]--;
			res[id] += (savelog[i] - 1) * mu[i];
		}
	}
	for (int i = 1; i <= t; ++i) {
		cout << res[i] << endl;
	}

	return 0;
}