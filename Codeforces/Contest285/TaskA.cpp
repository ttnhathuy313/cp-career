#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int n, k;
	cin >> n >> k;
	for (int i = n; i >= n - k + 1; --i) cout << i << ' ';
	for (int i = 1; i <= n - k; ++i) cout << i << ' ';

	return 0;
}