
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define cerr if(1)cerr
#define size(x) (int)x.size()
#define all(x) x.begin(), x.end()
 
const int N = 1e6 + 1, mod = 1e9 + 7, inf = 2e9;
 
int d;
ll pw = 1, ans = 0;
 
ll solve(ll d, ll p, bool leading) {
	if (!p) return !d;
	ll ans = 0;
	int c = (d % 10 + 10) % 10;
	ans += (10 - c - leading) * solve((d - c * p) / 10, p / 100, 0);
	ans += (c - leading) * solve((d + (10 - c) * p) / 10, p / 100, 0);
	return ans;
}
 
int main() { cin.tie(0)->sync_with_stdio(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.ans", "w", stdout);
	cin >> d;
	if (d % 9) {
		return cout << 0, 0;
	}
	d /= 9;
	for (int i = 2; i <= 18; i++) {
		pw *= 10;
		ll res = solve(d, pw / 9, 1);
		if (i & 1) {
			res *= 10;
		}
		ans += res;
	}
	cout << ans;
}