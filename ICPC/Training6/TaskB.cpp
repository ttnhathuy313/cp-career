#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 2005, MOD1 = 1e9 + 7, MOD2 = 923439347;
int pw1[N], pw2[N];

template<typename T1, typename T2>
struct hash_val
{
    T1 val1;
    T2 val2;
   
 
    // constructor
    hash_val() {val1 = val2 = 0;}
    hash_val(T1 val1, T2 val2)
    {
        this->val1 = val1;
        this->val2 = val2;
    }
 
    bool operator==(const hash_val &p) const {
        return val1 == p.val1 && val2 == p.val2;
    }
};
 
struct hash_fn
{
    template <class T1, class T2>
    std::size_t operator() (const hash_val<T1, T2> &node) const
    {
        std::size_t h1 = std::hash<T1>()(node.val1);
        std::size_t h2 = std::hash<T2>()(node.val2);
 
        return h1 ^ h2;
    }
};

int n, a[N], x[N], y[N], cnt = 0, mark[N];
map <ii, int> mp;
unordered_map <hash_val <int, int>, int, hash_fn> cnt_hash;

void solve() {
	mp.clear(); cnt = 0;
	cnt_hash.clear();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		if (x[i] > y[i]) swap(x[i], y[i]);
		if (mp.find({x[i], y[i]}) == mp.end()) {
			mp[{x[i], y[i]}] = ++cnt;
		}
		a[i] = mp[{x[i], y[i]}];
	}
	for (int i = 1; i <= n; ++i) {
		hash_val <int, int> cur;
		for (int j = i; j <= n; ++j) {
			(cur.val1 += pw1[a[j]]) %= MOD1;
			(cur.val2 += pw2[a[j]]) %= MOD2;
			cnt_hash[cur]++;
		}
	}
	int res = 0;
	for (auto D : cnt_hash) {
		res += D.second * (D.second - 1) / 2;
	}
	cout << res << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskB.INP", "r", stdin);
	freopen("TaskB.OUT", "w", stdout);

	pw1[0] = pw2[0] = 1;
	for (int i = 1; i < N; ++i) {
		pw1[i] = pw1[i - 1] * 10007 % MOD1;
		pw2[i] = pw2[i - 1] * 20007 % MOD2;
	}

	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}