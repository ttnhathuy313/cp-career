#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int a[N], lst[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.inp", "r", stdin);
	freopen("TaskC.out", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			lst[a[i]] = -1;
		}
		int res = N;
		for (int i = 1; i <= n; ++i) {
			if (lst[a[i]] != -1) res = min(res, i - lst[a[i]] + 1);
			lst[a[i]] = i;
		}
		if (res == N) res = -1;
		cout << res << endl;
	}

	return 0;
}