#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		vector <int> A;
		A.clear();
		int n, h;
		cin >> n >> h;
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			A.push_back(x);
		}
		sort(A.begin(), A.end(), greater <int>());
		int res = h / (A[0] + A[1]);
		res *= 2;
		if (h % (A[0] + A[1]) != 0) {
			if (h % (A[0] + A[1]) <= A[0]) res++;
			if (h % (A[0] + A[1]) > A[0]) res += 2;
		}
		cout << res << endl;
	}

	return 0;
}