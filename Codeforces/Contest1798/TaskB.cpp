#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

const int N = 5e4+5;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int m;
		cin >> m;
		set <int> poss;
		poss.clear();
		vector <vector <int>> vt;
		vt.clear();
		for (int i = 1; i <= m; ++i) {
			vector <int> d;
			d.clear();
			int ni; cin >> ni;
			while (ni--) {
				int x;
				cin >> x;
				d.push_back(x);
				poss.insert(x);
			}
			vt.push_back(d);
		}
		bool ok = true;
		vector <int> res; res.clear();
		for (int i = m - 1; i >= 0; --i) {
			if (poss.size() == 0) {
				ok = false;
				break;
			}
			int ans = -1;
			for (int x : vt[i]) {
				if (poss.find(x) != poss.end()) {
					ans = x;
					poss.erase(x);
				}
			}
			if (ans == -1) {
				ok = false;
				break;
			}
			res.push_back(ans);
		}
		reverse(res.begin(), res.end());
		if (!ok) {
			cout << -1 << endl;
		} else {
			for (int x : res) {
				cout << x << ' ';
			}
			cout << endl;
		}
	}

	return 0;
}