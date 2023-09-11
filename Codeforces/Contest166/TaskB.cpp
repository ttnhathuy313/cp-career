#include <bits/stdc++.h>

using namespace std;
#define int long long

struct Point {
	int x, y;
	Point() {}
	Point(int _x, int _y) : x(_x), y(_y) {}
};

Point toVec(Point a, Point b) {
	return Point(b.x - a.x, b.y - a.y);
}

int cross(Point a, Point b) {
	return a.x * b.y - a.y * b.x;
}

bool ccw(Point a, Point b, Point c) {
	return cross(toVec(a, b), toVec(a, c)) > 0;
}

int S(Point a, Point b, Point c) {
	return abs(cross(toVec(a, b), toVec(a, c)));
}

bool collinear(Point a, Point b, Point c) {
	return cross(toVec(a, b), toVec(a, c)) == 0;
}

bool inside(Point m, Point a, Point b, Point c) {
	if (collinear(b, c, m)) return 0;
	return (S(a, b, c) == S(a, b, m) + S(b, c, m) + S(a, c, m));
}

const int N = 1e5 + 5;
Point P[N];
int n;

bool check(Point m) {
	int l = 2, r = n, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (!ccw(P[1], m, P[mid])) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	if (ans == -1) return false;
	if (ans == 2) return 0;
	if (ans == n && collinear(P[1], P[ans], m)) return 0;
	return inside(m, P[1], P[ans], P[ans - 1]);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> P[i].x >> P[i].y;
		// cerr << "(" << P[i].x << ", " << P[i].y << ")" << endl;
 	}
	int q; bool f = true;
	cin >> q; 
	while (q--) {
		int x, y;
		cin >> x >> y;
		// cerr << "(" << x << ", " << y << ")" << endl;
		if (!check({x, y})) f = false;
	}
	if (f) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}