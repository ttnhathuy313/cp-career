#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5;
ii x1[N], x2[N];
bool f[N];
int w, h;

bool onEdge(int i) {
	bool ok = 1;
	if ((x1[i].first != 0 && x1[i].first != w) && (x1[i].second != 0 && x1[i].second != h))
		ok = false;
	return ok;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskJ.INP", "r", stdin);
	freopen("TaskJ.OUT", "w", stdout);

	cin >> w >> h;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x1[i].first >> x1[i].second >> x2[i].first >> x2[i].second;
	}
	for (int i = 1; i <= n; ++i) {
		x1[i + n] = x2[i];
	}
	vector <int> full_sorted;
	full_sorted.clear();
	vector <int> tmp;
	tmp.clear();
	for (int i = 1; i <= n * 2; ++i) if (onEdge(i) && onEdge((i <= n ? i + n : i - n))) {
		if (x1[i].first == 0) {
			tmp.push_back(i);
		}
	}
	sort(tmp.begin(), tmp.end(), [&](int a, int b) {
		return x1[a].second < x1[b].second;
	});
	for (int v : tmp) {
		full_sorted.push_back(v);
	}

	tmp.clear();
	for (int i = 1; i <= n * 2; ++i) if (onEdge(i) && onEdge((i <= n ? i + n : i - n))) {
		if (x1[i].second == h && x1[i].first != 0) {
			tmp.push_back(i);
		}
	}
	sort(tmp.begin(), tmp.end(), [&](int a, int b) {
		return x1[a].first < x1[b].first;
	});
	for (int v : tmp) {
		full_sorted.push_back(v);
	}

	tmp.clear();
	for (int i = 1; i <= n * 2; ++i) if (onEdge(i) && onEdge((i <= n ? i + n : i - n))) {
		if (x1[i].first == w && x1[i].second != h) {
			tmp.push_back(i);
		}
	}
	sort(tmp.begin(), tmp.end(), [&](int a, int b) {
		return x1[a].second > x1[b].second;
	});
	for (int v : tmp) {
		full_sorted.push_back(v);
	}

	tmp.clear();
	for (int i = 1; i <= n * 2; ++i) if (onEdge(i) && onEdge((i <= n ? i + n : i - n))) {
		if (x1[i].second == 0 && x1[i].first != w && x1[i].first != 0) {
			tmp.push_back(i);
		}
	}
	sort(tmp.begin(), tmp.end(), [&](int a, int b) {
		return x1[a].first > x1[b].first;
	});
	for (int v : tmp) {
		full_sorted.push_back(v);
	}

	int curOpen = 0, res = 1;
	stack <int> st;
	for (int v : full_sorted) {
		if (v > n) v -= n;
		// cerr << v << endl;
		if (!f[v]) {
			st.push(v);
			curOpen++;
			f[v] = 1;
		} else {
			f[v] = 1;
			if (st.top() != v) {
				res = 0;
				break;
			}
			curOpen--;
			st.pop();
		}
	}

	if (res == 1) {
		cout << "Y";
	} else cout << "N";

	return 0;
}