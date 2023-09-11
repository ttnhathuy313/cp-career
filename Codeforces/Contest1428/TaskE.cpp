#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

int cost(int x, int y) {
	int a = x / y;
	return a * a * y + (2 * a + 1) * (x % y);
}

const int N = 1e5 + 5;
int n, a[N], k, ans[N];
priority_queue <iii> pq;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		ans[i] = 1;
	}
	for (int i = 1; i <= n; ++i) if (a[i] > 1) {
		int V = cost(a[i], 1) - cost(a[i], 2);
		pq.push(iii(V, ii(i, 1)));
	}
	while (n != k) {
		iii d = pq.top(); pq.pop();
		k--;
		int i = d.second.first, j = d.second.second;
		ans[i]++;
		if (j + 2 <= a[i]) pq.push({cost(a[i], j + 1) - cost(a[i], j + 2), {i, j + 1}});
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res += cost(a[i], ans[i]);
	}
	cout << res << endl;

	return 0;
}