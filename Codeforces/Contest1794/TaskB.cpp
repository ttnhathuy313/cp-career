#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4;
int n, a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] == 1) {
				a[i]++;
			}
		}
		for (int i = 2; i <= n; ++i) {
			while ((a[i] % a[i - 1]) == 0) {
				a[i]++;
			}
		}
		for (int i = 1; i <= n; ++i) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}

	return 0;
}