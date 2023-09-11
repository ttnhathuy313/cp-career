#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		int mx = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			mx = max(mx, a[i]);
		}
		cout << n << endl;
		int r = (int)1e9;
		for (int i = 1; i <= n; ++i) {
			int aim = (int)log2(a[i]) + 1;
			aim = (1 << aim);
			cout << i << ' ' << aim - a[i] << endl;
		}
	}

	return 0;
}