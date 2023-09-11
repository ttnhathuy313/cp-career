#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int n, m;
	cin >> n >> m;
	int res = (1LL << n) + (1LL << m) - 2;
	cout << res << endl; 

	return 0;
}