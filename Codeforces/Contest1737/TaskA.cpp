#include <bits/stdc++.h>

using namespace std;

const int N = 205;
int n, k, f[26];
string s;

void solve() {
	cin >> n >> k >> s;
	memset(f, 0, sizeof f);
	for (int i = 0; i < s.size(); ++i) {
		f[s[i] - 'a']++;
	}
	for (int j = 1; j <= k; ++j) {
		int res = 0;
		for (int ch = 0; ch < 26; ++ch) {
			if (f[ch] == 0) {
				res = ch;
				break;
			}
		}
		res = min(res, n / k);
		for (int ch = 0; ch < res; ++ch) {
			f[ch]--;
		}
		cout << char('a' + res);
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}