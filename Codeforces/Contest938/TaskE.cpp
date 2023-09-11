#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, a[N];
map <int, int> cnt;

int modPow(int x, int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return ret;
}

void add(int &a, int b) {
	a = (a + b) % MOD;
}
void mul(int &a, int b) {
	a = a * b % MOD;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n;
	int mx = 0, fac = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
		mul(fac, i);
		mx = max(mx, a[i]);
	}
	int sm = 0, res = 0;
	for (auto d : cnt) {
		int tmp = d.first, l = d.second;
		if (tmp == mx) continue;
		mul(tmp, l); mul(tmp, fac);
		mul(tmp, modPow(n - sm, MOD - 2));
		add(res, tmp);
		sm += l;
	}
	cout << res << endl;

	return 0;
}