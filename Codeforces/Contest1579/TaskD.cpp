#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2e5 + 5;
int n, a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		priority_queue <ii> pq;
		while (!pq.empty()) pq.pop();		
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] > 0) pq.push({a[i], i});
		}
		vector <ii> res;
		res.clear();
		while (pq.size() > 1) {
			ii u = pq.top(); pq.pop();
			ii v = pq.top(); pq.pop();
			res.push_back({u.second, v.second});
			if (u.first != 1) pq.push({u.first - 1, u.second});
			if (v.first != 1) pq.push({v.first - 1, v.second});
		}
		cout << res.size() << endl;
		for (ii v : res) {
			cout << v.first << ' ' << v.second << endl;
		}
	}

	return 0;
}