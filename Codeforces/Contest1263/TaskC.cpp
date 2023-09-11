#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.inp", "r", stdin);
	freopen("TaskC.out", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		set <int> res; res.clear();
		res.insert(0);
		for (int i = 1; i <= sqrt(n); ++i) {
			int j = n / i;
			if (i * j > n - j) res.insert(i);
			if (i * j > n - i) res.insert(j);
		}
		cout << res.size() << endl;
		for (int d : res) cout << d << ' ';
		cout << endl;
	}

	return 0;
}