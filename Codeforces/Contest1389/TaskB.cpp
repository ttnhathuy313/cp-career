#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, a[N], k, z;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> k >> z;
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (i <= k + 1) sum += a[i];
		}
		int res = sum;
		for (int left = 1; left <= z; ++left) {
			sum -= a[k + 1 - left * 2 + 1] + a[k + 1 - left * 2 + 2];
			vector <int> val; val.clear();
			for (int i = 1; i <= k + 1 - left * 2; ++i)
				val.push_back(a[i] + a[i + 1]);
			sort(val.begin(), val.end(), greater <int>());
			int tmp = 0;
			if (val.size() >= left) {
				for (int t = 0; t < left; ++t) tmp += val[t];
				res = max(res, sum + tmp);
				if (sum + tmp == 31) cerr << left << endl;
			}
		}
		cout << res << endl;
	}

	return 0;
}