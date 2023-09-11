#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e6 + 5;
bitset <N> bs;
vector <int> primes;
 
void sieve() {
	bs.set();
	bs[0] = bs[1] = false;
	for (int i = 2; i <= N - 5; ++i) if (bs[i]) {
		for (int j = i * i; j <= N - 5; j += i) bs[j] = false;
		primes.push_back(i);
	}
}
 
int phi(int a) {
	int PF = primes[0], PF_idx = 0;
	int res = a;
	while (PF * PF <= a) {
		if (a % PF == 0) {
			while (a % PF == 0) a /= PF;
			res -= res / PF;
		}
		PF = primes[++PF_idx];
	}
	if (a > 1) res -= res / a;
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	sieve();
	int tc;
	cin >> tc;
	while (tc--) {
		int a, m;
		cin >> a >> m;
		int g = __gcd(a, m);
		cout << phi(m / g) << endl;
	}

	return 0;
}