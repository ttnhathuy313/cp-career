#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2e6 + 5;
int n, m;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	vector <int> A;
	A.clear();
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		A.push_back(v);
	}
	sort(A.begin(), A.end(), greater <int>());
	int tmp = 0, res = 0;
	for (int i = 1; i <= m; ++i) {
		tmp += A[i - 1];
		int need;
		if (i & 1) {
			need = i * (i - 1) / 2 + 1;
		} else {
			need = i * (i - 1) / 2 + i / 2;
			if (i == 2) need = 2;
		}
		if (need <= n) {
			res = max(res, tmp);
		}
	}
	cout << res << endl;

	return 0;
}