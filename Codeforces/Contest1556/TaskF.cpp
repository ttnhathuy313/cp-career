/*
	This problem is hard!
	First, after sketching the graph of the solution, I've recoginized that all winners lie in one main scc. The non-winner
	will be in a different scc that can be directly reached from every winner.
	Secondly, we have to iterate through the set of winner and calculate the probability of orientation that will make the
	complete graph become an scc.
	Let the probability for a set to be winners (or the probability of making a complete graph become an scc) be dp(X). 
	But calculate it directly is difficult as I tried it. Let's solve the opposite problem: the probability of not making
	it become an scc. Now, as always, we have to look at the model of the solution, aka the model of "not scc". It is actually
	a dag of smaller scc. Look at the dag more carefully, we can see that there is exactly one vertex with zero in-degree. It's
	because the graph is complete, if there are two zero in-degree vertices, they will be connected and one of them won't be
	zero in-degree anymore. Thus, that zero in-degree will be the representative for each representation of the graph. This is
	extremely useful in dp as we can extract the representative to create sub-problems. Because the representative is zero in-degree,
	we will have only outgoing edges from this sub-scc.
	Then, we have to make a bridge between the sub-sccs. This can be calculated using some kind of trick.
*/

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int N = 15, MOD = 1e9 + 7;

int norm(int x) {
    if (x < 0) {
        x += MOD;
    }
    if (x >= MOD) {
        x -= MOD;
    }
    return x;
}
template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct mod_int { // basically just the modulo stuff
    int x;
    mod_int(int x = 0) : x(norm(x)) {}
    int val() const {
        return x;
    }
    mod_int operator-() const {
        return mod_int(norm(MOD - x));
    }
    mod_int inv() const {
        assert(x != 0);
        return power(*this, MOD - 2);
    }
    mod_int &operator*=(const mod_int &rhs) {
        x = i64(x) * rhs.x % MOD;
        return *this;
    }
    mod_int &operator+=(const mod_int &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    mod_int &operator-=(const mod_int &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    mod_int &operator/=(const mod_int &rhs) {
        return *this *= rhs.inv();
    }
    friend mod_int operator*(const mod_int &lhs, const mod_int &rhs) {
        mod_int res = lhs;
        res *= rhs;
        return res;
    }
    friend mod_int operator+(const mod_int &lhs, const mod_int &rhs) {
        mod_int res = lhs;
        res += rhs;
        return res;
    }
    friend mod_int operator-(const mod_int &lhs, const mod_int &rhs) {
        mod_int res = lhs;
        res -= rhs;
        return res;
    }
    friend mod_int operator/(const mod_int &lhs, const mod_int &rhs) {
        mod_int res = lhs;
        res /= rhs;
        return res;
    }
};

int n;
mod_int a[N], num[(1 << N)][N] /*aka numerator with exponentation*/, denom[(1 << N)] /*aka denominator but the complete-graph-like multiplication, not the bridge*/;
mod_int scc[(1 << N)], dp[1 << N], inv_denom[1 << N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskF.INP", "r", stdin);
	freopen("TaskF.OUT", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].x;
	}
	for (int mask = 0; mask < (1 << n); ++mask) {
		num[mask][0] = num[mask][1] = 1;
		for (int i = 0; i < n; ++i) if (mask & (1 << i)) {
			num[mask][1] *= a[i];
		}
		for (int i = 2; i <= n; ++i) {
			num[mask][i] = num[mask][i - 1] * num[mask][1];
		}
		if (mask) {
			int j = __builtin_ctz(mask);
			denom[mask] = denom[mask ^ (1 << j)]; // take advantage of previous calculation
			for (int i = 0; i < n; ++i) if (mask & (1 << i)) {
				if (i != j) denom[mask] *= (a[i] + a[j]); // add more edges to make it complete
			}
		} else denom[mask] = 1;
		inv_denom[mask] = 1 / denom[mask];
	}
	for (int mask = 0; mask < (1 << n); ++mask) {
		scc[mask] = 1;
		for (int sub_mask = mask & (mask - 1); sub_mask > 0; sub_mask = (sub_mask - 1) & mask) {
			scc[mask] -= scc[sub_mask] * num[sub_mask][__builtin_popcount(sub_mask ^ mask)] * denom[sub_mask] * denom[mask ^ sub_mask] * inv_denom[mask];
		}
	}
	for (int mask = 0; mask < (1 << n); ++mask) { //calculate the probability of each set of winners
		int rem = ((1 << n) - 1) ^ mask;
		dp[mask] = scc[mask] * num[mask][__builtin_popcount(rem)] * denom[mask] * denom[rem] * inv_denom[(1 << n) - 1];
	}
	mod_int res = 0;
	for (int mask = 0; mask < (1 << n); ++mask) {
		res += dp[mask] * __builtin_popcount(mask);
	}
	cout << res.x << endl;

	return 0;
}