#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

const int N = 1e6 + 5, MOD = 1e9 + 7;
ll fib[N];

// ll calc(int id) { // This uses fast doubling
// 	if (id == 0) return 0;
// 	if (id == 1) return 1;
// 	if (fib[id] != -1) return fib[id]; 
// 	else {
// 		if (id & 1) {
// 			ll a = calc(id / 2), b = calc(id / 2 + 1);
// 			return fib[id] = ((1LL * a * a) % MOD + (1LL * b * b) % MOD) % MOD;
// 		} else {
// 			ll a = calc(id / 2), b = calc(id / 2 - 1);
// 			return fib[id] = (1LL * a * ((2 * b + a) % MOD)) % MOD;
// 		}
// 	}
// }

void mat_mul(int a[2][2], int b[2][2])

void mat_Pow(int n) {
	ll F[2][2] = {{0, 1}, {1, 1}};
	ll a[2][2] = {{0, 1}, {1, 1}};
	n--;
	while (n > 0) {
		if (n & 1) F = mat_mul(F, a);
		a = mat_mul(a, a);
		n >>= 1;
	}
	return F[0][0];
}


int main(int argc, char const *argv[])
{
	freopen("Fibonacci.inp", "r", stdin);
	freopen("Fibonacci.out", "w", stdout);

	FOR(i, 1, N - 5) fib[i] = -1;

	int q;
	cin >> q;
	while (q--) {
		int a;
		cin >> a;
		cout << calc(a) << ' ';
	}

	return 0;
}