#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int a[N], ans[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int lst = -N;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0) lst = i;
		ans[i] = i - lst;
	}
	lst = N + N;
	for (int i = n; i >= 1; --i) {
		if (a[i] == 0) lst = i;
		ans[i] = min(ans[i], lst - i);
	}
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';


	return 0;
}