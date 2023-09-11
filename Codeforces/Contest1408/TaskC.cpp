#include<bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e6 + 5;
int n, m, q, k, a[N], b[N], c[N], f[N];

signed main() {
    freopen("TaskC.inp","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        double x1 = 0, x2 = k;
        int y1 = 1, y2 = 1;
        int l = 0, r = n + 1;
        double res = 0;
        while (l < r - 1) {
            double u = (a[l + 1] - x1) / y1;
            double v = (x2 - a[r - 1]) / y2;
            if(u < v) {
                y1++;
                res += u;
                x1 = a[++l];
                x2 -= u * y2;
            } else if(v < u) {
                y2++;
                res += v;
                r--;
                x2 = a[r];
                x1 += y1 * v;
            } else {
                y1++;
                y2++;
                res += u;
                l++; r--;
                x1 = a[l];
                x2 = a[r];
            }
        }
        res += abs((x2 - x1) / (y1 + y2));
        cout << fixed << setprecision(9) << res << endl;
    }
    return 0;
}