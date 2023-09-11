#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
#define x first
#define y second


ii a[5];
int dist(ii a, ii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int calc(int u, int v, int mid) {
	ii p1 = ii(u, v), p2 = ii(u + mid, v), p3 = ii(u + mid, v + mid), p4 = ii(u, v + mid);
	vector <int> id; id.clear();
	int ret = (int)1e18;
	for (int i = 1; i <= 4; ++i) id.push_back(i);
	do {
		int tmp = dist(p1, a[id[0]]) + dist(p2, a[id[1]]) + dist(p3, a[id[2]]) + dist(p4, a[id[3]]);
		ret = min(ret, tmp);
	}while (next_permutation(id.begin(), id.end()));
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		for (int i = 1; i <= 4; ++i) {
			cin >> a[i].x >> a[i].y;
		}
		int res = (int)1e18;
		for (int i = 1; i <= 4; ++i) {
			for (int j = 1; j <= 4; ++j) {
				int u = a[i].x, v = a[j].y;
				cerr << u << ' ' << v << endl;
				int l = 1, r = (int)1e9, ans = (int)1e18;
				while (l <= r) {
					int mid = (l + r) >> 1;
					ans = min(ans, calc(u, v, mid));
					cerr << l << ' ' << r << endl;
					int la, ra;
					if (l != 1) la = calc(u, v, mid - 1);
					else la = (int)1e18;
					if (ra != (int)1e9) ra = calc(u, v, mid + 1);
					else ra = (int)1e18;
					cerr << "	" << la << ' ' << ra << endl;
					if (la > ra) l = mid + 1;
					else r = mid - 1;
				}
				res = min(res, ans);
			}
		}
		cout << res << endl;
	}

	return 0;
}