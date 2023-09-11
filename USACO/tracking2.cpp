#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, a[N], res[N], c[N], lwb[N], check[N];

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}


int main(int argc, char const *argv[])
{
	srand(time(NULL));
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("tracking2.INP", "r", stdin);
	freopen("tracking2.OUT", "w", stdout);

	int n = 12, k = 4;
	for (int i = 1; i <= n; ++i) {
		a[i] = Rand(2, 18);
	}
	for (int i = 1; i <= n - k + 1; ++i) {
		c[i] = (int)1e9;
		for (int j = i; j <= i + k - 1; ++j)
			c[i] = min(c[i], a[j]);
	}
	for (int i = 1;i <= n; ++i) {
		for (int j = max(1, i - k + 1); j <= min(i, n - k + 1); ++j)
			lwb[i] = max(lwb[i], c[j]);
	}
	for (int i = 1; i < n - k + 1; ++i) {
		if (c[i] == c[i + 1]) {
			res[i] = Rand(lwb[i], (int)100);
		} else {
			res[i] = c[i];
		}
	}
	res[n - k + 1] = c[n - k + 1];
	for (int i = 1; i <= n - k + 1; ++i) cerr << c[i] << ' '; cerr << endl;
	for (int i = n - k + 2; i <= n; ++i)
		res[i] = Rand(lwb[i], 100);
	for (int i = 1; i <= n; ++i) cerr << res[i] << ' '; cerr << endl;
	for (int i = 1; i <= n - k + 1; ++i) {
		check[i] = (int)1e9;
		for (int j = i; j <= i + k - 1; ++j)
			check[i] = min(check[i], res[j]);
	}
	for (int i = 1; i <= n - k + 1; ++i) {
		if (check[i] != c[i]) {
			cerr << "Wrong" << endl;
			return 0;
		}
	}
	cerr << "Yes" << endl;

	return 0;
}