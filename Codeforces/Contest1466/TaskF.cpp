#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 5e5 + 5, MOD = 1e9 + 7;
int n, m, k[N], mark[N];
set <int> basis[N], mask[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		for (int j = 0; j < k[i]; ++j) {
			int x;
			cin >> x;
			mask[i].insert(x);
		}
	}
	vector <int> id; id.clear();
	for (int i = 1; i <= n; ++i) {
		for (int j : mask[i]) {
			if (!mark[j]) {
				for (int vv : mask[i]) basis[j].insert(vv);
				basis[j].erase(j);
				mark[j] = 1;
				id.push_back(i);
			} else {
				set <int> N; N.clear();
				for (int vv : basis[j]) N.insert(vv);
				for (int vv : mask[i]) if (vv != j) {
					if (N.find(vv) == N.end()) N.insert(vv);
					else N.erase(vv);
				}
				vector <int> D; D.clear();
				for (int vv : N) {
					if (mark[vv] || vv < j) D.push_back(vv);
					else {
						for (int vv : D) N.erase(vv);
						if (N.empty()) 
							break;
						int v = *N.begin();
						N.erase(v);
						for (int vv : N) basis[v].insert(vv);
						mark[v] = 1;
						id.push_back(i);
						break;
					}
				}
			}
			break;
		}
	}
	int res = 1;
	for (int i = 0; i < id.size(); ++i) {
		res = res * 2;
		res %= MOD;
	}
	cout << res << ' ' << id.size() << endl;
	for (int v : id) cout << v << ' ';

	return 0;
}