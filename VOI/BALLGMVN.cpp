#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2005;
int n, x[N], y[N];

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

unordered_map <ii, ii, hash_pair> cnt[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("BALLGMVN.INP", "r", stdin);
	freopen("BALLGMVN.OUT", "w", stdout);

	cin >> n;

	for (int i = 1; i <= 2 * n; ++i) {
		cin >> x[i] >> y[i];
		// cerr << "(" << x[i] << ", " << y[i] << ")" << endl;
 	}
 	for (int i = 1; i <= n; ++i) {
 		for (int j = n + 1; j <= 2 * n; ++j) {
 			int u = x[j] - x[i], v = y[j] - y[i];
 			int g = __gcd(u, v);
 			if (g == 0) continue;
 			u /= g; v /= g;
 			cnt[i][ii(u, v)] = ii(i, j);
 			cnt[j][ii(u, v)] = ii(i, j);
 		}
 	}
 	for (int i = 1; i <= n; ++i) {
 		for (int j = 1; j <= n; ++j) if (i != j) {
 			int u = x[j] - x[i], v = y[j] - y[i];
 			int g = __gcd(u, v);
 			if (g == 0) continue;
 			u /= g, v /= g;
 			if (cnt[i][ii(u, v)] == ii(0, 0)) continue;
 			set <int> s; s.clear();
 			s.insert(i); s.insert(j);
 			s.insert(cnt[i][{u, v}].first);
 			s.insert(cnt[i][{u, v}].second);
 			for (int t : s) cout << t << ' ';
 			return 0;
 		}
 	}
 	for (int i = n + 1; i <= n * 2; ++i) {
 		for (int j = n + 1; j <= n * 2; ++j) if (i != j) {
 			int u = x[j] - x[i], v = y[j] - y[i];
 			int g = __gcd(u, v);
 			if (g == 0) continue;
 			u /= g, v /= g;
 			if (cnt[i][ii(u, v)] == ii(0, 0)) continue;
 			set <int> s; s.clear();
 			s.insert(i); s.insert(j);
 			s.insert(cnt[i][{u, v}].first);
 			s.insert(cnt[i][{u, v}].second);
 			for (int t : s) cout << t << ' ';
 			return 0;
 		}
 	}
 	cout << -1 << endl;

	return 0;
}