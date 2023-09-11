#include <bits/stdc++.h>

using namespace std;

const int N = 1505;
int n, x[N], y[N];
typedef pair <int, int> ii;

struct Line {
	int a, b;
	double c;
	Line() {}
	Line(int _a, int _b, double _c) : a(_a), b(_b), c(_c) {}
	bool operator < (const Line other) const {
		return a < other.a;
	}
};
map <pair <Line, ii>, int> mp;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("HINHTHOI.INP", "r", stdin);
	freopen("HINHTHOI.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		// cerr << "(" << x[i] << ", " << y[i] << ")" << endl;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			pair <int, int> n1 = make_pair(y[i] - y[j], x[j] - x[i]);
			int coefa = n1.first, coefb = n1.second;
			int g = __gcd(coefa, coefb);
			coefa /= g; coefb /= g;
			double coefc = -1.0 * (coefa * x[i] + coefb * y[i]) / g;
			mp[make_pair(Line(coefa, coefb, coefc), ii(x[i] + x[j], y[i] + y[j]))]++;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			pair <int, int> n1 = make_pair(x[j] - x[i], y[j] - y[i]);
			int coefa = n1.first, coefb = n1.second;
			int g = __gcd(coefa, coefb);
			coefa /= g; coefb /= g;
			double m1 = 1.0 * (x[i] + x[j]) / 2;
			double m2 = 1.0 * (y[i] + y[j]) / 2;
			double coefc = -1.0 * (coefa * m1 + coefb * m2) / g;
			res += mp[make_pair(Line(coefa, coefb, coefc), ii(x[i] + x[j], y[i] + y[j]))];
		}
	}
	cout << (res >> 1) << endl;

	return 0;
}