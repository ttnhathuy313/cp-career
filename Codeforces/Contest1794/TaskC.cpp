#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		queue <int> id;
		while (!id.empty()) {
			id.pop();
		}
		int curId = 1, longId = 1;
		double curProd = 1.0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] > curId) {
				curId++;
				id.push(i);
				curProd = curProd * a[i] / (curId - 1);
				while (!id.empty() && 1.0 < 1.0 / a[id.front()] * (int) id.size()) {
					curProd = curProd / a[id.front()] * (int) id.size();
					id.pop();
					curId--;
				}
				longId = curId;
			} else if (a[i] == longId) {
				if (!id.empty() && a[id.front()] != a[i]) {
					curProd = curProd / a[id.front()] * a[i];
					id.pop();
					id.push(i);
				} else {
					longId++;
				}
			}
			cout << longId - 1 << ' ';
		}
		cout << endl;
	}
	// cerr << fixed << setprecision(9) << 2 * 4 / (1 * 2) << endl;

	return 0;
}