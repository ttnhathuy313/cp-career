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
		int n;
		cin >> n;
		long long a = (1ll << n) + ((1ll << (n / 2)) - 1);
        long long b = (1ll << (n + 1)) - a;
        cout << abs(a - b) << '\n';
	}

	return 0;
}