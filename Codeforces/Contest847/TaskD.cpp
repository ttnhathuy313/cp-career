#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);
	freopen("TaskD.out", "w", stdout);

	int n, T;
	cin >> n >> T;
	priority_queue <int> pq; 
	while (!pq.empty()) pq.pop();
	int res = 0;
	for (int i = 1; i <= min(T - 1, n); ++i) {
		int x;
		cin >> x;
		while (pq.size() > 0 && pq.top() >= T - i)
			pq.pop();
		if (x < T) pq.push(x - i);
		res = max(res, (int)pq.size());
	}
	cout << res << endl;

	return 0;
}