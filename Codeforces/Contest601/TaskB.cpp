#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, q, a[N], b[N], l[N], r[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 2; i <= n; ++i) {
		b[i] = abs(a[i] - a[i - 1]);
	}
	while (q--) {
		int L, R;
		cin >> L >> R;
		L++;
		vector <int> st;
		st.clear();
		for (int i = L; i <= R; ++i) {
			while (!st.empty() && b[st.back()] < b[i])
				st.pop_back();
			l[i] = st.empty() ? L : st.back() + 1;
			st.push_back(i);
		}
		st.clear();
		for (int i = R; i >= L; --i) {
			while (!st.empty() && b[st.back()] <= b[i])
				st.pop_back();
			r[i] = st.empty() ? R : st.back() - 1;
			st.push_back(i);
		}
		int res = 0;
		for (int i = L; i <= R; ++i) {
			res += b[i] * (i - l[i] + 1) * (r[i] - i + 1);
		}
		cout << res << endl;
	}

	return 0;
}