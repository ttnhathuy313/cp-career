#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int p[N], n, s, t, tin[N], dfsTime, sz;

void dfs(int u) {
	sz++;
	tin[u] = ++dfsTime;
	if (!tin[p[u]]) dfs(p[u]);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	cin >> n >> s >> t;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	dfs(s);
	if (!tin[t]) {
		cout << -1;
		return 0;
	}
	cout << abs(tin[s] - tin[t]);

	return 0;
}