#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.inp", "r", stdin);
	freopen("TaskA.out", "w", stdout);

	int tc;
	int a[4];
	cin >> tc;
	while (tc--) {
		cin >> a[1] >> a[2] >> a[3];
		sort(a + 1, a + 4);
		if (a[3] > a[1] + a[2]) cout << a[1] + a[2] << endl;
		else cout << a[3] + (a[1] + a[2] - a[3]) / 2 << endl;
	}

	return 0;
}