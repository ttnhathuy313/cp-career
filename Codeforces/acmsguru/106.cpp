#include <bits/stdc++.h>

using namespace std;
#define int long long

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

bool find_any_solution(int a, int b, int c, int &x, int &y, int &g) {
	g = extended_gcd(abs(a), abs(b), x, y);
	if (c % g) return false;
	int v = c / g;
	x *= v;
	y *= v;
	if (a < 0) x = -x;
	if (b < 0) y = -y;
	return true;
}

void shift(int a, int b, int &x, int &y, int cnt) {
	x += cnt * b;
	y -= cnt * a;
}

int find_in_range(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
	int x, y, g, lx1, lx2, rx1, rx2;
	if (!find_any_solution(a, b, c, x, y, g))
		return 0;
	a /= g, b /= g;
	int sign_a = (a > 0 ? 1 : -1), sign_b = (b > 0 ? 1 : -1);
	shift(a, b, x, y, (minx - x) / b);
	if (x < minx) shift(a, b, x, y, sign_b);
	if (x > maxx) return 0;
	lx1 = x;
	shift(a, b, x, y, (maxx - x) / b);
	rx1 = x;
	shift(a, b, x, y, -(miny - y) / a);
	if (y < miny)
		shift(a, b, x, y, -sign_a);
	if (y > maxy) return 0;
	lx2 = x;
	shift(a, b, x, y, -(maxy - y) / a);
	rx2 = x;
	if (lx2 > rx2) swap(lx2, rx2);
	int lx, rx;
	lx = max(lx1, lx2);
	rx = min(rx2, rx1);
	if (lx > rx) return 0;

	return (rx - lx) / abs(b) + 1;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
 	freopen("106.INP", "r", stdin);
	freopen("106.OUT", "w", stdout);
 
	int a, b, c, lx, rx, ly, ry;
	cin >> a >> b >> c >> lx >> rx >> ly >> ry;
	if (a == 0 && b == 0) {
		if (c == 0) cout << (rx - lx + 1) * (ry - ly + 1) << endl;
		else cout << 0 << endl;
		return 0;
	}
	if (b == 0) {
		swap(a, b); swap(lx, ly); swap(rx, ry);
	}
	if (a == 0) {
		int x = -c / b;
		if (c % b) {
			cout << 0 << endl;
			return 0;
		}
		if (x > ry || x < ly) cout << 0 << endl;
		else cout << rx - lx + 1 << endl;
		return 0;
	}
	cout << find_in_range(a, b, -c, lx, rx, ly, ry) << endl;
 
	return 0;
}