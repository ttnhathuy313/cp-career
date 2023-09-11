#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5, LOG = 24;
int a[N], b[N], n, res;

int lw(int d, int i) {
	return lower_bound(b + 1, b + i, d) - b;
}

void solve(int k) {
	for (int i = 1; i <= n; ++i)
		b[i] = a[i] % (1 << (k + 1));
	sort(b + 1, b + 1 + n);
	int cnt = 0;
	for (int i = 2; i <= n; ++i) {
		int c1 = i - lw((1 << k) - b[i], i) + 1 - (i - lw((1 << (k + 1)) - b[i], i) + 1);
		int c2 = i - lw(3 * (1 << k) - b[i], i) + 1 - (i - lw((1 << (k + 2)) - b[i], i) + 1);
		cnt += c1 + c2;
	}
	if (cnt & 1) res += (1 << k);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 0; i <= LOG; ++i)
		solve(i);
	cout << res << endl;

	return 0;
}