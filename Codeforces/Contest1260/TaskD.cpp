#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;
typedef pair <ii, int> iii;
#define int long long

const int N = 2e5 + 5;
int a[N], m, n, k, t;
vector <iii> E;

bool check(int mid) {
	int lw = a[mid];
	int mxr = 0, tmp = 0, lstl = 0;
	for (iii e : E) {
		if (e.second <= lw) continue;
		int l = e.first.first, r = e.first.second;
		if (mxr >= l) {
			mxr = max(mxr, r);
		} else {
			if (mxr != 0) tmp += mxr - lstl + 1;
			lstl = e.first.first;
			mxr = r;
		}
	}
	if (mxr != 0) tmp += mxr - lstl + 1;
	tmp *= 2;
	tmp += n + 1;
	if (tmp <= t) return 1; 
	else return false;
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);
	freopen("TaskD.out", "w", stdout);

	cin >> m >> n >> k >> t;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + m, greater <int> ());
	for (int i = 1; i <= k; ++i) {
		int l, r, d;
		cin >> l >> r >> d;
		E.push_back(iii(ii(l, r), d));
	}
	sort(E.begin(), E.end());
	int l = 1, r = m, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	if (ans == -1) ans = 0;
	cout << ans << endl;

	return 0;
}