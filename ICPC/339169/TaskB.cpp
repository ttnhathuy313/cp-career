#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int n1 = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			n1++;
		}
	}
	int missing = 0;
	vector <int> res;
	res.clear();
	for (int i = n - 1; i >= n - n1; --i) {
		if (s[i] == '0') {
			missing++;
			res.push_back(i + 1);
		}
	}
	for (int i = 0; i < n - n1; ++i) {
		if (s[i] == '1') {
			if (missing > 0) res.push_back(i + 1);
			missing--;
		}
	}
	if (res.size() == 0) {
		cout << 0 << endl;
		return;
	}
	sort(res.begin(), res.end());
	cout << 1 << endl;
	cout << res.size() << ' ';
	for (int v : res) {
		cout << v << ' ';
	}
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}