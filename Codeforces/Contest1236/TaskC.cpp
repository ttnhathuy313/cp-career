#include <bits/stdc++.h>

using namespace std;

const int N = 305;
int ans[N][N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.inp", "r", stdin);
	freopen("TaskC.out", "w", stdout);

	int n;
	cin >> n;
	int a = 1, b = 1;
	int id = 0;
	bool down = true;
	while (1) {
		//cerr << a << ' ' << b << endl;
		ans[a][b] = ++id;
		if (a == 1 && b == n && n % 2 == 0) break;
		if (n % 2 == 1 && a == n && b == n) break;
		if (down) {
			if (a == n) {
				b++;
				down ^= 1;
			} else a++;
			continue;
		}
		if (a == 1) {
			b++;
			down ^= 1;
		} else a--;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++	j) {
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}