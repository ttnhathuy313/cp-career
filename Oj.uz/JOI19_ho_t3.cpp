#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 405, oo = 1e18;
int n, memo[N][N][N];
string s;

struct state {
	int lastR, lastG, lastY;
};

void upd(int &a, int b) {
	a = min(a, b);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("JOI19_ho_t3.INP", "r", stdin);
	freopen("JOI19_ho_t3.OUT", "w", stdout);

	cin >> n >> s;
	n = s.size();
	s = ' ' + s;
	vector <state> S; S.clear();
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int k = 0; k <= n; ++k) {
				S.push_back({i, j, k});
				memo[i][j][k] = oo;
			}
		}
	}
	memo[0][0][0] = 0;
	sort(S.begin(), S.end(), [](state a, state b) {
		return max(max(a.lastR, a.lastG), a.lastY) < max(max(b.lastR, b.lastG), b.lastY);
	});
	int res = oo;
	for (state st : S) {
		int lastR = st.lastR, lastG = st.lastG, lastY = st.lastY, i = max(max(lastR, lastG), lastY);
		if (memo[lastR][lastG][lastY] == oo) continue;
		int cur = memo[lastR][lastG][lastY];
		if (i == n) {
			res = min(res, cur);
			continue;
		}
		if (s[i + 1] == 'R') {
			if (lastR == i && i != 0) continue;
			upd(memo[i + 1][lastG][lastY], cur); // put at the end
			if (lastG > lastY) {
				if (lastR != i - 1 || i == 1) upd(memo[i][i + 1][lastY], cur + 1); // put near the end
				if (lastR < lastY - 1) upd(memo[lastY][i + 1][lastY + 1], cur + (i - lastY + 1)); // put after the last Y
			} else {
				if (lastR != i - 1 || i == 1) upd(memo[i][lastG][i + 1], cur + 1); // put near the end
				if (lastR < lastG - 1) upd(memo[lastG][lastG + 1][i + 1], cur + (i - lastG + 1)); // put after the last Y
			}
		}
		if (s[i + 1] == 'G') {
			if (lastG == i && i != 0) continue;
			upd(memo[lastR][i + 1][lastY], cur); // put at the end
			if (lastR > lastY) {
				if (lastG != i - 1 || i == 1) upd(memo[i + 1][i][lastY], cur + 1); // put near the end
				if (lastG < lastY - 1) upd(memo[i + 1][lastY][lastY + 1], cur + (i - lastY + 1)); // put after the last Y
			} else {
				if (lastG != i - 1 || i == 1) upd(memo[lastR][i][i + 1], cur + 1); // put near the end
				if (lastG < lastR - 1) upd(memo[lastR + 1][lastR][i + 1], cur + (i - lastR + 1)); // put after the last Y
			}
		}
		if (s[i + 1] == 'Y') {
			if (lastY == i && i != 0) continue;
			upd(memo[lastR][lastG][i + 1], cur); // put at the end
			if (lastR > lastG) {
				if (lastY != i - 1 || i == 1) upd(memo[i + 1][lastG][i], cur + 1); // put near the end
				if (lastY < lastG - 1) upd(memo[i + 1][lastG + 1][lastG], cur + (i - lastG + 1)); // put after the last Y
			} else {
				if (lastY != i - 1 || i == 1) upd(memo[lastR][i + 1][i], cur + 1); // put near the end
				if (lastY < lastR - 1) upd(memo[lastR + 1][i + 1][lastR], cur + (i - lastR + 1)); // put after the last Y
			}
		}
	}
	cout << res << endl;

	return 0;
}