#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
bool pref[N], suf[N];
int p[N], n, m;
string s, t;

void solve(int len) {
	for (int i = len; i <= m; ++i) {
		if (!pref[i - len] || !suf[i + 1]) continue;
		int num = 0;
		for (int j = i - len + 1; j <= i; ++j) {
			num *= 10;
			num += t[j] - '0';
		}
		int id = n - m + i;
		if (id < 1) continue;
		if (p[id] - p[i - len] == num) {
			cout << i - len + 1 << ' ' << id << endl;
			exit(0);
		}
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("PASSWORD.INP", "r", stdin);
	freopen("PASSWORD.OUT", "w", stdout);

	cin >> s >> t;
	n = s.size(), m = t.size();
	s = ' ' + s; t = ' ' + t;
	for (int i = 1; i <= n; ++i) {
		p[i] = p[i - 1];
		p[i] += s[i] - '0';
	}
	pref[0] = 1;
	for (int i = 1; i <= m; ++i) {
		if (!pref[i - 1]) continue;
		if (i > n) continue;
		if (s[i] != t[i]) continue;
		pref[i] = true;
	}
	suf[m + 1] = 1;
	for (int i = m; i >= 1; --i) {
		int j = n - m + i;
		if (j < 1) break;
		if (!suf[i + 1]) break;
		if (s[j] != t[i]) continue;
		suf[i] = true;
	}
	for (int i = 1; i <= 7; ++i) solve(i);

	return 0;
}