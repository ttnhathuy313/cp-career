#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, a[N], f[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i - 1] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		f[a[i]]++;
	}
	int curSum = 0, res = 1;
	for (int i = 0; i < n; ++i) {
		if (curSum >= i) {
			curSum += 0;
		} else if (curSum + f[i] - 1 >= i) {
			res++;
			cerr << i << endl;
		}
		curSum += f[i];
	}
	cout << res << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}