#include <bits/stdc++.h>

using namespace std;
#define int long long

int bi(string s) {
	reverse(s.begin(), s.end());
	int res = 0;
	for (int i = 0; i < s.size(); ++i) if (s[i] == '1')
		res += (1 << i);
	return res;
}

string show(int d) {
	string ret; ret.clear();
	while (d) {
		ret = char((d % 2) + '0') + ret;
		d /= 2;
	}
	return ret;
}


const int N = 405;
int n, m, a[N][N], ans[1<<7], h[N][N], dp[N];

int solve(int mask) {
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (mask & (1 << a[i][j])) h[i][j] = h[i - 1][j] + 1;
			else h[i][j] = 0;
			// cerr << h[i][j] << ' ';
		}
		// cerr << endl;
	}
	int ret = 0;
	for (int i = 1; i <= m; ++i) {
		memset(dp, 0, sizeof dp);
		vector <int> st; st.clear();
		st.push_back(0);
		for (int j = 1; j <= n; ++j) {
			while (st.size() && h[i][st.back()] >= h[i][j])
				st.pop_back();
			if (st.size()) {
				int val = st.back();
				dp[j] = dp[val] + (j - val) * h[i][j];
			} else dp[j] = 0;
			st.push_back(j);
			ret += dp[j];
		}
	}
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("CRECT.INP", "r", stdin);
	freopen("CRECT.OUT", "w", stdout);

	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		string s;
		cin >> s;
		for (int j = 1; j <= n; ++j) {
			a[i][j] = s[j - 1] - 'A';
		}
	}

	for (int mask = 1; mask < (1 << 5); ++mask) if (__builtin_popcount(mask) <= 3) {
		ans[mask] = solve(mask);
		for (int sub = mask; sub; sub = (sub - 1) & mask) {
			if (sub == mask) continue;
			ans[mask] -= ans[sub];
		}
	}

	int res = 0;
	for (int mask = 1; mask < (1 << 5); ++mask) if (__builtin_popcount(mask) == 3)
		res += ans[mask];
	cout << res << endl;

	return 0;
}