#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int y = -1;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i < n; ++i) {
		if (a[i] == a[i + 1]) {
			cout << "NO" << endl;
			return 0;
		}
		if (abs(a[i] - a[i + 1]) != 1) {
			if (~y && abs(a[i] - a[i + 1]) != y) {
				cout << "NO" << endl;
				return 0;
			}
			y = abs(a[i] - a[i + 1]);
		}
	}
	if (y == -1) {
		cout << "YES" << endl;
		cout << 1 << ' ' << (int)1e9 << endl;
		return 0;
	}
	for (int i = 1; i < n; ++i) {
		if (a[i] - a[i + 1] == 1) {
			if ((a[i] - 1) % y == 0) {
				cout << "NO";
				return 0;
			}
		} else if (a[i + 1] - a[i] == 1) {
			if (a[i] % y == 0) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	cout << (int)1e9 << ' ' << y << endl;

	return 0;
}