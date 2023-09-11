#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		string a, b, c;
		cin >> a >> b >> c;
		bool ok = true;
		for (int i = 0; i < a.size(); ++i) {
			if (c[i] == b[i] || c[i] == a[i]) continue;
			else ok = false;
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}