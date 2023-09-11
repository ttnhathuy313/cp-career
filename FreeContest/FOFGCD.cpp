#include <bits/stdc++.h>

using namespace std;
#define __builtin_popcount __builtin_popcountll
#define int long long
typedef pair <int, int> ii;

const int N = 1e6 + 5;
int a, b;
bitset <N + 5> bs;
vector <int> primes, D;
vector <ii> divs;

void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= N - 5; ++i) if (bs[i]) {
		for (int j = i * i; j <= N - 5; j += i) bs[j] = false;
		primes.push_back(i);
	}
}

vector <int> factorize(int n) {
	vector <int> res; res.clear();
	int PF_idx = 0, PF = primes[0];
	while (PF * PF <= n) {
		int d = 0;
		while (n % PF == 0) {
			d++;
			n /= PF;
		}
		if (d) res.push_back(PF);
		PF = primes[++PF_idx];
	}
	if (n > 1) res.push_back(n);
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("FOFGCD.INP", "r", stdin);
	// freopen("FOFGCD.OUT", "w", stdout);

	sieve();
	cin >> a >> b;
	D = factorize(a);
	int sz = D.size();
	for (int mask = 0; mask < (1 << sz); ++mask) {
		int num = 1;
		for (int i = 0; i < sz; ++i) if (mask & (1 << i))
			num *= D[i];
		divs.push_back({num, __builtin_popcount(mask)});
	}
	int res = 0;
	int g = __gcd(a, b);
	if (g > 1) {
		a /= g; b /= g;
	}
	while (b > 1) {
		int l = 1, r = b, ans = -1;
		int upSum = 0;
		for (ii div : divs) if (__gcd(div.first, a) == div.first) {
			int mob = (div.second & 1 ? -1 : 1);
			upSum += (b / div.first) * mob;
		}
		while (l <= r) {
			int mid = (l + r) >> 1;
			int downSum = 0;
			for (ii div : divs) if (__gcd(div.first, a) == div.first) {
				int mob = (div.second & 1 ? -1 : 1);
				downSum += ((mid - 1) / div.first) * mob;
			}
			if (upSum - downSum == b - mid + 1) {
				ans = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		res += b - ans;
		b = ans;
		// cerr << a << ' ' << b << endl;
		if (ans == 1) break;
		b--; res++;
		int g = __gcd(a, b);
		a /= g; b /= g;
		// cerr << "	" << a << ' ' << b << endl;
	}
	cout << res + 1 << endl;

	return 0;
}