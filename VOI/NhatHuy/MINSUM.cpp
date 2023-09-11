#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'

const int M = 1e5 + 5;
bitset <M> bs;
vector <int> primes;
map <int, int> mp;

void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= M - 5; ++i) {
		for (int j = i * i; j <= M - 5; j += i) bs[j] = false;
		primes.push_back(i);
	}
}

vector <int> factorize(int n) {
	vector <int> ret; ret.clear();
	int PF = primes[0], PF_idx = 0;
	while (PF * PF <= n) {
		if (n % PF == 0)
			ret.push_back(PF);
		while (n % PF == 0) {
			mp[PF]++;
			n /= PF;
		}
		PF = primes[++PF_idx];
	}
	if (n > 1) {
		mp[n]++;
		ret.push_back(n);
	}
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("MINSUM.INP", "r", stdin);
	freopen("MINSUM.OUT", "w", stdout);

	sieve();
	int tc;
	cin >> tc;
	while (tc--) {
		int A, B;
		cin >> A >> B;
		mp.clear();
		vector <int> d1 = factorize(A), d2 = factorize(B);
		vector <int> diff; diff.clear();
		set <int> common; common.clear();
		for (int v : d1) common.insert(v);
		for (int v : d2) common.insert(v);
		for (int v : common) if (mp[v] & 1) {
			diff.push_back(v);
		}
		int n = diff.size();
		int res = (int)1e18, id1 = -1, id2 = -1;
		for (int mask = 0; mask < (1 << n); ++mask) {
			int a = 1, b = 1;
			for (int i = 0; i < n; ++i) 
				if (mask & (1 << i)) a *= diff[i];
				else b *= diff[i];
			if (res > a + b) {
				res = a + b;
				id1 = a; id2 = b;
			}
		}
		cout << id1 << ' ' << id2 << endl;
	}	

	return 0;
}