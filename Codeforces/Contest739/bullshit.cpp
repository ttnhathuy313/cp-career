#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 500;
int a[N], b[N], n;

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("bullshit.INP", "r", stdin);
	freopen("bullshit.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		a[i] = Rand(5, 60);
		b[i] = Rand(a[i] + 1, 70);
		cerr << a[i] << ' ' << b[i] << ' ' << fixed << setprecision(9) << 1.0 * a[i] / b[i] << endl;
	}
	double tmp = N;
	ii d;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (1.0 * (a[i] + a[j]) / (b[i] + b[j]) < tmp) {
				tmp = min(tmp, 1.0 * (a[i] + a[j]) / (b[i] + b[j]));
				d = ii(i, j);
			}
		}
	}
	cerr << "~~~~~~~~~~~~~~~~~~~~~\n";
	cerr << a[d.first] << ' ' << b[d.first] << ' ' << fixed << setprecision(9) << 1.0 * a[d.first] / b[d.first] << endl;
	cerr << a[d.second] << ' ' << b[d.second] << ' ' << fixed << setprecision(9) << 1.0 * a[d.second] / b[d.second] << endl;
	cerr << fixed << setprecision(9) << tmp << endl;

	return 0;
}