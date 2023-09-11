#include <bits/stdc++.h>

using namespace std;

bool removed[500];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int n;
	cin >> n;
	string s;
	cin >> s;
	int res = 0;
	for (int cur = 'z' - 'a'; cur >= 0; --cur) {
		int pre = -2;
		for (int i = 0; i < s.size(); ++i) if (!removed[i]) {
			if (s[i] - 'a' == cur) {
				if (pre == cur - 1) removed[i] = 1, res++;
			} else pre = s[i] - 'a';
		}
		pre = -2;
		for (int i = s.size() - 1; i >= 0; --i) if (!removed[i]) {
			if (s[i] - 'a' == cur) {
				if (pre == cur - 1) removed[i] = 1, res++;
			} else pre = s[i] - 'a';
		}
	}
	cout << res << endl;

	return 0;
}