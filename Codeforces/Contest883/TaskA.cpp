#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 100050;
int in[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.inp", "r", stdin);
	freopen("TaskA.out", "w", stdout);
	int n, m, a, d, i, j;
	cin >> n >> m >> a >> d;
	for (i = 1; i <= m; i++)
		cin >> in[i];
 
	int c = d / a + 1;
 
	int ans = 0, p1 = 0, p2 = 0;
	while (p1 != n || p2 != m) {
		if (p1 != n && (p2 == m || (p1+1) * a < in[p2+1])) {
			int x = min(n + 1, (in[p2+1] + a - 1) / a) - (p1 + 1);
			if (p2 == m) x = n - p1;
			int c2 = (x + c - 1) / c;
 
			int s = (p1 + 1)*a, e = s + c*(c2 - 1)*a + d;
			p2 = lower_bound(in + 1, in + m + 1, e + 1) - (in + 1);
			p1 = min(n, e / a);
			ans += c2;
		}
		else {
			ans++;
			int s = in[p2+1], e = s + d;
			p2 = lower_bound(in + 1, in + m + 1, e + 1) - (in + 1);
			p1 = min(n, e / a);
		}
	}
	cout << ans << endl;
	return 0;
}