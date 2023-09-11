#include <bits/stdc++.h>

using namespace std;

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
		vector <int> a, b; a.clear(); b.clear();
		for (int i = 1; i <=n; ++i) {
			int x;
			cin >> x;
			a.push_back(x);
		}
		for (int i = 1; i <=n; ++i) {
			int x;
			cin >> x;
			b.push_back(x);
		}
		sort(a.begin(), a.end()); sort(b.begin(), b.end());
		for (int d : a) cout << d << ' '; cout << endl;
		for (int d : b) cout << d << ' '; cout << endl;
	}

	return 0;
}