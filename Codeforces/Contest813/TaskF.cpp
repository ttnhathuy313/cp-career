#include <bits/stdc++.h>

using namespace std;
#define int long long

struct dsu_t { // add an edge to a new graph, the bipartiteness is stored in isBipartite
	int connected;
	int sz[N];
	pair<int, int> par[N]; //stores <parent, parity of distance from parent>
	vector<int> changes;
 
	void init(int n) 
	{
		for(int i=1;i<=n;i++)
		{
			par[i]={i, 0};
			sz[i]=1;
		}
		connected=n;
	}
 
	pair<int, int> getPar(int x)
	{
		if(par[x].first==x)
			return par[x];
		pair<int, int> p = getPar(par[x].first);
		p.second ^= par[x].second;
		return p;
	}
 
	bool merge(int u, int v) //Returns 1 if the graph is no longer bipartite
	{
		pair<int, int> x=getPar(u), y=getPar(v);
		if(x.first==y.first)
		{
			if(x.second==y.second)
				return 1;
			changes.push_back(-1);
			return 0;
		}
 
		connected--;
 
		if(sz[x.first] < sz[y.first])
			swap(x, y);
		par[y.first]={x.first, 1^x.second^y.second};
		sz[x.first]+=sz[y.first];
		changes.push_back(y.first);
		return 0;
	}
 
	void undo() //Reversed the previous performed operation
	{
		if(!changes.size())
			return;
		if(changes.back()!=-1)
		{
			int x=changes.back();
			sz[par[x].first]-=sz[x];
			par[x]={x, 0};
		}
		changes.pop_back();
	}
} dsu;

typedef pair <int, int> ii;

const int N = 1e5 + 5;
int n, q, res[N];
vector <ii> st[4 * N];

int Left(int x) {
	return (x << 1);
}

int Right(int x) {
	return (x << 1) + 1;
}

void add(int id, int L, int R, int i, int j, ii e) {
	if (i > R || j < L) return;
	if (L >= i && R <= j) {
		st[id].push_back(e);
		return;
	}
	int mid = (L + R) >> 1;
	add(Left(id), L, mid, i, j, e);
	add(Right(id), mid + 1, R, i, j, e);
}

void dnc(int id, int L, int R, bool fuckup) {
	int cnt = 0;
	for (ii e : st[id]) {
		if (dsu.merge(e.first, e.second)) {
			fuckup = 1;
			break;
		}
		cnt++;
	}
	if (L == R) {
		res[L] = !fuckup;
		return;
	}
	int mid = (L + R) >> 1;
	dnc(Left(id), L, mid, fuckup);
	dnc(Right(id), mid + 1, R, fuckup);
	while (cnt--)
		dsu.undo();
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	map <ii, int> lst;
	lst.clear();
	cin >> n >> q;
	dsu.init(n);

	for (int i = 1; i <= q; ++i) {
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		map <ii, int>::iterator it = lst.find(ii(u, v));
		if (it == lst.end()) {
			lst[{u, v}] = i;
		} else {
			add(1, 1, q, (*it).second, i - 1, ii(u, v));
			lst.erase(it);
		}
	}
	for (auto d : lst) {
		add(1, 1, q, d.second, q, d.first);
	}

	dnc(1, 1, q, 0);

	for (int i = 1; i <= q; ++i) {
		if (res[i]) {
			cout << "YES" << endl;
		} else cout << "NO" << endl;
	}

	return 0;
}