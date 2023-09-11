#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 5e5 + 5;
int n, a[N];
vector <ii> st;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("C11PAIRS.INP", "r", stdin);
	freopen("C11PAIRS.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int res = 0;
	for (int i = n; i >= 1; --i) {
		int cnt = 0, tmp = 0;
		while (!st.empty() && a[st.back().first] <= a[i]) {
			int j = st.back().first, v = st.back().second;
			st.pop_back();
			res += v;
			if (a[j] == a[i]) cnt += v;
		}
		if (!st.empty()) res++;
		st.push_back({i, cnt + 1});

	}
	cout << res << endl;

	return 0;
}