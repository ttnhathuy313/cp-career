#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, m, a[N], t, break_point = 0;

int calc(int mid) {
	int curt = 0, cons = 0, pre = 0, cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] <= mid) {
			if (curt + a[i] <= t) {
				curt += a[i];
				pre += a[i];
				cnt++;
				cons++;
			} else {
				break_point = 1;
				break;
			}
		}
		if (cons == m) {
			cons = 0;
			curt += pre;
			pre = 0;
		}
		if (curt > t) {
			break_point = 1;
			break;
		}
	}
	return cnt;
}

void solve() {
	cin >> n >> m >> t;
	vector <int> V; V.clear();
	set <int> S; S.clear();
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] <= t && S.find(a[i]) == S.end()) {
			V.push_back(a[i]);
			S.insert(a[i]);
		}
	}
	sort(V.begin(), V.end());
	if (V.size() == 0) {
		cout << 0 << ' ' << 1 << endl;
		return;
	}
	int l = 0, r = t, ans = 0, id = -1;
	while (l <= r) {
		break_point = 0;
		int mid = (l + r) >> 1;
		int cur = calc(mid);
		cerr << l << ' ' << r << ' ' << mid << endl;
		if (cur >= ans) {
			ans = cur;
			id = mid;
		}
		if (break_point) r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << ' ' << id << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}