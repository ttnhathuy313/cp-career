#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
int n, a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		int s = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			s += a[i];
		}
		bool found = false;
		if (a[1] == 1) {
			cout << n + 1 << ' ';
			for (int i = 1; i <= n; ++i) cout << i << ' ';
			cout << endl;
			found = true;
		}
		if (found) continue;
		for (int i = 1; i < n; ++i) {
			if (a[i] == 0 && a[i + 1] == 1) {
				for (int j = 1; j <= i; ++j)
					cout << j << ' ';
				cout << n + 1 << ' ';
				for (int j = i + 1; j <= n; ++j) cout << j << ' ';
				cout << endl;
				found = true;
				break;
			}
		}
		if (found) continue;
		if (s == 0) {
			for (int i = 1; i <= n + 1; ++i) {
				cout << i << ' ';
			}
			cout << endl;
			found = true;
		}
		if (found) continue;
		cout << -1 << endl;
	}

	return 0;
}