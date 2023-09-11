#include <bits/stdc++.h>

using namespace std;

const int N = 105;
string s[N];
int p[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int n, m;
	cin >> n >> m;
	memset(p, -1, sizeof p);
	for (int i = 1; i <= n; ++i) cin >> s[i];
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			reverse(s[j].begin(), s[j].end());
			if (s[i] == s[j]) p[i] = j;
			reverse(s[j].begin(), s[j].end());
		}
	}
	int sz = 0, id = -1;
	string t;
	t.clear();
	for (int i = 1; i <= n; ++i) {
		if (p[i] != -1) {
			t += s[i];
		} else {
			string d = s[i];
			reverse(d.begin(), d.end());
			if (d != s[i]) continue;
			if (s[i].size() > sz) {
				sz = s[i].size();
				id = i;
			}
		}
	}
	int res = t.size() * 2;
	if (id != -1) res += sz;
	cout << res << endl;
	cout << t;
	if (id != -1) cout << s[id];
	reverse(t.begin(), t.end());
	cout << t << endl;

	return 0;
}