#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int f[N], n, key[N], k;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("AC5.INP", "r", stdin);
	freopen("AC5.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) cin >> key[i];
		memset(f, -1, sizeof f);
		f[1] = 0;
		for (int i = 2; i <= k; ++i) {
			for (int j = 1; j <= n; ++j) if (i % key[j] == 0) {
				if (~f[i / key[j]]) {
					if (f[i] == -1) f[i] = f[i / key[j]] + 1;
					f[i] = min(f[i], f[i / key[j]] + 1);
				}
			}
		}
		if (f[k] == -1) cout << "Impossible" << endl;
		else cout << f[k] << endl;
	}

	return 0;
}