#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int D[N * 2], a[2 * N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.ANS", "w", stdout);

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
		if (c1 == c2) {
			cout << 0 << endl;
			continue;
		}
		int res = N;
		for (int i = 1; i <= n; ++i) {
			for (int j = n + 1; j <= 2 * n; ++j) {
				int c = 0;
				for (int k = i; k <= j; ++k) if (a[k] == 1) c++;
					else c--;
				if (c == c1 - c2) res = min(res, j - i + 1);
			}
		}
		for (int i = 1; i <= n; ++i) {
			int c = 0;
			for (int j = i; j <= n; ++j) if (a[j] == 1) c++;
				else c--;
			if (c == c1 - c2) res = min(res, n - i + 1);
		}
		for (int i = n + 1; i <= n * 2; ++i) {
			int c = 0;
			for (int j = n + 1; j <= i; ++j) if (a[j] == 1) c++;
				else c--;
			if (c == c1 - c2) res = min(res, i - n);
		}
		cout << res << endl;
	}

	return 0;
}