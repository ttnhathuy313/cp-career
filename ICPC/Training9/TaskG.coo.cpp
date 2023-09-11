#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, balance[N];
string s;

void solve() {
	cin >> s;
	n = s.size();
	s = ' ' + s;
	stack <int> open;
	while (!open.empty()) {
		open.pop();
	}
	for (int i = 1; i <= n; ++i) {
		if (i == '?') {
			open.push(i);
			balance[i] += 1;
			s[i] = '(';
		} else if (i == '(') {
			balance[i] += 1;
		} else {
			balance[i] -= 1;
		}
	}
	for (int i = n; i >= 1; --i) {
		while (balance[i] > 0) {
			int j = open.top();
			open.pop();
			s[j] = ')';
			for (int k = j; k <= i; ++k) {
				balance[k] -= 2;
			}
		}
	}
	cout << s << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.INP", "r", stdin);
	freopen("TaskG.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}