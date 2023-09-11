#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1005, oo = 1e9 + 5;
int n, a[N], ans1, ans2;
vector <int> odd, even;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] > 0 && i & 1) {
			ans1 += a[i];
			odd.push_back(i);
		}
		if (a[i] > 0 && !(i & 1)) {
			ans2 += a[i];
			even.push_back(i);
		}
	}
	if (max(ans1, ans2) == 0) {
		int mx = -oo, id = -1;
		for (int i = 1; i <= n; ++i) {
			if (a[i] > mx) {
				mx = a[i];
				id = i;
			}
		}
		cout << mx << endl << n - 1 << endl;
		for (int i = 1; i < id; ++i) cout << 1 << endl;
		for (int i = n - id + 1; i > 1; --i) cout << i << endl;
		return 0;
	}
	cout << max(ans1, ans2) << endl;
	if (ans1 < ans2) {
		swap(even, odd);
	}
	vector <int> res; res.clear();
	for (int i = 1; i < odd[0]; ++i) {
		res.push_back(1);
	}
	for (int i = 0; i < odd.size() - 1; ++i) {
		int f1 = odd[i], f2 = odd[i + 1];
		int cen = (f1 + f2) >> 1;
		cen -= f1 - 1;
		for (int j = cen; j > 1; --j)
			res.push_back(j);
	}
	int rem = n - odd.back() + 1;
	for (int i = rem; i > 1; --i) res.push_back(i);
	cout << res.size() << endl;
	for (int v : res) cout << v << endl;

	return 0;
}