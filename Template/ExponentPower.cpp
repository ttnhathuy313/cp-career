#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll Pow(ll a, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

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
	return 0;
}