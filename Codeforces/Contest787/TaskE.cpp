#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LOG = 19;
struct Node {
	int Left, Right, sum;
} st[N * LOG * 4];
int n, a[N], cur, latest[4 * N], nVer, lst[N], root[2 * N], verNum[N], leaf[N], cv;

int Left(int x) {return (x << 1);}
int Right(int x) {return (x << 1) + 1;}

void build(int id, int L, int R) {
	cur++;
	int curID = cur;
	latest[id] = curID;
	if (L == R) {
		leaf[L] = id;
		st[curID] = {-1, -1, 0};
		return;
	}
	st[curID].sum = 0;
	int mid = (L + R) >> 1;
	st[curID].Left = cur + 1;
	build(Left(id), L, mid);
	st[curID].Right = cur + 1;
	build(Right(id), mid + 1, R);
	// cerr << "ver0 [" << L << ", " << R << "] : " << curID << " with left : " << st[curID].Left << ", right : " << st[curID].Right << " has sum " << st[curID].sum << endl;
}

void update(int id, int L, int R, int x) {
	cur++;
	int curID = cur;
	if (L == R) {
		st[curID] = {-1, -1, st[latest[id]].sum ^ 1};
		latest[id] = curID;
		return;
	}
	int mid = (L + R) >> 1;
	latest[id] = curID;
	if (x <= mid) {
		st[curID].Left = curID + 1;
		st[curID].Right = latest[Right(id)];
		update(Left(id), L, mid, x);
	} else {
		st[curID].Right = curID + 1;
		st[curID].Left = latest[Left(id)];
		update(Right(id), mid + 1, R, x);
	}
	st[curID].sum = st[st[curID].Left].sum + st[st[curID].Right].sum;
	// cerr << "ver" << nVer << " [" << L << ", " << R << "] : " << curID << " with left : " << st[curID].Left << ", right : " << st[curID].Right << " has sum " << st[curID].sum << endl;
}

void flip(int i) {
	root[++nVer] = cur + 1;
	update(1, 1, n, i);
}

int get(int id, int L, int R, int x) {
	if (L == R) return st[id].sum;
	int mid = (L + R) >> 1;
	if (x > mid) return get(st[id].Right, mid + 1, R, x);
	else return get(st[id].Left, L, mid, x);
}

int query(int id, int L, int R, int k) {
	if (L == R) return L;
	int mid = (L + R) >> 1;
	// cerr << "#" << id << " [" << L << ", " << R << "] left : " << st[id].Left << " right : " << st[id].Right << " sum : " << st[id].sum << endl;
	if (st[id].sum < k) return R;
	int s = st[st[id].Left].sum;
	if (s <= k && !(s == k && get(root[cv], 1, n, mid + 1) == 1)) return query(st[id].Right, mid + 1, R, k - st[st[id].Left].sum);
	else return query(st[id].Left, L, mid, k);
}

int find_kth(int k, int ver) {
	cv = ver;
	return query(root[ver], 1, n, k);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	build(1, 1, n);
	for (int i = n; i >= 1; --i) {
		if (lst[a[i]]) flip(lst[a[i]]);
		flip(i);
		lst[a[i]] = i;
		verNum[i] = nVer;
	}
	for (int k = 1; k <= n; ++k) {
		int l = 1;
		int block = 0;
		while (l <= n) {
			block++;
			l = find_kth(k, verNum[l]) + 1;
		}
		cout << block << ' ';
	}

	return 0;
}