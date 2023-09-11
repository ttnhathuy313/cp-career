#include <bits/stdc++.h>

using namespace std;

template<class A, class B> bool maximize(A& x, B y) {if (x < y) return x = y, true; else return false;}
template<class A, class B> bool minimize(A& x, B y) {if (x > y) return x = y, true; else return false;}

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << " ]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define     deb(x...)             cerr << "[ in " <<__func__<< "() : line " <<__LINE__<< " ] : [ " << #x << " ] = [ "; _print(x); cerr << '\n';

typedef     long long             ll;
typedef     unsigned long long    ull;
typedef     double                db;
typedef     long double           ld;
typedef     pair<db, db>          pdb;
typedef     pair<ld, ld>          pld;
typedef     pair<int, int>        pii;
typedef     pair<ll, ll>          pll;
typedef     pair<ll, int>         plli;
typedef     pair<int, ll>         pill;

#define     all(a)                a.begin(), a.end()
#define     pb                    push_back
#define     pf                    push_front
#define     fi                    first
#define     se                    second
#define     int                   long long

const int MAX_N = 1e5 + 5;
const int MAX_P = 100 + 5;
const int inf = 1e18 + 1;

int n, m, P;
int d[MAX_N];
int h[MAX_N];
int t[MAX_N];
int sum[MAX_N];
int dp[MAX_N][MAX_P];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("TaskA.inp", "r", stdin);
	freopen("TaskA.out", "w", stdout);

    cin >> n >> m >> P;
    for (int i = 2; i <= n; i++) {
        cin >> d[i];
        d[i] += d[i - 1];
    }
    int res = 0;
    for (int i = 1; i <= m; i++) {
        cin >> h[i] >> t[i];
        if (t[i] >= d[h[i]]) {
            t[i] -= d[h[i]];
        }
        else {
            res += d[h[i]] - t[i];
            t[i] = 0;
        }
    }

    sort(t + 1, t + m + 1);
    for (int i = 1; i <= m; i++) {
        sum[i] = sum[i - 1] + t[i];
    }

    /// dp[i][p] = dp[j][p - 1] + sum[i] - sum[j] - (i - j) * t[j + 1]
    ///             j < i
    ///          = dp[j][p - 1] + sum[i] - sum[j] - i * t[j + 1] + j * t[j + 1]
    ///          = (dp[j][p - 1] - sum[j] + j * t[j + 1]) - i * t[j + 1] + sum[i]
    ///                          b                        - x *   a      +  extra

    for (int i = 1; i <= m; i++) {
        for (int p = 0; p <= P; p++) {
            dp[i][p] = inf;
        }
    }
    for (int p = 1; p <= P; p++) {
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < i; j++) {
                minimize(dp[i][p], dp[j][p - 1] + sum[i] - sum[j] - (i - j) * t[j + 1]);
            }
        }
    }

    cout << dp[m][P] + res;

	return 0;
}

/*


*/