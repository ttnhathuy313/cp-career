#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
int ans[N], n, a, b;

pair <int, int> check() {
	vector <int> f(n + 5, 0), g(n + 5, 0);
	int c, d; c = d = 0;
	for (int i = 1; i <= n; ++i) {
		f[i] = g[i] = 1;
		for (int j = 1; j < i; ++j) {
			if (ans[i] > ans[j]) f[i] = max(f[i], f[j] + 1);
			if (ans[i] < ans[j]) g[i] = max(g[i], g[j] + 1);
			c = max(c, f[i]);
			d = max(d, g[i]);
		}
	}
	return {c, d};
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> a >> b;

	// for (int i = 1; i <= n; ++i) ans[i] = i; random_shuffle(ans + 1, ans + 1 + n);
	// a = check().first, b = check().second;
	// cout << a << ' ' << b << endl;
	// for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;

	if (b == 1) {
		if (a != n) {
			cout << -1 << endl;
			return 0;
		}
		for (int i = 1; i <= n; ++i) cout << i << ' ';
		return 0;
	}

	for (int i = n - b + 1; i <= n; ++i) {
		ans[i] = n - (i - (n - b + 1));
	}
	int rem = n - b;
	a--;
	if (a > rem) {
		cout << -1 << endl;
		return 0;
	}
	if (a == rem) {
		for (int i = 1; i <= rem; ++i)
			ans[i] = i;
	} else {
		if (rem / b + (rem % b != 0) > a) {
			cout << -1 << endl;
			return 0;
		}
		for (int i = 1; i <= rem; ++i) ans[i] = i;
		int del = rem - a;
		int i = 1;
		for (i = 1; i <= n; i += b) {
			// cerr << i << ' ' << del << endl;
			if (del >= b - 1) {
				reverse(ans + i, ans + i + b);
				del -= b - 1;
			} else {
				reverse(ans + i, ans + del + i + 1);
				break;
			}
		}
	}
	for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
	cout << endl;
	// pair <int, int> D = check();
	// cout << D.first << ' ' << D.second << endl;

	return 0;
}