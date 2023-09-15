#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, l[N], r[N], a[N], b[N], x[N], dp[N], res[N];

struct Segment {
    int l, r, a, b, id;
    bool operator<(const Segment& other) const {
        return b > other.b;
    }
};

struct Event {
    int x, type, id;
    bool operator<(const Event& other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return type < other.type;
    }
};

void solve() {
    cin >> n;
    vector <Segment> segs;
    segs.clear();
    for (int i = 1; i <= n; ++i) {
        cin >> l[i] >> r[i] >> a[i] >> b[i];
        segs.push_back({l[i], r[i], a[i], b[i], i});
        dp[i] = 0;
    }
    sort(segs.begin(), segs.end());
    set <pair <int, int>> ans;
    ans.clear();

    for (auto seg : segs) {
        // cout << seg.l << ' ' << seg.r << ' ' << seg.a << ' ' << seg.b << '\n';
        auto it = ans.lower_bound({-seg.b, 0});
        dp[seg.id] = seg.b;
        if (it != ans.end()) {
            if (it->second > seg.b) {
                dp[seg.id] = it->second;
            }
        }
        ans.insert({-seg.l, dp[seg.id]});
        // cout << seg.id << ' ' << dp[seg.id] << '\n';
    }

    vector <Event> sweep;
    sweep.clear();

    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> x[i];
        sweep.push_back({x[i], 1, i});
    }
    for (int i = 1; i <= n; ++i) {
        sweep.push_back({l[i], 0, i});
        sweep.push_back({r[i], 2, i});
    }
    sort(sweep.begin(), sweep.end());
    multiset<int> cur;
    for (Event e : sweep) {
        if (e.type == 0) {
            cur.insert(dp[e.id]);
        }
        if (e.type == 1) {
            res[e.id] = x[e.id];
            if (!cur.empty()) {
                res[e.id] = max(res[e.id], *cur.rbegin());
            }
        }
        if (e.type == 2) {
            cur.erase(cur.find(dp[e.id]));
        }
    }
    for (int i = 1; i <= q; ++i) {
        cout << res[i] << ' ';
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}