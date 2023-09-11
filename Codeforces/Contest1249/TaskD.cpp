#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 2e5 + 5;
vector <ii> PushIn[N];
bool ans[N];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);
	freopen("TaskD.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	multiset <ii> avail;
	for (int i = 1; i <= n; ++i) {
		int l, r;
		cin >> l >> r;
		PushIn[l].push_back(ii(r, i));
	}
	int m = 0;
	for (int i = 1; i < N; ++i) {
		for (ii d : PushIn[i]) avail.insert(d);
		while (avail.size() > 0 && (*(avail.begin())).first < i) {
			avail.erase(avail.begin());
		}
		int rem = avail.size() - k;
		if (rem <= 0) continue;
		m += rem;
		while(rem--) {
			ii val = *(avail.rbegin());
			multiset<ii>::iterator it = avail.find(val);
			avail.erase(it);
			ans[val.second] = true;
		}
	}
	cout << m << endl;
	for (int i = 1; i <= n; ++i) if (ans[i]) cout << i << " ";

	return 0;
}