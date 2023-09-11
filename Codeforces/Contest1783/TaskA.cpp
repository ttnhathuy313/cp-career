#include <bits/stdc++.h>

using namespace std;

const int N = 55;
int n, a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		sort(a + 1, a + 1 + n, greater <int>());
		if (a[1] == a[n]) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		cout << a[1] << ' ' << a[n] << ' ';
		for (int i = 2; i < n; ++i) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}

	return 0;
}