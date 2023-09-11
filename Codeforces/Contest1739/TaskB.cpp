#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		bool ok = true;
		for (int i = 2; i <= n; ++i) {
			if (a[i - 1] - a[i] >= 0 && a[i] != 0) {
				ok = false;
				break;
			}
			a[i] = a[i - 1] + a[i];
		}
		if (!ok) {
			cout << -1 << endl;
		} else {
			for (int i = 1; i <= n; ++i) {
				cout << a[i] << ' ';
			}
			cout << endl;
		}
	}	

	return 0;
}