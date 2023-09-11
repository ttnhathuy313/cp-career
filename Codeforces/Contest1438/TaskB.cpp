#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9, N = 1005;

struct Hash {
	int h1, h2;
	Hash() {}
	Hash(int _h1, int _h2) : h1(_h1), h2(_h2) {}
};

Hash operator + (Hash a, Hash b) {
	return Hash((a.h1 + b.h1) % MOD1, (a.h2 + b.h2) % MOD2);
}

Hash operator - (Hash a, Hash b) {
	return Hash((a.h1 - b.h1 + MOD1) % MOD1, (a.h2 - b.h2 + MOD2) % MOD2);
}

Hash operator * (Hash a, Hash b) {
	return Hash(a.h1 * b.h1 % MOD1, a.h2 * b.h2 % MOD2);
}

bool operator == (Hash a, Hash b) {
	return (a.h1 == b.h1 && a.h2 == b.h2);
}

Hash modPow(int x, int y) {
	Hash cur = Hash(x, x), res = Hash(1, 1);
	while (y) {
		if (y & 1) res = res * cur;
		cur = cur * cur;
		y >>= 1;
	}
	return res;
}

bool operator < (Hash a, Hash b) {
	if (a.h1 == b.h1) return a.h2 < b.h2;
	else return a.h1 < b.h1;
}


int n, b[N];
vector <Hash> e[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> b[i];
		}
		bool found = false;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) if (b[i] == b[j]) {
				found = true;
			}
		}
		if (found) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}