const int oo = 1e18 + 7;
 
struct Line {
	int a, b;
	Line() {}
	Line(int _a, int _b) : a(_a), b(_b) {}
	int val(int x) {
		return a * x + b;
	}
	bool operator == (Line other) {
		return (other.a == a && other.b == b);
	}
};
 
typedef pair <int, Line> iL;
 
struct PersistentLiChaoTree {
	vector <Line> st;
	int n, cnt; 
	stack <iL> changes;
	stack <int> popcount;
	PersistentLiChaoTree() {}
	PersistentLiChaoTree(int _n) {
		this->n = _n;
		st.resize(4 * n + 5);
		REP(i, st.size()) st[i] = Line(oo, oo);
	}
 
	int Left(int x) {return (x << 1);}
	int Right(int x) {return (x << 1) + 1;}
 
	void Assign(int id, Line b) {
		cnt++;
		changes.push(iL(id, st[id]));
		st[id] = b;
	}
 
	void update(int id, int L, int R, Line a) {
		if (L == R) {
			if (st[id] == Line(oo, oo)) Assign(id, a);
			else if (a.val(L) < st[id].val(L)) Assign(id, a);
			return;
		}
		if (st[id] == Line(oo, oo)) {
			Assign(id, a);
			return;
		}
		int mid = (L + R) >> 1;
		bool l = st[id].val(L) < a.val(L), r = st[id].val(R) < a.val(R);
		bool m1 = st[id].val(mid) < a.val(mid), m2 = st[id].val(mid + 1) < a.val(mid + 1);
		if (l && r) return;
		if (!l && !r) {Assign(id, a); return;}
		if (l && m1) {update(Right(id), mid + 1, R, a); return;}
		if (!l && !m1) {update(Right(id), mid + 1, R, st[id]); Assign(id, a); return;}
		if (m2 && r) {update(Left(id), L, mid, a);return;}
		if (!m2 && !r) {update(Left(id), L, mid, st[id]); Assign(id, a); return;}
	}
	void addLine(Line a) {
		cnt = 0;
		update(1, 1, n, a);
		popcount.push(cnt);
	}
 
	int query(int id, int L, int R, int x) {
		int ret;
		if (st[id] == Line(oo, oo)) ret = oo;
		else ret = st[id].val(x);
		if (L == R) return ret;
		int mid = (L + R) >> 1;
		if (x > mid) ret = min(ret, query(Right(id), mid + 1, R, x));
		else ret = min(ret, query(Left(id), L, mid, x));
		return ret;
	}
	int query(int x) {return query(1, 1, n, x);}
 
	void pop() { // O(logN) per operations due to the height of the IT
		if (popcount.empty()) return;
		int tmp = popcount.top(); popcount.pop();
		while (tmp && !changes.empty()) {
			iL c = changes.top(); changes.pop();
			st[c.first] = c.second;
			tmp--;
		}
	}
} IT;