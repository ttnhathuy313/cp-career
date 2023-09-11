#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, tot, a[2], b[2];
string st;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> st;
	n = st.size();
	st = ' ' + st;
	int odd, even;
	odd = even = 0;
	for (int i = 1; i <= n; ++i) {
		int id = i & 1;
		if (st[i] == 'a') {
			even += a[id ^ 1];
			a[id]++;
			odd += a[id];
		} else {
			even += b[id ^ 1];
			b[id]++;
			odd += b[id];
		}
	}
	cout << even << ' ' << odd << endl;

	return 0;
}