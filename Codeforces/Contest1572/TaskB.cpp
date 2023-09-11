#include <bits/stdc++.h>

using namespace std;
#define int long long 

const int N = 2e5 + 5;
int n, a[N], cons[N], nxt[N];
vector <int> res;

void init() {
	for (int i = 1; i <= n + 1; ++i) {
		cons[i] = 0;
		nxt[i] = 0;
	}
	res.clear();
}

void add_res(int i) {
	res.push_back(i);
	// cerr << "	Operate at " << i << endl;
}

void clear_the_way_left(int i, int j) {
	while (i <= n && a[i] == 0) i++;
	for (int k = j; k >= i; --k) {
		if (a[k] == 1 && (nxt[k] - k) % 2 == 0) {
			add_res(k);
		}
	}
}

void clear_the_way_right(int i, int j) {
	while (j > 0 && a[j] == 0) j--;
	if (i == 1 && a[1] == 1) {
		clear_the_way_left(i, j);
		return;
	}
	for (int k = i; k <= j; ++k) {
		if (a[k] == 1 && (nxt[k] - k) % 2 == 0) {
			add_res(k - 1);
		}
	}
}

void connect_left(int l, int r) {
	for (int i = r; i < nxt[r]; ++i) if ((i - r) & 1) {
		add_res(i);
	}
	int turn = 0;
	for (int i = r; i >= l; --i) {
		if (a[i] == 0) {
			if (turn == 1) {
				add_res(i);
				add_res(i + 1);
			}
			turn ^= 1;
			continue;
		}
		if (i != r && ((nxt[i] - i) & 1)) add_res(i);
		else turn = 0;
	}
}

void connect_right(int l, int r) {
	for (int i = l; i < nxt[l] - 1; ++i) {
		if ((l - i) % 2 == 0) add_res(i - 1);
	}
	int turn = 0, lst = -1;
	for (int i = nxt[l]; i <= r; ++i) {
		if (a[i] == 0) {
			if (turn == 1) {
				add_res(i - 2);
				add_res(i - 3);
			}
			turn ^= 1;
			continue;
		}
		if (a[i - 1] == 0) {
			lst = i;
		}
		if ((i - lst) % 2 == 0) add_res(i - 2);
		else turn = 0;
	}
}

void solve() {
	cin >> n;
	init();
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	nxt[n + 1] = n + 1;
	for (int i = n; i >= 1; --i) {
		if (a[i] == 0) nxt[i] = i;
		else nxt[i] = nxt[i + 1];
		if (a[i] == 0) continue;
		else cons[i] = cons[i + 1] + 1;
	}
	if (a[n - 1] == 0 && a[n] == 1 && nxt[1] == n - 1 && (n & 1)) {
		cout << "YES" << endl;
		cout << (n - 1) / 2 << endl;
		cout << n - 2 << ' ';
		for (int i = n - 2; i >= 1; --i) if (i != 1 && (i & 1)) {
			cout << i - 2 << ' ';
		}
		cout << endl;
		return;
	}
	if (a[2] == 0 && a[1] == 1 && nxt[3] == n + 1 && (n & 1)) {
		cout << "YES" << endl;
		cout << (n - 1) / 2 << endl;
		cout << 1 << ' ';
		for (int i = 3; i <= n; ++i) if (i != n && (i & 1)) {
			cout << i - 1 << ' ';
		}
		cout << endl;
		return;
	}
	int r = 1, l = 1, turn = 0;
	while (r <= n) {
		if (a[r] == 0) {
			r++;
			continue;
		}
		if (cons[r] % 2 == 0) {
			r = nxt[r];
			continue;
		}
		if (turn == 0) {
			turn ^= 1;
			if (l == 1) clear_the_way_left(1, r - 1);
			else clear_the_way_right(l, r - 1);
			// cerr << "GAP: " << l << " " << r - 1 << endl;
			l = r;
			r = nxt[r];
		} else {
			if (l == 1 && nxt[r] == n + 1) {
				cout << "NO" << endl;
				return;
			}
			turn ^= 1;
			// connect two points, depends on to go left or go right
			if (nxt[r] == n + 1) connect_right(l, n);
			else connect_left(l, r);
			// cerr << "Connect: " << l << ' ' << r << endl;
			r = nxt[r];
			l = r;
		}
	}
	if (turn == 1) {
		cout << "NO" << endl;
		return;
	}
	//clear the way at final
	if (l <= n) {
		if (l == 1) {
			bool ok = false;
			for (int i = 1; i <= n; ++i) if (a[i] == 0) {
				clear_the_way_right(i + 1, n);
				clear_the_way_left(1, i - 1);
				ok = true;
				break;
			}
			if (!ok) {
				cout << "NO" << endl;
				return;
			}

		} else clear_the_way_right(l, n);
	}
	cout << "YES" << endl;
	cout << res.size() << endl;
	for (int i : res) cout << i << ' ';
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}