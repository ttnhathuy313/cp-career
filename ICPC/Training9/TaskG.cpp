#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, balance[N];
bool question[N];
string s;
int tc = 0;

void solve() {
	cin >> s;
	tc++;
	n = s.size();
	s = ' ' + s;
	stack <int> open;
	while (!open.empty()) {
		open.pop();
	}
	for (int i = 1; i <= n; ++i) {
		balance[i] = 0;
		question[i] = false;
	}
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '?') {
			open.push(i);
			balance[i] = balance[i - 1] + 1;
			s[i] = '(';
			question[i] = true;
		} else if (s[i] == '(') {
			balance[i] = balance[i - 1] + 1;
		} else {
			balance[i] = balance[i - 1] - 1;
		}
	}
	while (balance[n] > 0) {
		int j = open.top();
		open.pop();
		s[j] = ')';
		balance[n] -= 2;
	}
	for (int i = 1; i <= n; ++i) {
		balance[i] = balance[i - 1] + (s[i] == '(' ? 1 : -1);
	}
	bool ok = false, waiting = false;
	for (int i = 1; i <= n; ++i) {
		if (question[i] && balance[i] >= 2 && s[i] == '(') {
			waiting = true;
		}
		if (waiting && question[i] && s[i] == ')' && i != n && balance[i] > 0) {
			ok = true;
		}
		if (waiting && balance[i] <= 1) {
			waiting = false;
		}
	}
	waiting = false;
	for (int i = 1; i <= n; ++i) {
		if (question[i] && s[i] == ')' && balance[i] > 0) {
			waiting = true;
		}
		if (waiting && question[i] && s[i] == '(' && balance[i - 1] > 0) {
			ok = true;
		}
	}
	if (ok) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
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