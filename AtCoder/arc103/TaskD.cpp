#include <bits/stdc++.h>
 
using namespace std;
#define int long long

const int N = 1e4 + 5; 
int n, x[N], y[N], d[1000];
bool flag = false;
 
int dis(int xa, int ya, int xb, int yb) {
	return abs(xa - xb) + abs(ya - yb);
}
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);
 
	cin >> n; 
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];
	flag = abs(x[1] + y[1]) & 1;
 
	for (int i = 1; i <= n; ++i)
		if ((abs(x[i] + y[i]) & 1) != flag) {
			cout << -1 << endl;
			return 0;
		}
 
	cout << (flag ? 31 : 32) << endl;
	for (int i = 1; i <= 31; ++i)
		cout << (d[i] = (1 << (31 - i))) << ' ';
	if (!flag) cout << (d[32] = 1) << endl;
	else cout << endl;
 
	for (int i = 1; i <= n; ++i) {
		int xd = 0, yd = 0;
		if (!flag) xd = 1;
		for (int j = 1; j <= 31; ++j) {
			char ch; int Dis = LLONG_MAX;
			if (dis(xd + d[j], yd, x[i], y[i]) < Dis)
				Dis = dis(xd + d[j], yd, x[i], y[i]), ch = 'R';
			if (dis(xd - d[j], yd, x[i], y[i]) < Dis)
			   	Dis = dis(xd - d[j], yd, x[i], y[i]), ch = 'L';
			if (dis(xd, yd + d[j], x[i], y[i]) < Dis)
				Dis = dis(xd, yd + d[j], x[i], y[i]), ch = 'U';
			if (dis(xd, yd - d[j], x[i], y[i]) < Dis)
				Dis = dis(xd, yd - d[j], x[i], y[i]), ch = 'D';
			if (ch == 'R') xd += d[j];
			if (ch == 'L') xd -= d[j];
			if (ch == 'U') yd += d[j];
			if (ch == 'D') yd -= d[j];
			cout << ch;
		}
		if (!flag) cout << 'R';
		cout << endl;
	}
 
	return 0;
}