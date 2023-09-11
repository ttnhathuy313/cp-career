#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5e4 + 5, AA = 1e6 + 5;
int n, a[N], p[AA], block_size, m, ans[N], curMemId;
 
struct Query {
	int l, r, id, blockid;
};
bool operator < (const Query a, const Query b) {
	if (a.blockid != b.blockid) {
		return a.l < b.l;
	} else return a.r < b.r;
} 
vector <Query> A, cur;
struct TrieNode {
	int mi, mx;
	int child[2];
	TrieNode() {
		mi = AA; mx = 0;
		for (int i = 0; i < 2; ++i)
			child[i] = 0;
	}
} mem[(int)2e7];
int root1, root2;

int new_plot() {
	++curMemId;
	mem[curMemId] = TrieNode();
	return curMemId;
}
 
void add_num(int root, int num, int id) {
	int p = root;
	vector <int> path; path.clear();
	for (int i = 20; i >= 0; --i) {
		int cur = (num & (1 << i)) > 0;
		path.push_back(p);
		if (mem[p].child[cur] == 0)
			mem[p].child[cur] = new_plot();
		p = mem[p].child[cur];
	}
	mem[p].mi = min(mem[p].mi, id);
	mem[p].mx = max(mem[p].mx, id);
	reverse(path.begin(), path.end());
	for (int D : path) {
		for (int i = 0; i < 2; ++i) if (mem[D].child[i] != 0) {
			mem[D].mi = min(mem[D].mi, mem[mem[D].child[i]].mi);
			mem[D].mx = max(mem[D].mx, mem[mem[D].child[i]].mx);
		}
	}
}
 
int get1(int root2, int num, int id) { // Take current value as the smaller one
	int p = root2;
	int res = 0;
	for (int i = 20; i >= 0; --i) {
		int cur = (num & (1 << i)) > 0;
		int opo = cur ^ 1;
		if (mem[p].child[opo] == 0 || mem[mem[p].child[opo]].mx < id)
			opo ^= 1, res -= (1 << i);
		res += (1 << i);
		p = mem[p].child[opo];
		if (p == 0) return -1;
	}
	return res;
}
 
int get2(int root1, int num, int id) { // Take current value as the bigger one
	int p = root1;
	int res = 0;
	for (int i = 20; i >= 0; --i) {
		int cur = (num & (1 << i)) > 0;
		int opo = cur ^ 1;
		if (mem[p].child[opo] == 0 || mem[mem[p].child[opo]].mi > id)
			opo ^= 1, res -= (1 << i);
		res += (1 << i);
		p = mem[p].child[opo];
		if (p == 0) return -1;
	}
	return res;
}
 
void solve_small(Query q) {
	int r1, r2;
	r1 = new_plot(); r2 = new_plot();
	int ret = 0;
	for (int i = q.l; i <= q.r; ++i) {
		add_num(r1, p[a[i] - 1], a[i]);
		add_num(r2, p[a[i]], a[i]);
		ret = max(ret, get1(r2, p[a[i] - 1], a[i]));
		ret = max(ret, get2(r1, p[a[i]], a[i]));
	}
	ans[q.id] = ret;
}
 
void solve(vector <Query> &cur, int block_index) {
	curMemId = 0;
	root1 = new_plot(); root2 = new_plot();
	int cur_max = 0, r_id = block_size * (block_index + 1) - 1, lbound = r_id;
	// for (Query q : cur) {
	// 	cerr << q.l << ' ' << q.r << endl;
	// }
	// cerr << "~~~~~~~~~~~~~~~~" << endl;
	for (Query q : cur) {
		if (q.r < block_size * (block_index + 1)) {
			solve_small(q);
			continue;
		}
		while (q.r > r_id) {
			r_id++;
			add_num(root1, p[a[r_id] - 1], a[r_id]);
			add_num(root2, p[a[r_id]], a[r_id]);
			cur_max = max(cur_max, get1(root2, p[a[r_id] - 1], a[r_id]));
			cur_max = max(cur_max, get2(root1, p[a[r_id]], a[r_id]));
		}
		int tmp = 0;
		int rr1 = new_plot();
		int rr2 = new_plot();
		for (int i = lbound; i >= q.l; --i) {
			add_num(rr1, p[a[i] - 1], a[i]);
			add_num(rr2, p[a[i]], a[i]);
			tmp = max(tmp, get1(rr2, p[a[i] - 1], a[i]));
			tmp = max(tmp, get2(rr1, p[a[i]], a[i]));
			tmp = max(tmp, get1(root2, p[a[i] - 1], a[i]));
			tmp = max(tmp, get2(root1, p[a[i]], a[i]));
		}
		ans[q.id] = max(tmp, cur_max);
	}
}
 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.inp", "r", stdin);
	freopen("TaskF.out", "w", stdout);
 
	cin >> n >> m;
	block_size = sqrt(n);
	for (int i = 1; i <= AA - 5; ++i)
		p[i] = p[i - 1] ^ i;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i) {
		int l, r;
		cin >> l >> r;
		A.push_back({l, r, i, l / block_size});
	}
	sort(A.begin(), A.end());
	A.push_back({0, 0});
	int pre_block = -1;
	for (int i = 0; i < A.size(); ++i) {
		Query q = A[i];
		if (q.blockid != pre_block || i == A.size() - 1) {
			if (~pre_block) solve(cur, pre_block);
			cur.clear();
		}
		pre_block = q.blockid;
		cur.push_back(q);
	}
	for (int i = 1; i <= m; ++i)
		cout << ans[i] << endl;
 
	return 0;
}