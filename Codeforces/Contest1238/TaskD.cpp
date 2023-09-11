#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 3e5 + 5;
string s;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int n;
	cin >> n >> s;
	int res = 0, cons = 1;
	for (int i = 1; i < n; ++i) {
		if (s[i] != s[i - 1]) {
			cerr << cons << endl;
			res += cons;
			cons = 0;
		}
		cons++;
	}
	for (int i = 1; i <= 8; ++i) {
		cerr << i << ' ' << (5 ^ i) << endl;
	}
	reverse(s.begin(), s.end());
	cons = 1;
	for (int i = 1; i < n; ++i) {
		if (s[i] != s[i - 1]) {
			res += cons - 1;
			cons = 0;
		}
		cons++;
	}
	cout << (n + 1) * n / 2 - res - n << endl;

	return 0;
}