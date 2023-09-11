#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, a[N], m, k;

void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> a[i];
	}
	int storage = n * m - 2;
	priority_queue <int> mx;
	while (!mx.empty())
		mx.pop();
	int finding = k;
	for (int i = 1; i <= k; ++i) {
		if (a[i] != finding) {
			mx.push(a[i]);
			if (mx.size() > storage) {
				cout << "TIDAK" << endl;
				return;
			}
		} else {
			finding--;
			while (!mx.empty() && mx.top() == finding) {
				finding--;
			}
		}
	}
	cout << "YA" << endl;

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