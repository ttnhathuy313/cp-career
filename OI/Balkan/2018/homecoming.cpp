#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e6 + 5;
int dp[N][2], a[N], b[N], c[N], pref[N];

int solve(int n, int k, int A[], int B[]) {
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= n; ++i) {
		a[i] = A[i - 1], b[i] = B[i - 1];
		c[i] = a[i] - b[i];
		pref[i] = pref[i - 1] + b[i - 1];
	}
	
	return 0;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("homecoming.INP", "r", stdin);
	freopen("homecoming.OUT", "w", stdout);

	int A[] = {1, 1}, B[] = {-1, -1};
	solve(1, 1, A,  B);

	return 0;
}