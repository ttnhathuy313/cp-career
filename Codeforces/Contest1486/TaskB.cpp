#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1005;
int n, x[N], y[N], p1[N], p2[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		vector <int> X, Y;
		int sumX = 0, sumY = 0;
		X.clear(); Y.clear();
		for (int i = 1; i <= n; ++i) {
			cin >> x[i] >> y[i];
			X.push_back(x[i]);
			Y.push_back(y[i]);
			sumX += x[i];
			sumY += y[i];
		}
		sort(X.begin(), X.end());
		sort(Y.begin(), Y.end());
		for (int i = 0; i < n; ++i) {
			if (i == 0) {
				p1[i] = X[i];
				p2[i] = Y[i];
				continue;
			}
			p1[i] = p1[i - 1] + X[i];
			p2[i] = p2[i - 1] + Y[i];
		}
		int minimal = (int)1e18;

		for (int i = 0; i < n; ++i) {
			int cur = X[i] * (i + 1) - p1[i] + (sumX - p1[i]) - X[i] * (n - i - 1);
			for (int j = 0; j < n; ++j) {
				int curr =  Y[j] * (j + 1) - p2[j] + (sumY - p2[j]) - Y[j] * (n - j - 1);
				if (cur + curr < minimal) minimal = cur + curr;
			}
		}
		cerr << minimal << endl;
		int cnt = 0;

		int i = 0;
		X.push_back(X.back() + 1);
		Y.push_back(Y.back() + 1);
		while (i < n) {
			while (i < n - 1 && X[i + 1] == X[i]) i++;
			int cur = X[i] * (i + 1) - p1[i] + (sumX - p1[i]) - X[i] * (n - i - 1);
			int j = 0;
			while (j < n) {
				while (j < n - 1 && Y[j + 1] == Y[j]) j++;
				int curr =  Y[j] * (j + 1) - p2[j] + (sumY - p2[j]) - Y[j] * (n - j - 1);
				if (cur + curr == minimal) {
					cerr << X[i] << ' ' << Y[j + 1] << endl;
					cnt += (X[i + 1] - X[i]) * (Y[j + 1] - Y[j]);
				}
				j++;
			}
			i++;
		}
		cout <<  cnt << endl;
	}

	return 0;
}