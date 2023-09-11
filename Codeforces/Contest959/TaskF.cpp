#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, LOGA = 20, MOD = 1e9 + 7;
int a[N], n, q, p2[N];
vector <int> basises[N];

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.inp", "r", stdin);
	freopen("TaskF.out", "w", stdout);

	p2[0] = 1;
	for (int i = 1; i <= N - 1; ++i) p2[i] = p2[i - 1] * 2 % MOD;

	cin >> n >> q;
	vector <int> basis(LOGA, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		int A = a[i];
		for (int j = 0; j < LOGA; ++j) {
			if ((A & (1 << j)) == 0) continue;
			if (!basis[j]) {
				basis[j] = A;
				break;
			}
			A ^= basis[j];
		}
		basises[i] = basis;
	}
	while (q--) {
		int l, x;
		cin >> l >> x;
		basis = basises[l];
		bool ok = true;
		int d = 0;
		for (int i = 0; i < LOGA; ++i) if (basis[i]) d++;
		for (int i = 0; i < LOGA; ++i) {
			if ((x & (1 << i)) == 0) continue;
			if (!basis[i]) ok = false;
			x ^= basis[i];
		}
		if (!ok) cout << 0 << endl;
		else cout << p2[l - d] << endl;
	}

	return 0;
}