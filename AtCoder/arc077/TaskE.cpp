#include <bits/stdc++.h>
 
using namespace std;
#define int long long

const int N = 1e5 + 5, oo = (int)2e9;
int c[N], cnt[N], M[N];
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskE.inp", "r", stdin);
	freopen("TaskE.out", "w", stdout);

    int n, m, a, b, k=0;
    cin >> n >> m;
    int sum = 0, mi = 0, res = oo;
    for (int i = 0; i <= m; i++) {
        cnt[i] = 0;
        M[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        if (i != 0) {
            a = c[i] + 1;
            a -= (a > m ? m : 0);
            cnt[a]--;
            b = c[i];
            b += (c[i] < c[i - 1] ? m : 0);
            M[a] += b - c[i - 1] - 1;
            a = c[i - 1] + 2;
            a -= (a > m ? m : 0);
            cnt[a]++;
            if (c[i] < c[i-1]) {
                mi += m - c[i-1];
                sum += m - c[i-1] + c[i];
                if (c[i-1] != m) {
                    k++;
                }
            }
            else sum += c[i] - c[i - 1];
        }
    }
    res = sum - mi;
    for (int i = 2; i <= m; i++) {
        mi -= M[i];
        k += cnt[i];
        mi += k;
        if (sum - mi < res) res = sum - mi;
    }
    cout << res;
    return 0;
}