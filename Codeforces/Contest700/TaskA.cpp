#include <bits/stdc++.h>

using namespace std;

double l, v1, v2;
int n, k, group;

bool check(double t) {
    double t2 = (l - t * v1) / (v2 - v1);
 
    double dist = t2 * (v2 - v1);
    double gap = dist / (v1 + v2);
 
    return t2 * group + gap * (group - 1) <= t;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskA.INP", "r", stdin);
	freopen("TaskA.OUT", "w", stdout);
	cout << fixed << setprecision(9);
	cin >> n >> l >> v1 >> v2 >> k;
	group = (n + k - 1) / k;
	double left = 0, right = 1.0 * l / v1;
	int cnt = 100;
	while (cnt--) {
		double mid = (left + right) / 2;
		if (check(mid)) right = mid;
		else left = mid;
	}
	cout << left << endl;

	return 0;
}