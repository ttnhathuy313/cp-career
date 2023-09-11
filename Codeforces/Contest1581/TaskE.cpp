#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n, m, x[N], y[N], block_size, lst[N], res[N], beg[N], ed[N], type[N], train[N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	char d = 'a' + 3;
	cerr << d << endl;
	vector <string> hooman;
	hooman = {"huy", "huy"};

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
	}
	int block_size = 600;
	memset(lst, -1, sizeof lst);
	for (int j = 1; j <= m; ++j) {
		int op, u;
		cin >> op >> u;
		type[j] = op; train[j] = u;
		if (op == 1) {
			lst[u] = j;
		} else {
			if (x[u] + y[u] > block_size) {
				for (int i = lst[u]; i < j; i += x[u] + y[u]) {
					if (i + x[u] < j) {
						res[i + x[u]]++;
						res[min(j, i + x[u] + y[u])]--;
					}
				}
			}
			lst[u] = -1;
		}
	}
	for (int u = 1; u <= n; ++u) if (lst[u] != -1) {
		int j = m + 1;
		if (x[u] + y[u] > block_size) {
			for (int i = lst[u]; i < j; i += x[u] + y[u]) {
				if (i + x[u] < j) {
					res[i + x[u]]++;
					res[min(j, i + x[u] + y[u])]--;
				}
			}
		}
		lst[u] = -1;
	}

	for (int cur = 2; cur <= block_size; ++cur) {
		vector <int> roll(cur, 0);
		for (int i = 1; i <= m; ++i) {
			int cur_id = i % cur;
			if (type[i] == 2 && x[train[i]] + y[train[i]] == cur) {
				int u = train[i];
				roll[beg[u]]--;
				roll[ed[u]]++;
				if (beg[train[i]] < ed[train[i]]) {
					if (cur_id > beg[u] && cur_id <= ed[u]) res[i]--;
				} else {
					if (cur_id > beg[u] || cur_id <= ed[u]) res[i]--;
				}
			}
			res[i] += roll[cur_id];

			if (type[i] == 1 && x[train[i]] + y[train[i]] == cur) {
				int u = train[i];
				beg[u] = (i + x[u]) % (x[u] + y[u]);
				ed[u] = (i + x[u] + y[u]) % (x[u] + y[u]);
				// cerr << i << "  :  " << beg[u] << ' ' << ed[u] << "   with current as " << cur_id << endl;
				roll[beg[u]]++;
				roll[ed[u]]--;
			}
		}
	}
	for (int i = 1; i <= m; ++i) {
		res[i] += res[i - 1];
		cout << res[i] << '\n';
	}

	return 0;
}