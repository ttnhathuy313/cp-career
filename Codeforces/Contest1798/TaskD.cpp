#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

const int N = 3e5 + 5;
int n, a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int mx = -(int)1e9, mi = -mx;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			mx = max(mx, a[i]);
			mi = min(mi, a[i]);
		}
		if (n == 1) {
			cout << "No" << endl;
			continue;
		}
		sort(a + 1, a + 1 + n);
		int i = 1, j = n, inc = 1, cur = 0, dem = 0;
		cout << "Yes" << endl;
		while (dem < n) {
			if (cur + a[j] >= (mx - mi)) {
				cur += a[i];
				cout << a[i] << ' ';
				i++;
				dem++;
			} else {
				cur += a[j];
				cout << a[j] << ' ';
				j--;
				dem++;
			}
		}
		cout << endl;

	}

	return 0;
}