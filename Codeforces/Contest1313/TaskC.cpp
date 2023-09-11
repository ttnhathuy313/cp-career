#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5e5 + 5, oo = 1e9 + 7;
int a[N], dp1[N], dp2[N];
stack <int> st;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	st.push(0);
	for (int i = 1; i <= n; ++i) {
		while (!st.empty() && a[st.top()] > a[i])
			st.pop();
		dp1[i] = dp1[st.top()] + (i - st.top()) * a[i];
		st.push(i);
	}
	a[n + 1] = 0;
	while (!st.empty()) st.pop();
	st.push(n + 1);
	for (int i = n; i >= 1; --i) {
		while (!st.empty() && a[st.top()] > a[i])
			st.pop();
		dp2[i] = dp2[st.top()] + (-i + st.top()) * a[i];
		st.push(i);
	}
	int res = 0, id = -1;
	for (int i = 1; i <= n; ++i) {
		if (res < dp1[i] + dp2[i] - a[i]) {
			res = dp1[i] + dp2[i] - a[i];
			id = i;
		}
	}
	cerr << res << ' ' << id << endl;
	int cur = a[id];
	vector <int> t; t.clear();
	for (int i = id - 1; i >= 1; --i) {
		cur = min(cur, a[i]);
		t.push_back(cur);
	}
	reverse(t.begin(), t.end());
	for (int x : t) cout << x << ' ';
	cout << a[id] << ' ';
	t.clear();
	cur = a[id];
	for (int i = id + 1; i <= n; ++i) {
		cur = min(cur, a[i]);
		cout << cur << ' ';
	}

	return 0;
}