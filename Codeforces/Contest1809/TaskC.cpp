#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 35;
int trace[N][N * N], n, p[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	memset(trace, -1, sizeof trace);
	trace[0][0] = 0;
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j <= i * (i + 1) / 2; ++j) {
			for (int k = 1; k <= i; ++k) if (j - k >= 0) {
				if (~trace[i - 1][j - k]) {
					trace[i][j] = k;
				}
			}
		}
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		memset(p, 0, sizeof p);
		int offset = 0;
		if (k < n) {
			k += n;
			offset = -500;
		} 
		if (true) {
			int j = k;
			for (int i = n; i >= 1; --i) {
				int pos = trace[i][j];
				int dem = 0;
				for (int ii = 1; ii <= n; ++ii) {
					if (p[ii]) {
						continue;
					}
					dem++;
					if (dem == pos) {
						p[ii] = i;
					}
				}
				j -= trace[i][j];
			}
		}
		for (int i = 1; i <= n; ++i) {
			p[i] += offset;
		}
		for (int i = 1; i <= n; ++i) {
			cerr << p[i] << ' ';
		}
		cerr << endl;
		for (int i = n; i >= 2; --i) {
			p[i] -= p[i - 1];
		}
		for (int i = 1; i <= n; ++i) {
			cout << p[i] << ' ';
		}
		cout << endl;
	}

	return 0;
}