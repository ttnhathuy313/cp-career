#include <bits/stdc++.h>

using namespace std;

char s[(int)1e5+ 5 ];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int k, n;
	cin >> k;
	string t;
	cin >> t;
	n = t.size();
	for (int i= 1; i <= n; ++i) s[i] = t[i - 1];
	sort(s + 1, s + 1 + n);
	int tot = 0;
	for (int i = 1; i <= n; ++i) tot += s[i] - '0';
	if (tot >= k) {
		cout << 0;
		return 0;
	}
	int i = 1, rem = k - tot;
	for (i = 1; i <= n; ++i) {
		rem -= '9' - s[i];
		if (rem <= 0) break;
	}
	cout << i << endl;

	return 0;
}