/*
	The main ideas of this problem:
		- Closely watch the process of pushing books. When a book is not pushed in the optimal solution?
		- My mistake was that I only looked at cases when the whole type of a book remain unchanged.
		but one should criticize on that. If we have fully remained one, why not halfly remained?
		We should also care the case that a suffix of book type will remain unchanged.
	Opinion about this problem: A good problem for training dp, especially the case when you have to tackle
	with some process of operations. We need to sort the operations in some way and think what the optimal looks
	like if some case happen. This is very neat! Worth 2500!
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5e5 + 5;
int n, a[N], l[N], r[N], dp[N], cnt[N], c[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	memset(l, -1, sizeof l);
	for (int i = 1; i <= n; ++i) {
		if (l[a[i]] == -1) l[a[i]] = i;
		r[a[i]] = i;
	}
	for (int i = n; i >= 1; --i) {
		dp[i] = dp[i + 1];
		c[a[i]]++;
		if (i == l[a[i]]) {
			dp[i] = max(dp[i], dp[r[a[i]] + 1] + cnt[a[i]]);
		} else {	
			dp[i] = max(dp[i], c[a[i]]);
		}
	}
	cout << n - dp[1] << endl;

	return 0;
}