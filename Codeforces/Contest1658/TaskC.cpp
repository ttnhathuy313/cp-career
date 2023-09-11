#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int found = 0;
		bool ok = true;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] == 1) found++;
		}
		a[n + 1] = a[1];
		for (int i = 1; i <= n; ++i) {
			if (a[i] < a[i + 1] && a[i] != a[i + 1] - 1)
				ok = false;
		}
		if (found != 1 || (!ok)) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;

	}

	return 0;
}