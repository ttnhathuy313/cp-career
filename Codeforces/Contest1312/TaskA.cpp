#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		if (b % a == 0) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}

	return 0;
}