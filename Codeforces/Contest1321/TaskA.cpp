#include <bits/stdc++.h>

using namespace std;

const int N = 500;
int a[N], b[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	int d1, d2, d3; d1 = d2 = d3 = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0 && b[i] == 1) d3++;
		if (a[i] == 1 && b[i] == 0) d1++;
		if (a[i] && b[i]) d2++;
	}
	if (d1 == 0) {
		cout << -1 << endl;
		return 0;
	}
	cout << max(1, (d3 + 1) / d1 + ((d3 + 1) % d1 != 0)) << endl;

	return 0;
}