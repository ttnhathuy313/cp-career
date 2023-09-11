#include <bits/stdc++.h>

using namespace std;

int extended_gcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int g = extended_gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

bool find_any(int a, int b, int c, int &x, int &y, int &g) { // ax + by = c, find any (x, y)
	g = extended_gcd(abs(a), abs(b), x, y);
	if (c % g) return false;
	int v = c / g;
	x *= v;
	y *= v;
	if (a < 0) x = -x;
	if (b < 0) y = -y;
	return true;
}

void shift(int &x, int &y, int a, int b, int cnt) {
	x += cnt * b;
	y -= cnt * a;
}

int find_in_range(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
	int g, x, y, lx1, lx2, rx1, rx2;
	if (!find_any(a, b, c, x, y, g)) return 0;
	b /= g;
	a /= g;
	int sign_a = a < 0 ? -1 : 1;
	int sign_b = b < 0 ? -1 : 1;

	shift(x, y, a, b, (minx - x) / b);
	if (x < minx) 
		shift(x, y, a, b, sign_b);
	if (x > maxx)
		return 0;
	lx1 = x;
	shift(x, y, a, b, (maxx - x) / b);
	if (x > maxx)
		shift(x, y, a, b, -sign_b);
	rx1 = x;

	shift(x, y, a, b, -(miny - y) / a);
	if (y < miny)
		shift(x, y, a, b, -sign_a);
	if (y > maxy)
		return 0;
	lx2 = x;
	shift(x, y, a, b, -(maxy - y) / a);
	if (y > maxy)
		shift(x, y, a, b, sign_a);
	rx2 = x;

	if (lx2 > rx2) swap(lx2, rx2);
	int lx = max(lx2, lx1);
	int rx = min(rx2, rx1);
	if (lx > rx) return 0;
	return (rx - lx) / abs(b) + 1;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("106.INP", "r", stdin);
	freopen("106.ans", "w", stdout);

	int a, b, c, lx, rx, ly, ry;
	cin >> a >> b >> c >> lx >> rx >> ly >> ry;
	int res = 0;
	for (int i = lx; i <= rx; ++i) {
		for (int j = ly; j <= ry; ++j) if (i * a + b * j + c == 0)
			res++;
	}
	cout << res << endl;

	return 0;
}