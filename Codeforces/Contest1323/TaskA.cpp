#include <bits/stdc++.h>

using namespace std;

int a[1005];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		if (n == 1) {
			int d;
			cin >> d;
			if (d & 1) cout << "-1" << endl;
			else cout << "1\n1\n";
			continue;
		}
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		vector <int> D; D.clear();
		for (int i = 1; i <= n; ++i) {
			if (a[i] % 2 == 0) {
				cout << "1\n" << i << endl;
				goto tag;
			} else D.push_back(i);
		}
		cout << 2 << endl;
		cout << D[0] << ' ' << D[1] << endl;

		tag:;
	}

	return 0;
}