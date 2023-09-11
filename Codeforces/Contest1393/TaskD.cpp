#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
int n, m;
char a[N][N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= m + n - 1; ++i) {
		for (int j = 1; j <= m + n - 1; ++j) {
			a[i][j] = ' ';
		}
	}
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; ++j) {
			a[i + j - 1][n - i + j] = s[j - 1];
			cerr << i + j - 1 << ' ' << n - i + j << endl;
  		}
	}
	for (int i = 1; i <= m + n - 1; ++i) {
		for (int j = 1; j <= m + n - 1; ++j) {
			cerr << a[i][j];
		}
		cerr << endl;
	}

	return 0;
}