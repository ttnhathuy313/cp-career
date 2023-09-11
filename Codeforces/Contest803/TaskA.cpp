#include <bits/stdc++.h>

using namespace std;
	
const int N = 105;
int res[N][N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.inp", "r", stdin);
	int n, k;	
	cin >> n >> k;
	if (k > n * n) cout << "-1\n";
	else {
		for (int i = 0; k > 0 && i < n; i++) {
			res[i][i] = 1;
			k--;
			for (int j = i + 1; k > 1 && j < n; j++) {
				res[i][j] = res[j][i] = 1;
				k = k - 2;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) cout << res[i][j] << ' ';
			cout << endl;
		}
	}
	return 0;
}