#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, a[N], k;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen("TaskE.INP", "r", stdin);
	// freopen("TaskE.OUT", "w", stdout);

	multiset <int> a; a.clear();
	for (int i = 1; i <= 5; ++i) a.insert(i);
	for (int c : a) cerr << c << endl;
	for (int i = 1; i <= 5; ++i) {
		int cur = *a.begin();
		cerr << cur << endl;
		a.erase(a.begin());
	}

	return 0;
}