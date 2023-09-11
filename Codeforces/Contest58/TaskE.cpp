#include <bits/stdc++.h>

using namespace std;
#define forn(i,a,b) for (int i = a; i <= b; ++i)
#define rep(i,a) for (int i = 0; i <= a; ++i)

const int N = 25;
int dp[N][N][N][N][2][2][2], na, nb, nc;
string a, b, c, A, B, C;

void pros(string &x) {
	reverse(x.begin(), x.end());
	x = ' ' + x;
}

struct col {
	int a, b, c;
} value[N][N][N][N][2][2][2];

struct pack {
	int i, posa, posb, posc, carry, enda, endb;
} trace[N][N][N][N][2][2][2], root;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	string t, tmp; tmp.clear();
	cin >> t;
	for (int i = 0; i < t.size(); ++i) {
		if (t[i] >= '0' && t[i] <= '9') {
			tmp += t[i];
		} else {
			if (t[i] == '+') a = tmp;
			if (t[i] == '=') b = tmp;
			tmp.clear();
		}
	}
	c = tmp;
	na = a.size(); nb = b.size(); nc = c.size();
	pros(a); pros(b); pros(c);
	memset(dp, -1, sizeof dp);
	dp[0][0][0][0][0][0][0] = 0;
	int res = N * N;
	rep(i, 20) rep(posa, na) rep(posb, nb) rep(posc, nc) rep(carry, 1) rep(enda, 1) rep(endb, 1) {
		int cur = dp[i][posa][posb][posc][carry][enda][endb];
		pack address = {i, posa, posb, posc, carry, enda, endb};
		if (cur == -1) continue;
		rep(d1, 9) rep(d2, 9) {
			int s = d1 * (enda?0:1) + d2 * (endb?0:1) + carry;
			int nxt = s % 10, ncarry = s / 10;
			int pa = posa; if (!enda && posa != na && a[posa + 1] - '0' == d1) pa++;
			int pb = posb; if (!endb && posb != nb && b[posb + 1] - '0' == d2) pb++;
			int pc = posc; if (posc != nc && c[posc + 1] - '0' == nxt) pc++;

			forn(nea,enda,1) forn(neb, endb, 1) {
				int &state = dp[i + 1][pa][pb][pc][ncarry][nea][neb];
				if (state == -1 || state > cur + 3 - enda - endb) {
					state = cur + 3 - enda - endb;
					trace[i + 1][pa][pb][pc][ncarry][nea][neb] = address;
					value[i + 1][pa][pb][pc][ncarry][nea][neb] = {(enda ? -1 : d1), (endb ? -1 : d2), nxt};
					continue;
				}
				state = min(state, cur + 3 - enda - endb);
			}
		}
		if (posa == na && posb == nb && posc == nc && res > cur && carry == 0) {
			res = cur;
			root = address;
		}
	}
	pack leaf = {0, 0, 0, 0, 0, 0, 0};
	while (root.i + root.posa + root.posb + root.posc + root.carry + root.enda + root.endb != 0) {
		col D = value[root.i][root.posa][root.posb][root.posc][root.carry][root.enda][root.endb];
		if (D.a != -1) A += char('0' + D.a);
		if (D.b != -1) B += char('0' + D.b);
		C += char('0' + D.c);
		root = trace[root.i][root.posa][root.posb][root.posc][root.carry][root.enda][root.endb];
	}
	cout << A << "+" << B << "=" << C << endl;

	return 0;
}