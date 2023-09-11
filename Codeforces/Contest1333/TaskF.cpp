#include <bits/stdc++.h>

using namespace std;

int res[(int)5e5 + 5];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 2 * i; j <= n; j += i) res[j] = i;
	}
	sort(res + 1, res + 1 + n);
	for (int i = 2; i <= n; ++i)
		cout << res[i] << ' ';

	return 0;
}