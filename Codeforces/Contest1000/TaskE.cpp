#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
 
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define fi   first
#define se   second
#define all(a) a.begin(), a.end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define endl '\n'
 
const int N = 3e5 + 5;
int n, m, biCount, biComp[N], dfsTime, tin[N], low[N], dp[N];
int res;
vector <int> adj[N], Tadj[N];
stack <int> S;
bool mark[N];
 
void dfs(int u, int pre) {
	mark[u] = 1;
	tin[u] = low[u] = ++dfsTime;
	S.push(u);
	for (int v : adj[u]) {
		if (v == pre) continue;
		if (!mark[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		} else low[u] = min(low[u], tin[v]);
	}
	if (tin[u] == low[u]) {
		++biCount;
		while (S.top() != u) {
			int v = S.top();
			biComp[v] = biCount;
			S.pop();
		}
		biComp[u] = biCount;
		S.pop();
	}
}
 
void dfs2(int u, int pre) {
	vector <int> w;
	w.clear();
	for (int v : Tadj[u]) {
		if (v == pre) continue;
		dfs2(v, u);
		w.push_back(dp[v]);
	}
	if (w.size() == 0) return;
	sort(all(w), greater<int> ());
	dp[u] = w[0] + 1;
	res = max(res, dp[u]);
	if (w.size() == 1) return;
	res = max(res, w[0] + 2 + w[1]);
}
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	clock_t tStart = clock();
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.out", "w", stdout);
 
	cin >> n >> m;
	vector <ii> Edges;
	REP(nhi, m) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		Edges.push_back(ii(u, v));
	}
	memset(mark, 0, sizeof mark);
	dfs(1, -1);
	set <ii> E;
	for (ii e : Edges) {
		int x = biComp[e.first], y = biComp[e.second];
		if (x == y) continue;
		if (x > y) swap(x, y);
		if (E.find(ii(x, y)) == E.end()) {
			E.insert(ii(x, y));
			Tadj[x].push_back(y);
			Tadj[y].push_back(x);
		}
	}
	dfs2(1, -1);
	cout << res << endl;
 
	
	fprintf(stderr, "Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}