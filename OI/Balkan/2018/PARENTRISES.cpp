#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

const int N = 1e6 + 5, M = 305, MOD = 1e9 + 7;
int n, ans[N], dp[M][M * 2][M * 2], mark[N];
string s;

void solve() {
	cin >> s;
	n = s.size();
	stack <int> open; while (!open.empty()) open.pop();
	int balance = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') {
			balance++;
			open.push(i);
			ans[i] = 1;
		} else {
			balance--;
			ans[i] = 1;
			if (balance < 0) {
				balance = 0;
				ans[i] = 2;
				if (open.empty()) {
					cout << "impossible" << endl;
					return;
				}
				int j = open.top(); open.pop();
				ans[j] = 0;
			}
		}
	}
	 while (!open.empty()) open.pop();
	 for (int i = 0; i < n; ++i) if (ans[i] == 0 || ans[i] == 1) {
	 	if (s[i] == '(') {
	 		open.push(i);
	 	} else {
	 		open.pop();
	 	}
	 }
	// for (int i = 0; i < n; ++i) {
	// 	if (ans[i] == 0 || ans[i] == 1) cerr << s[i];
	// } cerr << endl;
	// for (int i = 0; i < n; ++i) {
	// 	if (ans[i] == 0 || ans[i] == 2) cerr << s[i];
	// } cerr << endl;
	// cerr << balance << endl;
	int pre = n - 1;
	stack <int> close; while (!close.empty()) close.pop();
	while (!open.empty()) {
		if (balance == 0) break;
		int i = open.top();
		for (int j = pre; j > i; --j) if (s[j] == ')' && ans[j] == 1)
			close.push(j);
		pre = i;
		open.pop();
		if (close.empty()) {
			continue;
		}
		balance--;
		int j = close.top(); close.pop();
		ans[i] = 2;
		ans[j] = 0;
		if (balance == 0) break;
	}
	if (balance != 0) {
		cout << "impossible" << endl;
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (ans[i] == 0) cout << 'G';
		else if (ans[i] == 1) cout << 'R';
		else cout << 'B';
	}
	cout << endl;
	// cout << s << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("PARENTRISES.INP", "r", stdin);
	freopen("PARENTRISES.OUT", "w", stdout);

	int p;
	cin >> p;
	if (p == 1) {
		int tc;
		cin >> tc;
		while (tc--) {
			solve();
		}
	} else {
		dp[0][0][0]=1;
		for(int i=0;i<M-1;i++){
			for(int j=0;j<=2*i;j++){
				for(int k=0;k<=2*i;k++){
					dp[i+1][j+2][k+1]+=dp[i][j][k];
					if(dp[i+1][j+2][k+1]>=MOD)dp[i+1][j+2][k+1]-=MOD;
					if(j>0){
						dp[i+1][j-1][max(k-2,0)]+=dp[i][j][k];
						if(dp[i+1][j-1][max(k-2,0)]>=MOD)dp[i+1][j-1][max(k-2,0)]-=MOD;
					}
				}
			}
		}
		int tc;
		cin >> tc;
		while (tc--) {
			int d;
			cin >> d;
			int r = 0;
			for (int j = 0; j <= 2 * d; ++j) {
				(r += dp[d][j][0]) %= MOD;
			}
			cout << r << endl;
		}
	}

	return 0;
}