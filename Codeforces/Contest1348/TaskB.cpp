#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 4;


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		set <int> S;
		S.clear();
		vector <int> V; V.clear();
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			S.insert(x);
		}
		if (S.size() > k) {
			cout << -1 << endl;
			continue;
		}
		cout << k * n << endl;
		for (int i = 0; i < n; ++i) {
			for (int v : S) cout << v << ' ';
			for (int j = 0; j < k - (int)S.size(); ++j) cout << 1 << ' ';
		}
		cout << endl;
	}

	return 0;
}