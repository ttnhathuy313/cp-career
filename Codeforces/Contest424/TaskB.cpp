#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 1e3 + 5;
int x[N], y[N], a[N], n;

bool cmp(int i, int j) {
	return x[i] * x[i] + y[i] * y[i] < x[j] * x[j] + y[j] * y[j];
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.inp", "r", stdin);
	freopen("TaskB.out", "w", stdout);

	int s;
	cin >> n >> s;
	vector <int> indices;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i] >> a[i];
		indices.push_back(i);
	}
	sort(indices.begin(), indices.end(), cmp);
	int rem = 1000000 - s;
	for (int i : indices) {
		rem -= a[i];
		if (rem <= 0) {
			cout << fixed << setprecision(9) << sqrt(x[i] * x[i] + y[i] * y[i]) << endl;
			return 0;
		}
	}
	cout << -1 << endl;

	return 0;
}