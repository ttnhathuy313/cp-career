#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;

int fpow(int a, int b) {
	int ans = 1, t = a;
	while (b) {
		if (b & 1) ans = ans * t % MOD;
		t = t * t % MOD;
		b >>= 1;
	}
	return ans;
}
int C(int x,int y) {
	if(x < 0 || y < 0 || x - y < 0) return 0;
	int a = 1, b = 1;
	for (int i = 1; i <= y; i++)
		a = a * (x - i + 1) % MOD,
		b = b * i % MOD;
	return a * fpow(b, MOD - 2) % MOD;
}
int32_t main() {
	int n,m;
	cin >> n >> m;
	if (n == 2) cout << 0 << endl;
	else cout << C(m, n - 1) * (n - 2) % MOD * fpow(2, n-3) % MOD << endl;
	return 0;
}