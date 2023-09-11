#include <bits/stdc++.h>

using namespace std;

void solve() {
	string a, b;
	cin >> a >> b;
	if (a[0] == b[0]) {
		cout << "YES" << endl;
		cout << a[0] << "*" << endl;
		return;
	}
	if (a[a.size() - 1] == b[b.size() - 1]) {
		cout << "YES" << endl;
		cout << "*" << a[a.size() - 1] << endl;
		return;
	}
	for (int i = 0; i < a.size() - 1; ++i) {
		for (int j = 0; j < b.size() - 1; ++j) {
			if (a.substr(i, 2) == b.substr(j, 2)) {
				cout << "YES" << endl;
				cout << "*" << a.substr(i, 2) << "*" << endl;
				return;
			}
		}
	}
	cout << "NO" << endl;
}

int main(int argc, char const *argv[])
{
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