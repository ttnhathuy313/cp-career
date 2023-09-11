#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int n, a[N], suf[N];
stack <int> odd, even;


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("TaskL.INP", "r", stdin);
	// freopen("TaskL.OUT", "w", stdout);

	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
		if (a[i] & 1) odd.push(a[i]);
		else even.push(a[i]);
	}
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0') {
			vector <int> wodd; wodd.clear();
			vector <int> weven; weven.clear();
			while (!even.empty()) {
				int x = even.top(); even.pop();
				sum -= x;
				x >>= 1;
				sum += x;
				if (x == 0) continue;
				if (x & 1) wodd.push_back(x);
				else weven.push_back(x);
			}
			for (int i : wodd) odd.push(i);
			for (int i : weven) even.push(i);
			cout << sum << endl;
		} else {
			vector <int> wodd; wodd.clear();
			vector <int> weven; weven.clear();
			while (!odd.empty()) {
				int x = odd.top(); odd.pop();
				sum -= x;
				x--;
				sum += x;
				if (x == 0) continue;
				if (x & 1) wodd.push_back(x);
				else weven.push_back(x);
			}
			for (int i : wodd) odd.push(i);
			for (int i : weven) even.push(i);
			cout << sum << endl;
		}
	}

	return 0;
}