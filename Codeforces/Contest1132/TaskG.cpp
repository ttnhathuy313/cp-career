#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1000100, inf = 1e9;
int t[N << 2], lz[N << 2], a[N];
vector<int> g[N];
int tin[N], tout[N], tt;
 
void dfs(int u) {
	tin[u] = ++tt;
	for (int v : g[u]) {
		dfs(v);
	}
	tout[u] = tt;
}
 
void push(int v,int l,int r) {
	if (lz[v]) {
		t[v] += lz[v];
		if (l < r) {
			lz[v << 1] += lz[v];
			lz[v << 1 | 1] += lz[v];
		}
		lz[v] = 0;
	}
}
 
void add(int v,int l,int r,int L,int R,int val) {
	push(v, l, r);
	if (L > r || R < l) {
		return;
	}
	if (L <= l && r <= R) {
		lz[v] = val;
		push(v, l, r);
		return;
	}
	int md = (l + r) >> 1;
	add(v << 1, l, md, L, R, val);
	add(v << 1 | 1, md + 1, r, L, R, val);
	t[v] = max(t[v << 1], t[v << 1 | 1]);
}
 
void del(int v,int l,int r,int p) {
	push(v, l, r);
	if (l > p || r < p) {
		return;
	}
	if (l == r) {
		t[v] = -inf;
		return;
	}
	int md = (l + r) >> 1;
	del(v << 1, l, md, p);
	del(v << 1 | 1, md + 1, r, p);
	t[v] = max(t[v << 1], t[v << 1 | 1]);
}
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskG.inp", "r", stdin);
	freopen("TaskG.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	stack<int> st;
	for (int i = n; i > 0; --i) {
		while (st.size() && a[i] >= a[st.top()]) {
			st.pop();
		}
		int v = (st.size() ? st.top() : n + 1);
		g[v].push_back(i);
		st.push(i);
	}
	dfs(n + 1);
	for (int i = 1; i <= n; ++i) {
		add(1, 1, n + 1, tin[i], tout[i], 1);
		if (i > k) {
			del(1, 1, n + 1, tin[i - k]);
		}
		if (i >= k) cout << t[1] << ' ';
	}
}