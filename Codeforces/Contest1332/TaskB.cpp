#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
int c[500], a[N], ans[N], cnt[N];
int d[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	for (int i = 0; i <= 10; ++i) c[d[i]] = i + 1;
	while (tc--) {
		int n;
		cin >> n;
		set <int> D; D.clear();
		int f = 0;
		int cnt = 0;
		map <int, int> F; F.clear();
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			for (int j = 2; j <= sqrt(x); ++j) if (x % j == 0) {
				if (D.find(j) == D.end()) {
					F[j] = ++cnt;
					D.insert(j);
				}
				ans[i] = F[j];
				break;
			}
		}
		cout << cnt << endl;
		for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
		cout << endl;
	}

	return 0;
}