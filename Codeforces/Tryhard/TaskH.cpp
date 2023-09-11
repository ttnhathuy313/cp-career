#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6 + 5;
int n, m, a[N], b[N], lab[N * 2];
bool avail[N * 2];
 
int root(int x) {
	return (lab[x] == -1 ? x : lab[x] = root(lab[x]));
}
 
bool unite(int u, int v) {
	if (!avail[u]) return false;
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
	freopen("TaskH.INP", "r", stdin);
	freopen("TaskH.OUT", "w", stdout);
 
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i <= (int)2e6; ++i)
		lab[i] = -1, avail[i] = 1;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (unite(a[i], b[i])) res++;
	}
	cout << res << endl;
 
	return 0;
}