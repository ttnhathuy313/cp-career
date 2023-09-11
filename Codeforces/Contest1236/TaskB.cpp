#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

ll mod_Pow(ll a, ll n, ll m) {
	a %= m;
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % m;
		a = a * a % m;
		n >>= 1;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("TaskB.inp", "r", stdin);
	// freopen("TaskB.out", "w", stdout);

	ll n, m;
	cin >> n >> m;
	ll a = mod_Pow(2, m, MOD);
	ll res = mod_Pow((a - 1 + MOD) % MOD, n, MOD);
	cout << res << endl;

	return 0;
}