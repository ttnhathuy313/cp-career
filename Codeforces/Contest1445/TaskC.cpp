#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e6 + 5;
bitset <N> bs;
vector <int> primes;

void sieve() { //Remember to call at the beginning
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 1; i < N; ++i) if (bs[i]) {
		for (int j = i * i; j < N; j += i) bs[j] = false;
		primes.push_back(i);
	}
}

vector <ii> PrimeFactorize(int a) {
	vector <ii> ret; ret.clear();
	int PF = primes[0], PF_idx = 0;
	while (PF * PF) {
		if (a % PF == 0) {
			int v = 1;
			while (a % PF == 0) {
				v *= PF;
				a /= PF;
			}
			ret.push_back({PF, v});
		}
		PF = primes[++PF_idx];
	}
	if (a > 1) ret.push_back({a, a});
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	sieve();
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		vector <ii> d = PrimeFactorize(b);
		int p = a, res = 1;
		for (ii v : d) {
			int u = 1;
			while (a % v.first == 0) {
				u *= v.first;
				a /= v.first;
			}
			if (u < v.second) res = p;
			else {
				res = max(res, p / u * v.second / v.first);
			}
		}
		cout << res << endl;
	}

	return 0;
}