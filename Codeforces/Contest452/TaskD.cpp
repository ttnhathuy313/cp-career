#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define forn(i, a, b) for (int i = a; i <= b; ++i)

multiset <int> wash, dry, fold;
int k, n1, n2, n3, t1, t2, t3;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.INP", "r", stdin);
	freopen("TaskD.OUT", "w", stdout);

	cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
	rep(i, n1) wash.insert(0);
	rep(i, n2) dry.insert(0);
	rep(i, n3) fold.insert(0);

	int res = 0;
	rep(turn, k) {
		int w = *wash.begin(), d = *dry.begin(), f = *fold.begin();
		d = max(d, f - t2);	
		w = max(w, d - t1);
		res = max(res, w + t1 + t2 + t3);
		wash.erase(wash.begin()); wash.insert(w + t1);
		dry.erase(dry.begin()); dry.insert(w + t1 + t2);
		fold.erase(fold.begin()); fold.insert(w + t1 + t2 + t3);
	}
	cout << res << endl;

	return 0;
}	