#include <bits/stdc++.h>

using namespace std;
#define int long long
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define REP(i, a) for(int i = 0; i < (a); ++i)
typedef pair <int, int> ii;

const int N = 50;
int dp[20][35][26][17][15];
vector <int> fac[88]; // factorize of number
vector <ii> cmp;

int calc(int rem, int n2, int n3, int n5, int n7) {
	if (n2 < 0 || n3 < 0 || n5 < 0 || n7 < 0) return 0;
	if (rem == 0) {
		if (n2 + n3 + n5 + n7 == 0) return 1;
		else return 0;
	}
	if (~dp[rem][n2][n3][n5][n7]) return dp[rem][n2][n3][n5][n7];
	int ret = 0;
	ret += calc(rem - 1, n2, n3, n5, n7);
	int cur[10];
	memset(cur, 0, sizeof cur);
	cur[2] = n2; cur[3] = n3; cur[5] = n5; cur[7] = n7;
	for (int i = 2; i <= 9; ++i) {
		for (int d : fac[i]) cur[d]--;
		ret += calc(rem - 1, cur[2], cur[3], cur[5], cur[7]);
		for (int d : fac[i]) cur[d]++;

	}
	return dp[rem][n2][n3][n5][n7] = ret;
}

int solve(int R) {
	int tot_result = 0;
	REP(n2, 33) REP(n3, 21) REP(n5, 14) REP(n7, 12) {
		int semi = 1;
		REP(i, n2) semi *= 2; REP(i, n3) semi *= 3; REP(i, n5) semi *= 5; REP(i, n7) semi *= 7;
		int L = R / semi, tmp = L;
		if (L == 0) continue;
		if (semi > L) continue;
		vector <int> digit; digit.clear();
		while (tmp) {
			digit.push_back(tmp % 10);
			tmp /= 10;
		}
		int cur[10];
		memset(cur, 0, sizeof cur);
		cur[2] = n2; cur[3] = n3; cur[5] = n5; cur[7] = n7;
		int res = 0;
		for (int i = 1; i < digit.size(); ++i) {
			res += calc(i, n2, n3, n5, n7); // leading zeroes case
		}
		int lst = digit.size() - 1;
		for (int i = digit.size() - 1; i >= 0; --i) {
			int cur_digit = digit[i];
			if (cur_digit == 0) break;
			for (int nxt = 1; nxt < cur_digit; ++nxt) { // choose next digit, case smaller
				for (int d : fac[nxt]) cur[d]--;
				res += calc(i, cur[2], cur[3], cur[5], cur[7]);
				for (int d : fac[nxt]) cur[d]++;
			}
			//choose next digit, case equal
			for (int d : fac[cur_digit])
				cur[d]--;
			if (cur[2] < 0 || cur[3] < 0 || cur[5] < 0 || cur[7] < 0) break;
			lst = i;
		}
		if (cur[2] == 0 && cur[3] == 0 && cur[5] == 0 && cur[7] == 0 && lst == 0) {
			res++;
		}
		tot_result += res;
		if (res > 0 ){
			cmp.push_back({semi, res});
		}
	}
	return tot_result;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("PERFECT.INP", "r", stdin);
	freopen("PERFECT.OUT", "w", stdout);

	int A, B;
	cin >> A >> B;
	memset(dp, -1, sizeof dp);
	fac[2].push_back(2); fac[3].push_back(3); fac[5].push_back(5); fac[7].push_back(7);
	fac[4].push_back(2); fac[4].push_back(2); fac[6].push_back(3); fac[6].push_back(2);
	fac[8].push_back(2); fac[8].push_back(2); fac[8].push_back(2); fac[9].push_back(3); fac[9].push_back(3);
	cout << solve(B) - solve(A - 1) << endl;
	// sort(cmp.begin(), cmp.end());
	// for (ii v : cmp) {
	// 	cerr << v.first << ' ' << v.second << endl;
	// }

	return 0;
}