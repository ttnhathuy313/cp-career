#include <bits/stdc++.h>

/*
	The idea of slope trick : 
		- prove that the function is slope-trick-able (convex / concave, lines has INTEGER slope)
		- The merging property of two slope-trick-able function
		==> Another way of saving the graph of function : We go from right to left, if the slope decrease once, we add
		the point when it change (if at the same point, the slope change twice then we add it twice)
		- The graph (of g, not f) has a property that, the last line's slope has slope 1. At sometimes, higher we add, higher cost we get
*/

using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	int n;
	cin >> n;
	priority_queue <int> pq; while (!pq.empty()) pq.pop();
	int res = 0;
	for (int i = 0; i < n; ++i) {
		int ai;
		cin >> ai; ai -= i;
		pq.push(ai);
		if (pq.top() > ai) {
			res += pq.top() - ai;
			pq.pop(); // We pop the slope-point that make the graph rise up
			pq.push(ai); // mergings of two function is unions of two slope-changing points, absolute has two ai_s
		}
		/* 
		In case of pq.top() <= ai, we just add and pop right after that so it doesn't matter
		*/
	}
	cout << res << endl;

	return 0;
}