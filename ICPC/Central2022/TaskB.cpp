#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, pi[N], ans[N], okay[N];
vector <int> dag[N];
string s;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> s;
	n = s.size();
	s += '#' + s;
	s = ' ' + s;

	memset(pi, -1, sizeof pi);
	for (int i = 1; i <= n * 2 + 1; ++i) {
		int cur = pi[i - 1];
		while (cur != -1) {
			if (s[cur + 1] == s[i]) {
				break;
			}
			if (cur == 0) {
				break;
			}
			cur = pi[cur];
		}
		if (s[cur + 1] != s[i]) {
			pi[i] = 0;
		} else pi[i] = cur + 1;

		cerr << i << ' ' << pi[i] << endl;

		if (i <= n + 1) {
			continue;
		}

		cur = pi[i];
		dag[cur].push_back(pi[cur]);
		ans[cur]++;
		if (i != 2 * n + 1) {
			continue;
		}
		while (cur != 0 && cur != -1) {
			// ans[cur]++;
			if (i == 2 * n + 1) {
				okay[cur] = 1;
			}
			cur = pi[cur];
		}
	}
	for (int i = 2 * n + 1; i >= 1; --i) {
		for (int j : dag[i]) {
			ans[j] += ans[i];
		}
	}
	
	int q;
	cin >> q;
	while (q--) {
		int l;
		cin >> l;
		if (okay[l] && ans[l] >= 3) {
			cout << "YES " << ans[l] << endl;
		} else cout << "NO" << endl;
	}

	return 0;
}