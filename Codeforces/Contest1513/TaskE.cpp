#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, MOD = 1e9 + 7;
int n, a[N], fac[N];
map <int, int> cnt;

void mul(int &a, int b) {
	a = a * b % MOD;
}

int modPow(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) mul(res, x);
		mul(x, x);
		y >>= 1;
	}
	return res;
}

int inverse(int x) {
	x %= MOD;
	return modPow(x, MOD - 2);
}

int C(int k, int n) {
	if (k > n) return 0;
	int res = fac[n];
	mul(res, inverse(fac[k] * fac[n - k]));
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n;
	int source = 0, sum = 0, sink = 0;
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
		sum += a[i];
		fac[i] = fac[i - 1];
		mul(fac[i], i);
	}
	if (sum % n != 0) {
		cout << 0 << endl;
		return 0;
	} else {
		sum /= n;
	}
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > sum) source++;
		if (a[i] < sum) sink++;
		if (cnt[a[i]] > 0 && a[i] != sum) {
			mul(ans, inverse(fac[cnt[a[i]]]));
			cnt[a[i]] = 0;
		}
	}
	if (min(source, sink) <= 1) {
		mul(ans, fac[n]);
		for (int i = 1; i <= n; ++i) {
			if (cnt[a[i]] > 0) {
				mul(ans, inverse(fac[cnt[a[i]]]));
				cnt[a[i]] = 0;
			}
		}
		cout << ans << endl;
		return 0;
	}
	mul(ans, 2);
	mul(ans, fac[source]);
	mul(ans, fac[sink]);
	// source + sink + 1 places
	mul(ans, C(source + sink, n));
	cout << ans << endl;

	return 0;
}