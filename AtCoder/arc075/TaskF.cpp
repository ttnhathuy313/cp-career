#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
int ans, p10[50];
 
void solve(int p1, int p2, int rem, int nmult) {
    if (p1 <= p2) {
        if (p1 == p2) nmult *= 10;
        if (rem == 0) ans += nmult;
        return;
    }
    int ndiff = p10[p1] - p10[p2];
    for (int i = -9; i <= 9; i++) {
        int knew = rem + i * ndiff;
        if (abs(knew) < p10[p1]) {
            int nways = 10 - abs(i);
            if (p2 == 0 && i <= 0) nways--;
            solve(p1 - 1, p2 + 1, knew, nmult * nways);
        }
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TaskF.inp", "r", stdin);
    ans = 0;
    p10[0] = 1;
    for (int i = 1; i < 50; i++)
        p10[i] = p10[i - 1] * 10;
    int D;
    cin >> D;
    for (int i = 1; i <= 18; i++)
        solve(i - 1, 0, D, 1);
 
    cout << ans << "\n";
    return 0;
}