#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int a[N], n;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0) {
			if (res == 0) continue;
			if (a[i - 1] == 1 && a[i + 1] == 1) res++;
		} else {
			res++;
		}
	}
	cout << res << endl;

	return 0;
}