#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 1505;
int n;
ii p[N];

int dist(ii a, ii b) {
	return (b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("HINHTHOI.INP", "r", stdin);
	freopen("HINHTHOI.ANS", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].first >> p[i].second;
		// cerr << "(" << x[i] << ", " << y[i] << ")" << endl;
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				for (int t = 1; t <= n; ++t) {
					set <int> id; id.clear();
					id.insert(i); id.insert(j); id.insert(k); id.insert(t);
					if (id.size() < 4) continue;
					set <int> d; d.clear();
					d.insert(dist(p[i], p[j]));
					d.insert(dist(p[i], p[t]));
					d.insert(dist(p[j], p[k]));
					d.insert(dist(p[k], p[t]));
					if (d.size() == 1) res++;
				}
			}
		}
	}
	cout << res / 8 << endl;

	return 0;
}