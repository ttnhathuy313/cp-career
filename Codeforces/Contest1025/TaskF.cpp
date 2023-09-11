#include <bits/stdc++.h>

using namespace std;
#define int long long

struct Point {
	int x, y;
	Point() {}
	Point(int _x, int _y) : x(_x), y(_y) {}
	bool upper() const {
		return y > 0 || (y == 0 && x > 0);
	}
	bool operator < (const Point &other) const {
		if (upper() != other.upper()) {
			return upper();
		} else {
			return x * other.y - y * other.x > 0;
		}
	}
};

const int N = 2505;
int n, ans;
Point p[N];

int solve(int u) {
	vector <pair <Point, int>> ve;
	ve.clear();
	int cnt = 0, ret = 0;
	for (int i = 1; i <= n; ++i) if (i != u) {
		int x = p[i].x - p[u].x, y = p[i].y - p[u].y;
		ve.push_back({Point(x, y), 1});
		ve.push_back({Point(-x, -y), 0});
		cnt += Point(x, y).upper();
	}
	sort(ve.begin(), ve.end());
	for (pair <Point, int> v : ve) {
		if (v.second) {
			cnt--;
			ret += cnt * (cnt - 1) / 2 * (n - 3 - cnt) * (n - 2 - cnt) / 2;
		} else cnt++;
	}
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].x >> p[i].y;
	}
	for (int i = 1; i <= n; ++i) {
		ans += solve(i);
	}
	cout << ans / 2 << endl;

	return 0;
}