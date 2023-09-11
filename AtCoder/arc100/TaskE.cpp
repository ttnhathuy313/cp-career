#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = (1 << 19);
int a[N], n, ans[N];
ii F[N];

ii combine(ii A, ii b) {
	vector <int> v; v.clear();
	v.push_back(A.first); v.push_back(A.second);
	v.push_back(b.first); v.push_back(b.second);
	sort(v.begin(), v.end(), [](int i, int j) {
		return (a[i] > a[j]);
	});
	return {v[0], v[1]};
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.INP", "r", stdin);
	freopen("TaskE.OUT", "w", stdout);

	cin >> n;
	for (int i = 0; i < (1 << n); ++i) {
		cin >> a[i];
		F[i] = {i, 0};
	}
	for (int mask = 1; mask < (1 << n); ++mask) {
		set <ii> V; V.clear();
		V.insert({-a[mask], mask});
		for (int i = 0; i < n; ++i) if (mask & (1 << i)) {
			V.insert({-a[F[mask ^ (1 << i)].first], F[mask ^ (1 << i)].first});
			V.insert({-a[F[mask ^ (1 << i)].second], F[mask ^ (1 << i)].second});
		}
		F[mask] = {(*V.begin()).second, (*++V.begin()).second};
	}
	for (int i = 1; i < (1 << n); ++i) {
		ans[i] = a[F[i].first] + a[F[i].second];
		ans[i] = max(ans[i], ans[i - 1]);
		cout << ans[i] << endl;
	}

	return 0;
}