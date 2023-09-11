#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
int a[N], n, d[N];

int degCal() {
	bool ok = false;
	int ret = 0;
	while (!ok) {
		ret++;
		for (int i = 1; i <= n - 1; ++i) d[i] = d[i + 1] - d[i];
		ok = true;
		for (int i = 2; i <= n - ret; ++i) if (d[i] != d[i - 1]) {
			ok = false;
			break;
		}
	}
	return ret;
}

void solve2() {
	for (int A = -200; A <= 200; A++)
		for (int b = -200; b <= 200; ++b)
			for (int c = -200; c <= 200; ++c) {
				if (A + b + c == a[1] && 4 * A + 2 * b + c == a[2] && 9 * A + 3 * b + c == a[3]) {
					cout << A << "n ^ 2 + " << b << "n + " << c << endl;
				}
			}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("NumberSeriesFormula.inp", "r", stdin);
	freopen("NumberSeriesFormula.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		d[i] = a[i];
	}
	if (degCal() == 2) {
		solve2();
	}
	return 0;
}