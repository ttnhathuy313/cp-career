#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 17;
int a[N];

int lcm(int a, int b) {
	return a * b / __gcd(a, b);
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("NGM2.INP", "r", stdin);
	freopen("NGM2.OUT", "w", stdout);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> a[i];
	}
	int res = 0;
	for (int mask = 0; mask < (1 << k); ++mask) {
		int val = 1;
		for (int i = 0; i < k; ++i) if (mask & (1 << i)) {
			val = lcm(val, a[i + 1]);
		}
		if (__builtin_popcount(mask) % 2 == 0) res += n / val;
		else res -= n / val;
	}
	cout << res << endl;

	return 0;
}