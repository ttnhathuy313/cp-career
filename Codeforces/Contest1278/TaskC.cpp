#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int D[N * 2], a[2 * N];

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
		D[0] = -1;
		int c1 = 0, c2 = 0;
		for (int i = 1; i <= 2 * n; ++i) {
			cin >> a[i];
			if (a[i] == 1) c1++;
			else c2++;
			D[i] = -1;
		}
		if (c2 == c1) {
			cout << 0 << endl;
			continue;
		}
		int cur = 0;
		for (int i = n; i >= 1; --i) {
			if (a[i] == 1) cur++;
			else cur--;
			D[cur + n] = max(D[cur + n], i);
		}
		D[n] = n + 1;
		cur = 0;
		int res = N * 2;
		for (int i = n + 1; i <= 2 * n; ++i) {
			if (a[i] == 1) cur++;
			else cur--;
			if (c1 - c2 - cur + n >= 0 && c1 - c2 - cur + n <= 2 * n && D[c1 - c2 - cur + n] > 0) 
				res = min(res, i - D[c1 - c2 - cur + n] + 1);
		}
		if (c1 - c2 + n >= 0 && c1 - c2 + n <= 2 * n && D[c1 - c2 + n] > 0) 
			res = min(res, n - D[c1 - c2 + n] + 1);
		cout << res << endl;
	}

	return 0;
}