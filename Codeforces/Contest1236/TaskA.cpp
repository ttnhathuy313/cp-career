#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.inp", "r", stdin);
	freopen("TaskA.out", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int a, b, c;
		cin >> a >> b >> c;
		int res = 0;
		for (int i = 0; i <= b; ++i) {
			int t1 = min(i / 2, a), t2 = min(b - i, c / 2);
			res = max(res, (t1 + t2) * 3);
		}
		cout << res << endl;
	}

	return 0;
}