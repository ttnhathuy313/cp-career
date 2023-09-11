#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		cerr << "(" << x << ", " << y << ")" << endl;
	}

	return 0;
}