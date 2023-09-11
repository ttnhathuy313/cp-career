#include <bits/stdc++.h>

using namespace std;

int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int w, d, h;
		cin >> w >> d >> h;
		int a, b, f, g;
		cin >> a >> b >> f >> g;
		int res = dist(f, 0, a, b) + g;
		res = min(res, dist(f, d, a, b) + d - g);
		res = min(res, dist(0, g, a, b) + f);
		res = min(res, dist(w, g, a, b) + w - f);
		res += h;
		cout << res << endl;
	}

	return 0;
}