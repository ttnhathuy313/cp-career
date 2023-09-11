#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, a[N], b[N], cnt1[N], cnt2[N];
vector <int> el1[N], el2[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskI.INP", "r", stdin);
	freopen("TaskI.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt1[a[i]]++;
		el1[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		cnt2[b[i]]++;
		el2[b[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i) if (cnt1[i] > 0 && cnt2[i] > 0) {
		cout << 1 << ' ' << el1[i][0] << endl;
		cout << 1 << ' ' << el2[i][0] << endl;
		return 0;
	}
	vector <int> A, B; A.clear(); B.clear();
	for (int i = 1; i <= n; ++i) if (cnt1[i] > 0) A.push_back(i);
	for (int i = 1; i <= n; ++i) if (cnt2[i] > 0) B.push_back(i);
	if (A[0])


	return 0;
}