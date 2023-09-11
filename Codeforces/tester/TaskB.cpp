#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
int n, xuoi[N], nguoc[N], c[N], d[N], a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, n0 = 0;
		cin >> n;
		int pren = n;
		vector <int> pos;
		pos.clear();
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> a[i];
			if (a[i] == 0) {
				pos.push_back(i);
				n0++;
			}
		}
		if (n0 > 2) {
			cout << "No" << endl;
			continue;
		}
		if (n0 == 1) {
			if (pos[0] != 0 && pos[0] != n - 1) {
				cout << "No" << endl;
				continue;
			}
		}
		if (n0 == 2) {
			if (pos[0] != 0 || pos[1] != n - 1) {
				cout << "No" << endl;
				continue;
			}
		}
		if (n == 0) {
			cout << "No" << endl;
			continue;
		}
		for (int i = 0; i < n; ++i) {
			xuoi[i] = ((a[i] - i >= 0) ? 1 : 0);
			c[i] = i;
			d[i] = (n - i - 1);
			nguoc[i] = ((a[i] - n + i + 1 >= 0) ? 1 : 0);
		}
		for (int i = 1; i < n; ++i)
			xuoi[i] &= xuoi[i - 1];
		for (int i = n - 2; i >= 0; --i)
			nguoc[i] &= nguoc[i + 1];
		bool found = false;
		for (int i = 0; i < n - 1; ++i) {
			if (xuoi[i] && nguoc[i + 1] && !(c[i] == d[i + 1] && a[i] == a[i + 1])) {
				found = true;
			}
		}
		if (xuoi[n - 1]) found |= true;
		if (nguoc[0]) found |= true;
		if (found) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}