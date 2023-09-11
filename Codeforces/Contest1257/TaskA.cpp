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
		int n, x, a, b;
		cin >> n >> x >> a >> b;
		cout << min(n - 1, abs(a - b) + x) << endl;
	}

	return 0;
}