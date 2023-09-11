#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 5e5 + 5;
int n, a[N], m;

void solve() {
	cin >> n >> m;
	vector <ii> V;
	V.clear();
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		V.push_back({a[i], i});
	}
	sort(V.begin(), V.end());
	int res_id = 0, rem = m;
	for (auto v : V) {
		if (v.first <= rem) {
			rem -= v.first;
			res_id++;
		} else {
			break;
		}
	}
	int res = n - res_id, mx = 0;
	bool found = false;
	for (int i = 0; i < res_id; ++i) {
		auto v = V[i];
		if (v.second == res_id + 1) {
			found = true;
		}
		mx = max(mx, v.first);
	}
	if (found) {
		res--;
		
	} else if (rem + mx - a[res_id + 1] >= 0) {
			res--;
	}
	cout << max(1, res + 1) << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}