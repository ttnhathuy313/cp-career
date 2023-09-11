#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 3e5 + 5;
int n, k, a[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) 
		cin >> a[i];
	vector <int> val; val.clear();
	int cur = 0;
	for (int i = n; i >= 2; --i) {
		cur += a[i];
		val.push_back(cur);
	}
	int res = cur + a[1];
	sort(val.begin(), val.end(), greater <int>());
	for (int i = 0; i < k - 1; ++i) res += val[i];
	cout << res << endl;

	return 0;
}