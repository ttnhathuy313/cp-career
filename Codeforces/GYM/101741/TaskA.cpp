#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
#define int long long

const int N = 5e5 + 5;
int d, na, nb, nc;

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.inp", "r", stdin);
	freopen("TaskA.out", "w", stdout);

	vector <int> a, b, c;
	while (cin >> d >> na >> nb >> nc) {
		a.clear(); b.clear(); c.clear();
		for (int i = 1; i <= na; ++i) {
			int x;
			cin >> x;
			a.push_back(x);
		}
		for (int i = 1; i <= nb; ++i) {
			int x;
			cin >> x;
			b.push_back(x);
		}
		for (int i = 1; i <= nc; ++i) {
			int x;
			cin >> x;
			c.push_back(x);
		}
		sort(all(a)); sort(all(b)); sort(all(c));
		int res = 0;
		for (int x : a) {
			int cb = upper_bound(all(b), x + d) - lower_bound(b.begin(), b.end(), x);
			int cc = upper_bound(all(c), x + d) - lower_bound(all(c), x);
			res += cb * cc;
		}
		for (int x : b) {
			int ca = upper_bound(all(a), x + d) - lower_bound(all(a), x + 1);
			int cc = upper_bound(all(c), x + d) - lower_bound(all(c), x);
			res += ca * cc;
		}
		for (int x : c) {
			int ca = upper_bound(all(a), x + d) - lower_bound(all(a), x + 1);
			int cb = upper_bound(all(b), x + d) - lower_bound(all(b), x + 1);
			res += cb * ca;
		}
		cout << res << endl;
	}

	return 0;
}