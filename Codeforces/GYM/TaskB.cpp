#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e3 + 5;
int p[N], s[N], f[N][N];

void solve() {
	memset(p, 0, sizeof p);
	memset(s, 0, sizeof s);
	memset(f, 0, sizeof s);
	string S;
	int n; cin >> n;
	cin >> S;
	S = ' ' + S;
	for (int i = 1; i <= n; ++i) {
		p[i] = p[i - 1];
		if (S[i] == 'S') p[i]++;
		else if (S[i] == 'P') p[i]--;
	}
	for (int i = n; i >= 1; --i) {
		s[i] = s[i + 1];
		if (S[i] == 'P') s[i]++;
		else if (S[i] == 'R') s[i]--; 
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			f[i][j] = f[i][j - 1];
			if (S[j] == 'S') f[i][j]--;
			else if (S[j] == 'R') f[i][j]++;
		}
	}
	int res = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = i + 1; j <= n + 1; ++j) {
			if (p[i] + f[i + 1][j - 1] + s[j] > 0) res++;
		}
	}
	cout << res << endl;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.inp", "r", stdin);
	freopen("TaskB.out", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}