#include <bits/stdc++.h>

using namespace std;
#define int long long

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.inp", "r", stdin);
	freopen("TaskC.out", "w", stdout);

	int n;
	cin >> n;
	vector <int> f;
	for (int i = 1; i <= sqrt(n); ++i) if (n % i == 0) {
		f.push_back(n / i);
		if (i != 1) f.push_back(i);
	}
	int g = f[0];
	for (int i = 1; i < f.size(); ++i) g = __gcd(g, f[i]);
	cout << g << endl;

	return 0;
}