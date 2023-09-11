/*	
	Problem Description: You are given a tree with n nodes. You have to answer q queries. In each query, you are given an
	interval [l, r]. You have to delete a node in the range of [l, r] such that afterward, the lowest common ancestor (LCA)
	of all node in the range [l, r] (except the deleted one) is as lowest as possible (have largest depth).

	My approach: First, I created a vector. while traversing the tree with dfs, if I enter a node, I push it to the vector,
	if I exit a node, I also push it to the vector. So, each node will be added twice. Tin[u] will be the first position of
	u in the vector and tout[u] will be the second position of u in the vector. A LCA of an interval of node [l, r] will be a node
	such that its interval [first_appearance, second_appearance] will cover all appearances of the node lies in [l, r]. Therefore,
	it makes sense that we should only delete the node that is leftmost and rightmost in the vector. Only by that way, we can change
	the LCA. The rest is easy, there's only two option of node to delete. I delete each one and check what is more optimized.


	Time Complexity: O((N + Q)logN)
*/


#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 1e5 + 5, LOG = 22;
int n, q, tin[N], tout[N], P[N][LOG], h[N], dfsTime;
/*
	- tin and tout is the time we enter a node and the time we exit a node respectively
	- P[N][LOG] is the arrays used for binary lifting. From u, if we go up 2 ^ i steps, we will reach P[u][i]. By using this,
	we can go up from a vertex any arbitrary length in O(log(length)).
	- dfsTime is just a counter.
	- h is supposed to be height, but accidentally it really means depth of a node ^^
*/

vector <int> adj[N];

struct SegmentTree { // I create a struct of SegmentTree because I don't want to implement it twice for two seperate SegmentTree
	int n; // The SegmentTree of the array with size n
	vector <ii> st;
	SegmentTree() {}
	SegmentTree(int _n) {
		this -> n = _n;
		st.assign(4 * n + 5, {0, 0});
	}
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}

	void update(int id, int L, int R, int i, int val) { // This will update a position to any value
		if (L > i || R < i) return; // base case
		if (L == R) {
			st[id] = {val, i};
			return;
		}
		int mid = (L + R) >> 1;
		update(Left(id), L, mid, i, val); // keep going down the segment tree
		update(Right(id), mid + 1, R, i, val);
		st[id] = max(st[Left(id)], st[Right(id)]);
	}
	ii query(int id, int L, int R, int i, int j) { // this pair returns the maximum value in the array and the position of the maximum
		if (L > j || R < i) return {-5 * N, 0};
		if (L >= i && R <= j) return st[id];
		int mid = (L + R) >> 1;
		return max(query(Left(id), L, mid, i, j), query(Right(id), mid + 1, R, i, j));
	}
	void update(int val, int i) {
		update(1, 1, n, i, val);
	}
	ii query(int i, int j) {
		return query(1, 1, n, i, j);
	}
} IT1, IT2;

void dfs(int u, int pre) {
	if (~pre) h[u] = h[pre] + 1; // Calculate depth of the node
	P[u][0] = pre; 
	tin[u] = ++dfsTime; // The time I enter a node
	for (int i = 1; i < LOG; ++i) if ((1 << i) <= h[u]) // Calculate the sparse table in order to find the LCA.
		P[u][i] = P[P[u][i - 1]][i - 1];
	for (int v : adj[u])
		dfs(v, u);
	tout[u] = ++dfsTime; // The time that I exit a node
}

int lca(int u, int v)  { // Findint the lowest common ancestor using binary lifting
	if (u == -1) return v;
	if (v == -1) return u;
	if (h[u] < h[v]) swap(u, v);
	for (int i = LOG - 1; i >= 0; --i) if ((1 << i) <= h[u] - h[v]) {
		u = P[u][i];
	}
	if (u == v) return u;
	for (int i = LOG - 1; i >= 0; --i) if ((1 << i) <= h[u] && P[u][i] != P[v][i]) // Binary Lifting
		u = P[u][i], v = P[v][i];
	return P[u][0];
}

int fullsolve(int l, int r, int x) { // Calculating the LCA of entire interval [l, r]. X is just a random element in the interval
	if (l > r) return -1;
	int mi = -IT1.query(l, r).first, mx = IT2.query(l, r).first;
	int nb = (int)log2(h[x]), cur = 0, curV = x;
	if (tin[x] <= mi && tout[x] >= mx) return x; // If x is already the LCA for the interval [l, r]
	for (int i = nb; i >= 0; --i) if ((1 << i) <= h[curV]) { // I go up from the node X to find the lowest common ancestor of the interval
		int tmp = P[curV][i];
		if (tin[tmp] <= mi && tout[tmp] >= mx) continue;
		curV = tmp;
		cur += (1 << i);
	}
	return P[curV][0];
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n >> q;
	for (int i = 2; i <= n; ++i) {
		int p; cin >> p;
		adj[p].push_back(i);
	}
	dfs(1, -1);
	IT1 = SegmentTree(n), IT2 = SegmentTree(n);
	for (int i = 1; i <= n; ++i) {
		IT1.update(-tin[i], i); // I change it to negative because I want to find the minimum
		IT2.update(tout[i], i);
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		int id1 = IT1.query(l, r).second;
		int a1 = lca(fullsolve(l, id1 - 1, l), fullsolve(id1 + 1, r, id1 + 1)); // What if I delete the leftmost node in the vector
		int id2 = IT2.query(l, r).second;
		int a2 = lca(fullsolve(id2 + 1, r, id2 + 1), fullsolve(l, id2 - 1, l)); // What if I delete the rightmost node in the vector
		if (h[a1] > h[a2]) { // compare both
			cout << id1 << ' ' << h[a1] << endl;
		} else cout << id2 << ' ' << h[a2] << endl;
	}

	return 0;
}