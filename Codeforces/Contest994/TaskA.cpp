#include <bits/stdc++.h>

using namespace std;

int a[33], b[33], id[(int)3e5];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= 1000; ++i) id[i] = 10000000;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		id[a[i]] = i;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
	}
	sort(b + 1, b + 1 + m, [](int i, int j) {
		return id[i] < id[j];
	});
	for (int i = 1; i <= m; ++i) if (id[b[i]] != 10000000)
		cout << b[i] << ' ';

	return 0;
}