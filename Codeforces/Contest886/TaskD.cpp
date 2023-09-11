#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define forn(i, a, b) for (int i = a; i <= b; ++i)

const int N = 1e5 + 5;
int n, p[30], cnt[30], deg[30], out[30];
string s[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n;
	forn(i, 1, n) {
		cin >> s[i];
		int c[27];
		memset(c, 0, sizeof c);
		rep(j, s[i].size()) {
			cnt[s[i][j] - 'a']++;
			if (c[s[i][j] - 'a'] == 0) c[s[i][j] - 'a']++;
			else {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	memset(p, -1, sizeof p);
	forn(i, 1, n) {
		rep(j, s[i].size() - 1) {
			if (p[s[i][j] - 'a'] != s[i][j + 1] - 'a' && ~p[s[i][j] - 'a']) {
				cout << "NO" << endl;
				return 0;
			}
			deg[s[i][j + 1] - 'a']++;
			p[s[i][j] - 'a'] = s[i][j + 1] - 'a';
		}
	}
	int need = 0;
	string res; res.clear();
	rep(i, 26) if (cnt[i]) {
		int cur = i;
		need++;
		if (deg[i] != 0) continue;
		while (cur != -1) {
			out[cur] = 1;
			res += char('a' + cur);
			cur = p[cur]; 
			if (out[cur]) {
				cout << "NO";
				return 0;
			}
		}
	}
	if (res.size() != need) cout << "NO";
	else cout << res;

	return 0;
}