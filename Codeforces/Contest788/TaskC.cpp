#include <bits/stdc++.h>

using namespace std;

const int N = 1005, offset = 1001;
vector <int> adj[2 * N];
int cnt[N], n, d[N * 2], p[2 * N];
bool mark[N * 2];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.inp", "r", stdin);
	freopen("TaskC.out", "w", stdout);

	int k;
	cin >> n >> k;
	for (int i = 1; i <= k; ++i) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	for (int i = -1000; i <= 1000; ++i) {
		for (int j = 0; j <= 1000; j++) if (cnt[j] && -1000 <= i + j - n && i + j - n <= 1000) {
			adj[i + offset].push_back(i + offset + j - n);
		}
	}
	queue <int> q;
	while (!q.empty()) q.pop();
	q.push(offset);
	mark[offset] = 1;
	int res = N * N;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) {
			if (!mark[v]) {
				q.push(v);
				d[v] = d[u] + 1;
				p[v] = u;
				mark[v] = 1;
			} else if (v == offset) {
				res = min(res, d[u] + 1 - d[v]);
			}
		}
	}
	if (res == N * N) res = -1;	
	cout << res << endl;

	return 0;
}