#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
#define int long long

long long Exp(int a, int n) {
  if (n == 0) return 1;
  long long res = Exp(a, n / 2);
  res = res * res % MOD;
  if (n % 2) res = res * a % MOD;
  return res;
}

signed main() {
  freopen("TaskE.inp", "r", stdin);
  freopen("TaskE.out", "w", stdout);
  long long n;
  while (cin >> n) {
    n = n % MOD;
    long long f3 = Exp(n, 5);
    for (int i = 1; i <= n; ++i) {
    	f3 += n * n * (i - 1) * (n - i + 1) % MOD;
    	f3 %= MOD;
    }
    f3 %= MOD;
    long long f2 = (f3 + Exp(n, 5)) % MOD; // opposite - CORRECT
    long long f1 = 2 * Exp(n, 5) % MOD; // adjacent
    long long res = (4 * f1 + 2 * f2 + 4 * f3) % MOD;
    if (res < 0) res += MOD;
    cout << res << '\n';
	}
}
