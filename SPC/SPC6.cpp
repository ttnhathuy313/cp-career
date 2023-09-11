#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 45;
int mark[N][N][N][N], n, m, rock[N][N];
int dx[] = {1, -1, 0, 0},
	dy[] = {0, 0, 1, -1};

bool check(array <int, 4> cur, int dir1, int dir2) {
	array <int, 4> nxt = {cur[0] + dx[dir1], cur[1] + dy[dir1], cur[2] + dx[dir2], cur[3] + dy[dir2]};
	if (ii(nxt[0], nxt[1]) == ii(nxt[2], nxt[3])) return false;
	if (rock[nxt[0]][nxt[1]] || rock[nxt[2]][nxt[3]]) return false;
	if (nxt[0] == 0 || nxt[0] > n || nxt[1] == 0 || nxt[1] > m) return false;
	if (nxt[2] == 0 || nxt[2] > n || nxt[3] == 0 || nxt[3] > m) return false;
	if (ii(cur[0], cur[1]) == ii(nxt[2], nxt[3]) && ii(cur[2], cur[3]) == ii(nxt[0], nxt[1])) return false;
	return true;
}

void solve() {
	cin >> n >> m;
	int sx1, sx2, sy1, sy2, ex1, ex2, ey1, ey2;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == '#') rock[i][j + 1] = 1;
			if (s[j] == 'a') {
				ex1 = i, ey1 = j + 1;
			}
			if (s[j] == 'b') {
				ex2 = i, ey2 = j + 1;
			}
			if (s[j] == 'A') {
				sx1 = i, sy1 = j + 1;
			}
			if (s[j] == 'B') {
				sx2 = i, sy2 = j + 1;
			}
		}
	}
	memset(mark, 0, sizeof mark);
	mark[sx1][sy1][sx2][sy2] = 1;
	queue <array<int, 4>> q;
	while (!q.empty()) q.pop();
	q.push({sx1, sy1, sx2, sy2});
	while (!q.empty()) {
		array <int, 4> cur = q.front();
		// if (cur == array<int,4>({ex1, ey1, ex2, ey2})) cerr << "lmao" << endl;
		// cerr << cur[0] << ' ' << cur[1] << ' ' << cur[2] << ' ' << cur[3] << " : " << mark[cur[0]][cur[1]][cur[2]][cur[3]] << endl;
		q.pop();
		for (int dir1 = 0; dir1 < 4; ++dir1) {
			for (int dir2 = 0; dir2 < 4; ++dir2) {
				if (!check(cur, dir1, dir2)) continue;
				array <int, 4> nxt = {cur[0] + dx[dir1], cur[1] + dy[dir1], cur[2] + dx[dir2], cur[3] + dy[dir2]};
				if (mark[nxt[0]][nxt[1]][nxt[2]][nxt[3]]) continue;
		// if (nxt == array<int,4>({ex1, ey1, ex2, ey2})) cerr << "lmao" << endl;

				mark[nxt[0]][nxt[1]][nxt[2]][nxt[3]] = mark[cur[0]][cur[1]][cur[2]][cur[3]] + 1;
				q.push(nxt);
			}
		}
	}
	if (mark[ex1][ey1][ex2][ey2] == 0) {
		cout << "NO SOLUTION" << endl;
	} else cout << mark[ex1][ey1][ex2][ey2] - 1 << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("SPC6.INP", "r", stdin);
	freopen("SPC6.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}