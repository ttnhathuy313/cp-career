#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int n, a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		int diff = 0, pre = -1;
		for (int i = 1; i <= n; ++i) {
			if (a[i] != pre)
				diff++;
			pre = a[i];
		}
		if (k == 1) {
			if (diff == 1) cout << 1 << endl;
			else cout << -1 << endl;
			continue;
		}
		int res = 1;
		if (diff <= k) {
			cout << 1 << endl;
			continue;
		}
		diff -= k;
		res += (diff + k - 2) / (k - 1);
		cout << res << endl;
	}

	return 0;
}