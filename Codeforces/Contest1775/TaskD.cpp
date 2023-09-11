#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, offset = 3e5;
int n, a[N], mark[N * 2], f[N], pre[N * 2];
vector <int> adj[N * 2];

void sieve() {
	for (int i = 2; i < N; ++i) if (f[i] == 0) {
		f[i] = i;
		for (long long j = 1LL * i * i; j < N; j += i) f[j] = i;
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	sieve();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int s, t;
	cin >> s >> t;
	for (int i = 1; i <= n; ++i) {
		int x = a[i];
		while (x > 1) {
			int nxt = f[x];
			while (x % nxt == 0)
				x /= nxt;
			adj[i].push_back(n + nxt);
			adj[n + nxt].push_back(i);
		}
	}
	memset(mark, -1, sizeof mark);
	memset(pre, -1, sizeof pre);
	mark[s] = 0;
	queue <int> q;
	while (!q.empty()) {
		q.pop();
	}
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) {
			if (mark[v] == -1) {
				mark[v] = mark[u] + 1;
				pre[v] = u;
				q.push(v);
			}
		}
	}
	if (mark[t] == -1) {
		cout << -1 << endl;
		return 0;
	}

	cout << mark[t] / 2 + 1 << endl;
	int cur = t;
	vector <int> ans;
	ans.clear();
	while (~cur) {
		if (cur <= n) ans.push_back(cur);
		cur = pre[cur];
	}
	reverse(ans.begin(), ans.end());
	for (int v : ans) {
		cout << v << ' ';
	}
	cout << endl;

	return 0;
}