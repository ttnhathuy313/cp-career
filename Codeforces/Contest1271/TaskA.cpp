#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int res = 0;
	for (int i = 0; i <= d; ++i) {
		int n1 = min(i, a);
		int n2 = min(d - i, min(b, c));
		res = max(res, n1 * e + n2 * f);
	}
	cout << res << endl;

	return 0;
}