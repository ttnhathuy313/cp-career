#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2e5 + 5;
int n, k, a[N], b[N];
vector <ii> power[N];

int timeDie(int x, int y) {
	return (x + y) / y;
}

bool check(int mid) {
	for (int i = 1; i <= k; ++i)
		power[i].clear();
	for (int i = 1; i <= n; ++i) {
		int T = timeDie(a[i], b[i]);
		if (T > k) continue;
		power[T].push_back({a[i], i});
	}
	int j = 1;
	for (int i = 1; i <= k; ++i) {
		while (power[j].empty() && j <= k) j++;
		if (j < i) return false;
		if (j == k + 1) return true;
		int v = power[j].back().first, id = power[j].back().second;
		power[j].pop_back();
		int T = timeDie(v + mid, b[id]);
		if (T <= k) {
			power[T].push_back({v + mid, id});
		}
	}
	return true;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	int l = 0, r = (int)2e12, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	cout << ans << endl;

	return 0;
}