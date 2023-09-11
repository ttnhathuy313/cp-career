#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int n1 = 0, n2 = 0;
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		for (int i = 1; i < n; ++i) {
			if (a[i] == -1 && a[i + 1] == -1) {
				n1++;
			} else if (a[i] + a[i + 1] == 0) {
				n2++;
			}
		}
		if (n1) {
			sum += 4;
		} else if (n2) {
			sum += 0;
		} else sum -= 4;
		cout << sum << endl;
	}

	return 0;
}