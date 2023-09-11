#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
int grid[30][30];
 
signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<vector<int>> grid(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i & 1) grid[i][j] = (1LL << (i + j));
			cout << grid[i][j] << " \n"[j == n - 1];
		}
	}
	cout.flush();
	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		int sum; 
		cin >> sum;
		cout << "1 1";
		int row = 0, col = 0;
		for (int step = 0; step < (n << 1) - 2; ++step) {
			int should = sum & (1LL << (step + 1));
			if (row + 1 < n && grid[row + 1][col] == should) ++row;
			else ++col;
			cout << " " << row + 1 << " " << col + 1;
		}
		cout << endl;
		cout.flush();
	}
	return 0;
}