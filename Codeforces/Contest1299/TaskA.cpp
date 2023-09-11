#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int a[N], n, pref[N], suf[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		pref[i] = a[i] | pref[i - 1];
	for (int i = n; i >= 1; --i)
		suf[i] = a[i] | suf[i + 1];
	int res = -1, id = -1;
	for (int i = 1; i <= n; ++i) {
		int v = pref[i - 1] | suf[i + 1];
		int val = 0;
		for (int j = 0; j < 31; ++j) if (a[i] & (1 << j)) {
			if (v & (1 << j)) val += 0;
			else val += (1 << j);
		}
		if (res < val) {
			res = val;
			id = i;
		}
	}
	cout << a[id] << " ";
	for (int i = 1; i <= n; ++i) if (i != id) cout << a[i] << ' ';

	return 0;
}