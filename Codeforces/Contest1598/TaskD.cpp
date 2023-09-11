#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int a[N], b[N], cnt1[N], cnt2[N], cnt3[N];
vector <int> val[N];

int C[5][N];

void updateckn() {
	for (int k = 0; k < 5; ++k)
		for (int n = 0; n < N; ++n) {
			if (k > n) {
				C[k][n] = 0;
				continue;
			}
			if (k == 0 || k == n || n == 0) {
				C[k][n] = 1;
				continue;
			} else {
				C[k][n] = (C[k - 1][n - 1] + C[k][n - 1]);
			}
		}
}

int calc(vector <int> A) {
	int n = A.size();
	vector <vector <int>> dp(n + 5, vector <int> (4, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		int v = A[i - 1];
		for (int j = 0; j <= 3; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (j) dp[i][j] += dp[i - 1][j - 1] * v;
		}
	}
	return dp[n][3];
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int tc;
	cin >> tc;
	updateckn();
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i] >> b[i];
			cnt1[i] = cnt2[i] = cnt3[i] = 0;
			val[i].clear();
		}
		for (int i = 1; i <= n; ++i) {
			cnt1[a[i]]++;
			cnt2[b[i]]++;
			val[a[i]].push_back(b[i]);
		}
		vector <int> vv; vv.clear();
		for (int i = 1; i <= n; ++i) if (cnt1[i])
			vv.push_back(cnt1[i]);
		int res = calc(vv);
		for (int i = 1; i <= n; ++i) if (val[i].size()) {
			int m = val[i].size();
			int temp = C[2][m] * (n - m);
			for (int v : val[i]) {
				cnt2[v]--;
				cnt3[v] = 0;
			}
			//one in block
			for (int v : val[i]) {
				temp -= cnt2[v] * (m - 1);
				cnt3[v]++;
			}
			for (int v : val[i]) if (cnt3[v] != 0) {
				temp -= C[2][cnt3[v]] * (n - m);
				cnt3[v] = 0;
			}
			for (int v : val[i]) {
				cnt3[v]++;
			}
			// two in block
			for (int v : val[i]) if (cnt3[v] != 0) {
				temp += C[2][cnt3[v]] * cnt2[v];
				cnt3[v] = 0;
			}

			// all in block
			for (int v : val[i]) {
				cnt3[v]++;
			}
			vv.clear();
			for (int v : val[i]) if (cnt3[v] != 0) {
				vv.push_back(cnt3[v]);
				cnt3[v] = 0;
			}
			temp += calc(vv);


			for (int v : val[i]) {
				cnt2[v]++;
			}

			res += temp;
		}
		cout << res << endl;

	}	

	return 0;
}