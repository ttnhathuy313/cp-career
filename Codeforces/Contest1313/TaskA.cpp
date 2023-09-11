#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int a, b, c;
		cin >> a >> b >> c;
		vector <int> d; d.clear();
		d.push_back(a);
		d.push_back(b);
		d.push_back(c);
		sort(d.begin(), d.end(), greater <int>());
		a = d[0], b = d[1], c = d[2];
		int res = 0;
		if (a > 0) res++, a--;
		if (b > 0) res++, b--;
		if (c > 0) res++, c--;
		if (a > 0 && b > 0) {
			res++;
			a--; b--;
		}
		if (a > 0 && c > 0) {
			res++;
			a--; c--;
		}
		if (c > 0 && b > 0) {
			res++;
			c--; b--;
		}
		if (a > 0 && b > 0 && c > 0) {
			res++;
		}
		cout << res << endl;
	}

	return 0;
}