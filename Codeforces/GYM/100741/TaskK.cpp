#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
bool win[N][N];
int deg[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskK.inp", "r", stdin);
	freopen("TaskK.out", "w", stdout);

	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	for (int i = n; i > n / 2; --i) {
		for (int j = 1; j <= n / 2; ++j) {
			if (i & 1) win[i][j] = 1, deg[j]++, deg[i]--;
			else win[j][i] = 1, deg[i]++, deg[j]--;
		}
		for (int j = i - 1; j > n / 2; --j) {
			if (i & 1) win[j][i] = 1, deg[i]++, deg[j]--;
			else win[i][j] = 1, deg[j]++, deg[i]--;
		}
	}
	for (int i = 1; i <= n; ++i) if (deg[i] != 0) cerr << "lmao" << endl;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			cout << win[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}