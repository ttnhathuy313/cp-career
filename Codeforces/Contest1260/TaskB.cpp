#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.inp", "r", stdin);
	freopen("TaskB.out", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		if ((b - a) <= a && (a - (b - a)) % 3 == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}