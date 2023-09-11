#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, a[N];
stack <int> st;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskJ.INP", "r", stdin);
	freopen("TaskJ.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	st.push(0);
	int res = 0;
	a[0] = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] >= a[i - 1]) {
			if (a[i] > a[i - 1]) st.push(i);
			res += a[i] - a[i - 1];
			continue;
		}
		while (!st.empty() && a[i] <= a[st.top()])
			st.pop();
		st.push(i);
	}
	cout << res << endl;

	return 0;
}