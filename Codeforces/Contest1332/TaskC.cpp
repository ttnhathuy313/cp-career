#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int cnt[N][30];
string s;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k >> s;
		for (int i = 0; i < k; ++i) {
			for (int j = 0; j < 26; ++j) cnt[i][j] = 0;
		}
		for (int i = 0; i < n; ++i) cnt[i % k][s[i] - 'a']++;
		int res = (int)1e9;
		for (int i = 0; i < n; i += k) {
			int l = i, r = i + k - 1;
			int t = 0;
			while (l <= r) {
				int tt = (int)1e9;
				for (int c = 0; c < 26; ++c) {
					if (l != r) tt = min(tt, 2 * n / k - cnt[l % k][c] - cnt[r % k][c]);
					else tt = min(tt, n / k - cnt[l % k][c]);
				}
				t += tt;
				l++; r--;
			}
			res = min(res, t);
		}
		cout << res << endl;
	}

	return 0;
}