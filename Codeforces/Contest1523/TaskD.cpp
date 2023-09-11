/*
	Problem Descripstion: In the input, you are give n (n <= 2 * 10 ^ 5) masks, each mask consists of m (m <= 60) bits and 
	at most p (p <= 15) bits 1. The task of this problem is to find a new mask (named as X), also consists of m bits, such 
	that there are at least n / 2  masks in the input satisfies that X is a subset of each.

	My approach for this problem is: We are finding X. Then, each masks in the input have to be either the superset of X or not.
	Because X always exists, there should be at least half of the input masks that is the superset of X. This is very suspicious
	in terms of probability. We can randomly choose an element (named Y) in the input masks and assume that it is a superset of X. Then,
	we can try all the possible X and check if it can satisfy the condition in the problem statement. Becauses Y has only p bits
	at most, the number of possible X that we have to check is 2 ^ p. What if Y isn't the actual superset of X in the final answer?
	We can choose another element to assume and continue the process. However, we only have to do it 64 times. Because the
	probability of choosing 64 times and still missed the correct superset is (1/2) ^ 64 ~ 0%.

	In order to check if a mask X satisfies the condition in the problem statement (to count how many input masks that take X
	as a subset), I use the a variation of dynamic programming sum over subset (the inverted problem of the original one).

	Time Complexity:  O(64 * p * 2 ^ p).
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, m, p, a[N], dp[(1 << 17)], pos[30];
string s[N]; // I read the input masks as strings of length m

pair <int, string> solve(int id) { // the integer will be the number of bit 1 in the answer mask. The string will be the mask itself
	memset(a, 0, sizeof a); // I compress all masks into the length of p because only p bits that is 1 in the chosen element matters.
	memset(dp, 0, sizeof dp); // After calculation, this array returns the number of input masks that take X as a subset
	memset(pos, 0, sizeof pos); // This is an auxiliary array to recover the masks into the original one (because we compressed it)
	
	// begin compression
	int cnt = 0;
	for (int k = 1; k <= m; ++k) {
		if (s[id][k] == '0') continue;
		pos[cnt] = k;
		for (int i = 1; i <= n; ++i) {
			if (s[i][k] == '1') a[i] |= (1 << cnt);
		}
		cnt++;
	}
	// end of compression, each masks consists of p meaningful bits.

	// Calculating for each X, how many input masks that take X as a subset using dynamic programming sum over subset.
	int full_mask = (1 << cnt) - 1;
	for (int i = 1; i <= n; ++i) {
		dp[~a[i] & full_mask]++; // ~a[i] & full_mask is toggling the mask. It is because we are using the inverted version of dp sos
	}
	for (int i = 0; i < cnt; ++i) { // This is essentially dp sos
		for (int mask = 0; mask < (1 << cnt); ++mask) if (mask & (1 << i))
			dp[mask] += dp[mask ^ (1 << i)];
	}
	// Done calculating

	pair <int, int> res = make_pair(-1, 0);
	for (int mask = 0; mask < (1 << cnt); ++mask) if (dp[~mask & full_mask] >= (n + 1) / 2) { // Trying all the possible masks X
		if (res.first < __builtin_popcount(mask)) {
			res = make_pair(__builtin_popcount(mask), mask);
		}
	}

	string ret; ret.clear();
	for (int i = 1; i <= m; ++i) 
		ret += '0';
	for (int i = 0; i < cnt; ++i) if (res.second & (1 << i)) // recovering the original mask.
		ret[pos[i] - 1] = '1';
	return make_pair(res.first, ret);
}

signed main() {
	mt19937 rng(time(0) + 114514);
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m >> p;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		s[i] = ' ' + s[i];
	}
	int tries = 60;
	pair <int, string> res = make_pair(-1, "thisisarandomstring"); // Initialize
	while (tries--) {
		int id = uniform_int_distribution<int>(0, n - 1)(rng) + 1; // Choose a randome number between 1 and n
		pair <int, string> ret = solve(id); // Try all the possible X for each choice of element.
		if (res.first < ret.first) { // If this creates a better mask, update it to the answer
			res = ret;
		}
	}
	cout << res.second << endl;

	return 0;
}