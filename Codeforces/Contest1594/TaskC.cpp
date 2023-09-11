#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 3e5 + 5;
int dem[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		string s;
		char c;
		cin >> n >> c >> s;
		s = ' ' + s;
		int cnt = 0;
		for (int i = 1; i <= n; ++i) if (s[i] != c)
			cnt++;
		for (int i = 1; i <= n; ++i)
			dem[i] = 0;
		if (s[n] == c) {
			if (cnt == 0) {
				cout << 0 << endl;
			} else {
				cout << 1 << endl;
				cout << n << endl;
			}
			continue;
		}
		for (int i = n; i >= 1; --i) {
			for (int j = i; j <= n; j += i) if (s[j] != c)
				dem[i]++;
		}
		int id = -1;
		for (int i = 1; i <= n; ++i) if (dem[i] == 0) {
			id = i;
		}
		if (~id) {
			cout << 1 << endl;
			cout << id << endl;
			continue;
		}
		for (int i = 1; i <= n; ++i) if (n % i != 0)
			id = i;
		cout << 2 << endl;
		cout << n << ' ';
		cout << id << endl;
	}

	return 0;
}