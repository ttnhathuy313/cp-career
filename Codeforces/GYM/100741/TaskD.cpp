#include <bits/stdc++.h>

using namespace std;

const int N = 3e6 + 5;
int a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);
	freopen("TaskD.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int res = 0;
	sort(a + 1, a + 1 + n);
	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] != a[i - 1]) {
			if (cur & 1) res ^= a[i - 1];
			cur = 1;
		} else cur++;
	}
	if (cur & 1) res ^= a[n];
	cout << res << endl;

	return 0;
}