#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int a[N];


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskI.INP", "r", stdin);
	freopen("TaskI.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, s = 0, mn = (int)1e9;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			s += a[i];
			mn = min(mn, a[i]);
		}
		bool win = false;
		if (n & 1) {
			win = s & 1;
		} else {
			if (s & 1) win = true;
			else win = mn & 1;
		}
		if (win) cout << "Yalalov" << endl;
		else cout << "Shin" << endl;
	}

	return 0;
}