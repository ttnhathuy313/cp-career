#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;
int n, a[N];
map <int, int> cnt;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
		res = max(res, cnt[a[i]]);
	}
	cout << res << endl;

	return 0;
}