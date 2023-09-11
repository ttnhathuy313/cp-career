#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;
#define all(x) x.begin(), x.end()
 
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);

	int n; cin >> n;
	vector<int> x(n), y(n);
	vector<ii> ball(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		if(x[i] < y[i]) swap(x[i], y[i]);
		ball[i] = {x[i], y[i]};
	}
	sort(all(x)); sort(all(y));
	int ans = (x[n - 1] - x[0]) * (y[n - 1] - y[0]);
	sort(all(ball));
	int rrange = x[n - 1] - y[0];
	priority_queue<int , vector<int>, greater<int>> pque;
	priority_queue<int> pque2;
	pque.push(ball[n - 1].second);
	pque2.push(ball[n - 1].second);
	for(int i = n - 2; i >= 0; --i) {
		int bmax = max(ball[i].first, pque2.top());
		int bmin = min(ball[0].first, pque.top());
		ans = min(ans, rrange * (bmax - bmin));
		pque.push(ball[i].second);
		pque2.push(ball[i].second);
	}
	cout << ans << endl;
    return 0;
}