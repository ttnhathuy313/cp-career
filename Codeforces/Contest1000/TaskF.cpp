#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
int a[N], n, block_size, cnt[N], ans[N];
bool d[N];

struct Query {
	int l, r, id;
	Query() {}
	Query(int _l, int _r, int _id) : l(_l), r(_r), id(_id) {}
	bool operator<(const Query other) const {
		if (l / block_size != other.l / block_size) {
			return l < other.l;
		} else {
			int a = l / block_size;
			if (a % 2 == 0) {
				return r > other.r;
			} else return r < other.r;
		}
	}
} Q[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.inp", "r", stdin);
	freopen("TaskF.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	block_size = 800;
	int q;
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		int l, r;
		cin >> l >> r;
		Q[i] = Query(l, r, i);
	}
	sort(Q + 1, Q + 1 + q);
	int L = 0, R = 0;
	stack <int> candidate;
	while (!candidate.empty()) candidate.pop();
	for (int i = 1; i <= q; ++i) {
		int l = Q[i].l, r = Q[i].r;
		while (L < l) {
			cnt[a[L]]--;
			if (cnt[a[L]] == 1 && !d[a[L]]) {
				d[a[L]] = 1;
				candidate.push(L);
			}
			L++;
		}
		while (L > l) {
			L--;
			cnt[a[L]]++;
			if (cnt[a[L]] == 1 && !d[a[L]]) {
				d[a[L]] = 1;
				candidate.push(L);
			}
		}
		while (R < r) {
			R++;
			cnt[a[R]]++;
			if (cnt[a[R]] == 1 && !d[a[R]]) {
				d[a[R]] = 1;
				candidate.push(R);
			}
		}
		while (R > r) {
			cnt[a[R]]--;
			if (cnt[a[R]] == 1 && !d[a[R]]) {
				d[a[R]] = 1;
				candidate.push(R);
			}
			R--;
		}
		while (!candidate.empty() && cnt[a[candidate.top()]] != 1) {
			d[a[candidate.top()]] = 0;
			candidate.pop();
		}
		if (!candidate.empty()) ans[Q[i].id] = a[candidate.top()];
	}
	for (int i = 1; i <= q; ++i)
		cout << ans[i] << '\n';

	return 0;
}