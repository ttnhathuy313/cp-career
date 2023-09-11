#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, a[N], m;
vector <int> infected, seg;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		infected.clear();
		seg.clear();
		for (int i = 1; i <= m; ++i) {
			int x;
			cin >> x;
			infected.push_back(x);
		}
		sort(infected.begin(), infected.end());
		for (int i = 0; i < m - 1; ++i) {
			seg.push_back(infected[i + 1] - infected[i] - 1);
		}
		seg.push_back(n - infected[m - 1] + infected[0] - 1);
		sort(seg.begin(), seg.end());
		int saved = 0, days = 0;
		while (seg.size() > 0) {
			// cerr << seg.back() << endl;
			if (seg.back() - days * 2 == 1) {
				saved += 1;
				days += 1;
				seg.pop_back();
				continue;
			}
			// cerr << seg.back() << ' ' << seg.back() - days - 1 << endl;
			saved += max(0, seg.back() - days * 2 - 1);
			days += 2;
			seg.pop_back();
		}
		cout << n - saved << endl;
	}

	return 0;
}