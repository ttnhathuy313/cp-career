#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, a[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		set <int> s;
		s.clear();
		int mx = -1, id = -1;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			s.insert(a[i]);
			if (i - int(s.size()) > mx) {
				mx = i - int(s.size());
				id = i;
			}
		}
		cout << 1 << ' ' << id << endl;
	}

	return 0;
}