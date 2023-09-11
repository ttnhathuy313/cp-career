#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.inp", "r", stdin);
	freopen("TaskA.out", "w", stdout);

	int q;
	cin >> q;
	while (q--) {
		vector <int> d;
		d.clear();
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			int b;
			cin >> b;
			d.push_back(b);
		}
		sort(d.begin(), d.end());
		int pre = -1;
		int ans = 1;
		for (int c : d) {
			if (c == pre + 1) ans = 2;
			pre = c;
		}
		cout << ans << endl;
	}

	return 0;
}