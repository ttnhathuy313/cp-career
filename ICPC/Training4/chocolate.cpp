#include <bits/stdc++.h>

using namespace std;
#define int long long
#define rep(i, a) for (int i = 0; i < a; ++i)
typedef pair <int, int> ii;

int x[15][15][2], sz_x[115], sz_y[15], val[15][6][6][2], cnt, clue;
map <char, int> mp1, mp2;
ii fappear[15]; int side[15];
char v1[] = {'_','S','R','T'}, v2[] = {'_','V','S','C'};
string ss[] = {"SV", "SS", "SC", "RV", "RS", "RC", "TV", "TS", "TC"};
vector <int> id;
vector <ii> vitri[5][2];



bool test() {
	bool okay = true;
	bool printt = (id == vector <int> {6, 0, 8, 1, 4, 5, 2, 3, 7});
	for (int i = 1; i <= clue; ++i) {
		bool ok = false;
		int d = val[i][fappear[i].first][fappear[i].second][side[i]];
		for (ii V : vitri[d][side[i]]) {
			int u = V.first, v = V.second;
			if (u < fappear[i].first || v < fappear[i].second) continue;
			bool breakhong = false;
			for (int uu = 1; uu <= sz_x[i]; ++uu) {
				if (breakhong) break;
				for (int vv = 1; vv <= sz_y[i]; ++vv) {
					int curu = uu + u - fappear[i].first, curv = vv + v - fappear[i].second;
					if (curu > 3 || curv > 3) {
						breakhong = true;
						break;
					}
					if (val[i][uu][vv][0] != 0 && val[i][uu][vv][0] != x[curu][curv][0]) {
						breakhong = true;
						break;
					}
					if (val[i][uu][vv][1] != 0 && val[i][uu][vv][1] != x[curu][curv][1]) {
						breakhong = true;
						break;
					}
				}
			}
			if (breakhong == true) continue;
			ok = true;
			break;
		}
		if (!ok) {
			return false;
		}
	}
	return true;
}

void solve() {
	cin >> clue;
	for (int i = 1; i <= clue; ++i) {
		cin >> sz_x[i] >> sz_y[i];
		for (int u = 1; u <= sz_x[i]; ++u) {
			for (int v = 1; v <= sz_y[i]; ++v) {
				string s;
				cin >> s;
				val[i][u][v][0] = mp1[s[0]];
				val[i][u][v][1] = mp2[s[1]];
				if (val[i][u][v][0]) {
					fappear[i] = {u, v};
				}
				if (val[i][u][v][0]) {
					side[i] = 0;
				}
				if (val[i][u][v][1]) {
					fappear[i] = {u, v};
				}
				if (val[i][u][v][1]) {
					side[i] = 1;
				}
				// cerr << val[i][u][v][0] << val[i][u][v][1] << ' ';
			}
			// cerr << endl;
		}
		// cerr << endl;
	}
	id.clear();
	for (int i = 0; i < 9; ++i) id.push_back(i);

	do {
		for (int i = 0; i < 6; ++i) for (int j = 0; j < 2; ++j) vitri[i][j].clear();
		int vvv = 0;
		for (int i = 1; i <= 3; ++i) {
			for (int j = 1; j <= 3; ++j) {
				x[i][j][0] = mp1[ss[id[vvv]][0]];
				x[i][j][1] = mp2[ss[id[vvv++]][1]];
				vitri[x[i][j][0]][0].push_back({i, j});
				vitri[x[i][j][1]][1].push_back({i, j});
			}

		}
		if (test()) {
			cout << "Puzzle #" << (++cnt) << ":" << endl;
			for (int i = 1; i <= 3; ++i) {
				for (int j = 1; j <= 3; ++j) {
					cout << v1[x[i][j][0]] << v2[x[i][j][1]] << ' ';
				}
				cout << endl;
			}
			return;
		}
	} while (next_permutation(id.begin(), id.end()));
	
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("chocolate.INP", "r", stdin);
	freopen("chocolate.OUT", "w", stdout);


	int tc;
	cin >> tc;
	mp1['S'] = 1; mp1['R'] = 2; mp1['T'] = 3;
	mp2['V'] = 1; mp2['S'] = 2; mp2['C'] = 3;
	while (tc--) {
		solve();
		if (tc) cout << endl;
	}

	return 0;
}