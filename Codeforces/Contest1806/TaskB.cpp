#include <bits/stdc++.h>

using namespace std;
#define forn(i, a, b) for (int i = a; i <= b; ++i)

const int N = 2e5 + 5;
int n, a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] == 0) {
				cnt++;
			}
		}
		if (cnt <= (n + 1) / 2) {
			cout << 0 << endl;
			continue;
		}
		int cnt1 = 0;
		for (int i = 1; i <= n; ++i) if (a[i] == 1) {
			cnt1++;
		}
		if (cnt1 + cnt != n || cnt1 == 0) {
			cout << 1 << endl;
		} else cout << 2 << endl;
	}

	vector <int> y = {-3, -2, -1, 0, 1, 2, 3, 4};
	int r = 5;
	forn(x1,-r,r)forn(x2,-r,r)forn(x3,-r,r)forn(x4,-r,r)forn(x5,-r,r)forn(x6,-r,r) {
		vector <int> x = {x1, x2, x3, x4, x5, x6};

		int sum = 0;
		for (int v : x) sum += v;
		bool ok = true;
		for (int mask = 0; mask < (1 << 6); ++mask) if (__builtin_popcount(mask) == 3) {
			int cur_prod = 1, cur_sum = 0;
			for (int i = 0; i < 6; ++i) if (mask & (1 << i)) {
				cur_prod *= x[i];
				cur_sum += x[i];
			}
			if (cur_prod != sum - cur_sum) {
				ok = false;
			}
		}
		if (ok) {
			for (int v : x) {
				cerr << v << ' ';
			}
			cerr << endl;
		}
	}


	return 0;
}