#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n; 
char many[3];
string s[3];

void solve(int k, int t) {
	string a = s[k], b = s[t];
	int j = 0;
	for (int i = 0; i < 2 * n; ++i) {
		if (a[i] == many[k]) {
			while (j < 2 * n && b[j] != many[k]) {
				cout << b[j];
				j++;
			}
			cout << a[i];
			j++;
		} else {
			cout << a[i];
		}
	}
	while (j < 2 * n) {
		cout << b[j];
		j++;
	}
	cout << endl;
}

void solve() {
	cin >> n >> s[0] >> s[1] >> s[2];

	for (int i = 0; i < 3; ++i) {
		int cnt = 0;
		for (int j = 0; j < 2 * n; ++j) {
			if (s[i][j] == '0') cnt++;
		}
		if (cnt < n) many[i] = '1';
		else many[i] = '0';
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) if (i != j && many[i] == many[j]) {
			solve(i, j);
			return;
		}
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}