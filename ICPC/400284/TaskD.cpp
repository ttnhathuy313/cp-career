#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int a[N][N];

struct rect {
	int a1, a2, a3, a4;
};

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		int tot1 = 0;
		for (int i = 1; i <= n; ++i) {
			string s;
			cin >> s;
			for (int j = 1; j <= m; ++j) {
				a[i][j] = (s[j - 1] == '0' ? 0 : 1);
				if (a[i][j] == 1) {
					tot1++;
				}
			}
		}
		vector <rect> res;
		res.clear();
		if (a[1][1]) {
			cout << -1 << endl;
			continue;
		}
		for (int i = n; i >= 2; --i) {
			for (int j = 1; j <= m; ++j) if (a[i][j]) {
				res.push_back({i - 1, j, i, j});
			}
		}
		for (int j = m; j >= 2; --j) if (a[1][j]) {
			res.push_back({1, j - 1, 1, j});
		}
		cout << res.size() << endl;
		for (rect d : res) {
			cout << d.a1 << ' ' << d.a2 << ' ' << d.a3 << ' ' << d.a4 << endl;
		}
	}

	return 0;
}