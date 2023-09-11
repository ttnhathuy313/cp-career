#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int n;
string s;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n >> s;
	n = s.size();
	s = ' ' + s;
	int d = 0;
	for (int i = 1; i <= n; ++i) if (i + 1 + i - 1 <= n) {
		if (s.substr(1, i) == s.substr(i + 1, i)) d = i;
	}
	int res;
	if (d == 0) res = n;
	else res = n - d + 1;
	cout << res << endl;

	return 0;
}