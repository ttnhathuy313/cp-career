#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

int cnt = 0;
string temp;

int cost(int a, int b) {
	temp.clear();
	if (a/10 != 0) temp = temp + char(a/10 + '0');
	if (a % 10 != 0 || (a % 10 == 0 && a/10 != 0)) temp = temp + char((a % 10) + '0');
	temp = temp + char(b/10 + '0');
	temp = temp + char((b % 10) + '0');
	int ret = temp.size(), n = temp.size();
	for (int i = 0; i < n - 1; ++i) if (temp[i] != temp[i + 1])
		ret++;
	return ret;
}

void solve() {
	string s;
	cin >> s;
	int minute = (s[0] - '0') * 10 + s[1] - '0', secs = (s[3] - '0') * 10 + s[4] - '0', percent;
	// cerr << minute << ' ' << secs << endl;
	cin >> percent;
	int tot = minute * 60 + secs, split = tot * percent / 100;
	int lb = tot - split, ub = tot + split;
	int res = 45678, dist = 0;
	ii id;
	for (int i = lb; i <= ub; ++i) {
		for (int j = 0; j <= 99; ++j) if (i - j >= 0 && (i - j) % 60 == 0) {
			int mn = (i - j) / 60, sc = j;
			if (cost(mn, sc) == res)  {
				if (abs(i - tot) < dist) {
					dist = abs(i - tot);
					id = {mn, sc};
				}
			}
			if (cost(mn, sc) < res) {
				res = cost(mn, sc);
				id = {mn, sc};
				dist = abs(i - tot);
			}
		}
	}
	cout << "Case #" << (++cnt) << ": ";
	cost(id.first, id.second);
	cout << temp << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("microwave.INP", "r", stdin);
	freopen("microwave.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}