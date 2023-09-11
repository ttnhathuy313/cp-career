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
		int a, b;
		cin >> a >> b;
		if (__gcd(a, b) != 1) cout << "Infinite" << endl;
		else cout << "Finite" << endl;
	}

	return 0;
}