#include <bits/stdc++.h>

using namespace std;
#define int long long 
typedef pair <int, int> ii;

const int N = 4e5 + 5;
int n, a[N], h, s, d, pref[N]; 

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("PROJECT.INP", "r", stdin);
	freopen("PROJECT.OUT", "w", stdout);

	cin >> n >> h >> s >> d;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int k = (h + d) / s;
	int res = 0;
	deque <int> dq; dq.clear();
	for (int i = 1; i <= n; ++i) {
		while (!dq.empty() && dq.front() < i - k - 1)
			dq.pop_front();
		int mx = (dq.size() > 0 ? a[dq.front()] : 0);
		while (!dq.empty() && a[dq.back()] < a[i])
			dq.pop_back();
		if (dq.empty()) {
			res -= (a[i] - mx) * (i - 1) * s - (h + d) * (a[i] - mx);
			pref[i] += a[i] - mx;
		}
		dq.push_back(i);
	}
	dq.clear();
	for (int i = n; i >= 1; --i) {
		while (!dq.empty() && dq.front() > i + k + 1)
			dq.pop_front();
		int mx = (dq.size() > 0 ? a[dq.front()] : 0);		
		while (!dq.empty() && a[dq.back()] < a[i])
			dq.pop_back();
		if (dq.empty()) {
			res += (a[i] - mx) * i * s;
			pref[i + 1] -= a[i] - mx;
		}
		dq.push_back(i);
	}
	cout << res << endl;
	for (int i = 1; i <= n; ++i) {
		pref[i] += pref[i - 1];
		cout << pref[i] << ' ';
	}

	return 0;
}