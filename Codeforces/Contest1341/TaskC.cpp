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
		for (int i = 1; i <= n; ++i) cin >> a[i];
		bool ok = true;
		for (int i = 1; i < n; ++i) {
			if (a[i] < a[i + 1]) {
				if (a[i + 1] != a[i] + 1) ok = false;
			}
		}
		if (ok) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}