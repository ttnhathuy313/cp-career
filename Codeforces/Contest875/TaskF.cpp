#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, m, a[N], b[N], w[N], lab[N];
bool avail[N];

int root(int x) {
	return (lab[x] == -1 ? x : lab[x] = root(lab[x]));
}

bool unite(int u, int v) {
	int x = root(u), y = root(v);
	if (x == y) {
		if (avail[x]) {
			avail[x] = false;
			return true;
		} else return false;
	} else {
		if (!avail[x] && !avail[y]) return false;
		lab[y] = x;
		avail[x] = (avail[x] & avail[y]);
		return true;
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n >> m;
	vector <int> ind; ind.clear();
	for (int i = 1; i <= m; ++i) {
		cin >> a[i] >> b[i] >> w[i];
		ind.push_back(i);
	}
	sort(ind.begin(), ind.end(), [](int i, int j) {
		return w[i] > w[j];
	});
	for (int i = 1; i <= n; ++i)
		lab[i] = -1, avail[i] = 1;
	int res = 0;
	for (int i : ind) {
		int u = a[i], v = b[i];
		if (unite(u, v)) res += w[i];
	}
	cout << res << endl;

	return 0;
}