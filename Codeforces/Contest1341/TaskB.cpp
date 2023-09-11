#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int k, n, a[N], peak[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		int cur = 0, res = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; ++i) {
			if (i == 1 || i == n) {
				peak[i] = 0;
				continue;
			}
			peak[i] = (a[i] > a[i - 1] && a[i] > a[i + 1]);
			if (i < k) cur += peak[i], res += peak[i];
		}
		int l = 2, id = 1;
		for (int i = k + 1; i <= n; ++i) {
			cur += peak[i - 1];
			cur -= peak[l];
			l++;
			if (res < cur) {
				res = cur;
				id = l - 1;
			}
		}
		cout << res + 1 << ' ' << id << endl;
	}

	return 0;
}