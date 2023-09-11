#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, a[N], b[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	// freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		int cnt0 = 0, cnt1 = 0, sum = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] == 0) cnt0++;
			else cnt1++;
		}
		vector <int> pref0, pref1;
		pref0.clear();
		pref1.clear();
		for (int i = 1; i <= n; ++i) {
			cin >> b[i];
			sum += b[i];
			if (a[i] == 0) pref0.push_back(b[i]);
			else pref1.push_back(b[i]);
		}
		sort(pref0.begin(), pref0.end(), greater <int>());
		for (int i = 1; i < pref0.size(); i++) {
			pref0[i] += pref0[i - 1];
		}

		sort(pref1.begin(), pref1.end(), greater <int>());
		for (int i = 1; i < pref1.size(); i++) {
			pref1[i] += pref1[i - 1];
		}

		int res = 0;
		int choice1 = min(cnt0 - 1, cnt1) - 1;
		if (cnt0 > 0) res = max(res, (choice1 >= 0 ? pref0[choice1] : 0) + 
			(choice1 + (cnt1 > cnt0 - 1) >= 0 ? pref1[choice1 + (cnt1 > cnt0 - 1)] : 0));
		int choice2 = min(cnt1 - 1, cnt0) - 1;
		if (cnt1 > 0) res = max(res, (choice2 + (cnt0 > cnt1 - 1) >= 0 ? pref0[choice2 + (cnt0 > cnt1 - 1)] : 0) + (choice2 >= 0 ? pref1[choice2] : 0));
		cout << sum + res << endl;
	}

	return 0;
}