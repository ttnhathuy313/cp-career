#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

const int N = 1e6 + 5, A = 1e6;
int a[N], n, k;
bitset <A + 5> bs;
vector <int> primes;
vector <ii> D;
vector <int> res;

void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= A; ++i) {
		for (int j = i * i; j <= A; j += i) bs[j] = false;
		primes.push_back(i);
	}
}

vector <ii> Factorization(int c) {
	int PF_idx = 0, PF = primes[0];
	vector <ii> ret; ret.clear();
	while (PF * PF <= c) {
		int cnt = 0;
		while (c % PF == 0) {
			c /= PF;
			cnt++;
		}
		if (cnt) ret.push_back(ii(PF, cnt));
		PF = primes[++PF_idx];
	}
	if (c > 1) ret.push_back(ii(c, 1));
	return ret;
}

main() {
	srand(03012003);
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.inp", "r", stdin);
	freopen("TaskF.out", "w", stdout);
	double t = clock();
	sieve();
	cin >> n;
	k = n / 2;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	random_shuffle(a + 1, a + 1 + n);
	int res = 0;
	while ((clock() - t) / CLOCKS_PER_SEC < 2) {
		int id = Rand(1, n);
		D = Factorization(a[id]);
		unordered_map <int, int> cnt;
		cnt.clear();
		for (int i = 1; i <= n; ++i) {
			cnt[__gcd(a[i], a[id])]++;
		}
		for (ii pp : D) {
			int p = pp.first;
			function <void(int, int)> calc = [&](int it, int val) {
				if (it == D.size()) {
					for (int i = 0; i < pp.second; ++i) val *= p;
					for (int i = pp.second - 1; i >= 0; --i) {
						cnt[val / p] += cnt[val];
						if (i > 0) val /= p;
					}
					return;
				}
				if (D[it].first == p) {
					calc(it + 1, val);
					return;
				}
				for (int i = 0; i <= D[it].second; ++i) {
					calc(it + 1, val);
					if (i + 1 <= D[it].second) val *= D[it].first;
				}
			};
			calc(0, 1);
		}
		for (auto p : cnt) if (p.second * 2 >= n) {
			res = max(res, p.first);
		}
	}
	cout << res << endl;

	return 0;
}