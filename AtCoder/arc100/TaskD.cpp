#include<bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2e5 + 5;
int a[N], n;
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskD.inp", "r", stdin);

	cin >> n; 
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> b(n + 1);
    for(int i = 1; i <= n; i++)
        b[i] = b[i-1] + a[i-1];
    int r = 1e18;
    for(int i = 2; i <= n - 2; i++) {
        int ls = b[i], rs = b[n] - b[i];
        for(int lls : {
                *prev(upper_bound(b.begin(), b.begin()+i+1, ls/2)),
                *lower_bound(b.begin(), b.begin()+i+1, ls/2),
                })
        for(int rls : {
                *prev(upper_bound(b.begin()+i+1, b.end(), ls + rs/2)) - ls,
                *lower_bound(b.begin()+i+1, b.end(), ls + rs/2) - ls,
                }) {
            int lrs = ls - lls;
            int rrs = rs - rls;
 
            int mx = max(max(lls, lrs), max(rls, rrs));
            int mn = min(min(lls, lrs), min(rls, rrs));
 
            r = min(r, mx-mn);
        }
    }
    cout << r << endl;
    return 0;
}