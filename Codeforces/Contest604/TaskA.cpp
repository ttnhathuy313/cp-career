#include <bits/stdc++.h>

using namespace std;

double w[44], m[44], score[] = {0, 500, 1000, 1500, 2000, 2500};

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);

	for (int i = 1; i <= 5; ++i) {
		cin >> m[i];
	}
	for (int i = 1; i <= 5; ++i) cin >> w[i];
	double res = 0;
	for (int i = 1; i <= 5; ++i) {
		res += max(score[i] / 3, score[i] - (score[i] * m[i]) / 250 - 50 * w[i]);
	}
	int u, v; cin >> u >> v;
	res += u * 100 - v * 50;
	cout << (int)res << endl;

	return 0;
}