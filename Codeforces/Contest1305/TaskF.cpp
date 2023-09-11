#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
bitset <(int)1e6 + 5> bs;
int n, a[N];
vector <int> primes, factorize[3 * N];

void sieve(int A) {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= A; ++i) if (bs[i]) {
		for (int j = i * i; j <= A; j += i) bs[j] = false;
		primes.push_back(i);
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n;
	set <int> Try; Try.clear();
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int l_range = max(1LL, a[1] - n), r_range = a[1] + n, bound = sqrt(r_range);
	sieve(bound);
	for (int i : primes) {
		for (int j = max(i * i, (l_range % i == 0 ? l_range : l_range + i - (l_range % i))); j <= r_range; j += i)
			factorize[j - l_range].push_back(i);
	}
	for (int i = l_range; i <= r_range; ++i) {
		int cur = i;
		for (int d : factorize[i - l_range]) while (cur % d == 0) cur /= d;
		if (cur > 1) factorize[i - l_range].push_back(cur);
	}
	for (int i = -n; i <= n; ++i) if (a[1] + i > 0) {
		vector <int> D = factorize[a[1] + i - l_range];
		for (int v : D) {
			Try.insert(v);
		}
	}
	int res = (int)1e9;
	for (int V : Try) {
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans += min((a[i] >= V ? a[i] % V : (int)1e9), V - (a[i] % V));
			if (ans > res) break;
		}
		res = min(res, ans);
	}
	cout << res << endl;

	return 0;
}