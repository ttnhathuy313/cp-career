#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int req[N];

void solve() {
	int n;
	string s;
	cin >> s;
	n = s.size();
	string hangdoi;
	cin >> hangdoi;
	int k = hangdoi.size();
	for (int i = 0; i <= k; ++i)
		req[i] = 0;
	int len = 0;
	vector <int> w; w.clear();

	for (int i = 0; i < n; ++i) {
		if (s[i] == 'X') {
			if (len > 0) w.push_back(len);
			len = 0;
		} else len++;
	}
	if (len) w.push_back(len);
	priority_queue <int> pq;
	while (!pq.empty()) pq.pop();
	for (int i : w) {
		req[0] += i / 2;
		pq.push(i);
	}
	for (int i = 1; i <= k; ++i) {
		int x = pq.top();
		if (x <= 2) {
			req[i] = req[i - 1];
			continue;
		}
		pq.pop();
		req[i] = req[i - 1] - (x / 2) + ((x - 3) / 2);
		pq.push(x - 3);
	}

	if (req[0] == 0) cout << "N";
	else cout << "Y";		
	int n1 = 0, n2 = 0;
	for (int i = 0; i < k; ++i) {
		if (hangdoi[i] == 'M') n1++;
		else n2++;
		if (req[n2] <= n1) cout << "N";
		else cout << "Y";
	}
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("TaskG.INP", "r", stdin);
	// freopen("TaskG.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}