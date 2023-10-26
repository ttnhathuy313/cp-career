#include <iostream>
#include <algorithm>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int a[N], b[N];

int sum_range(int l, int r) {
    return (r * (r + 1) - l * (l - 1)) / 2;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n - 1; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        sort(a + 1, a + n);
        sort(b + 1, b + 1 + n);
        int j = 1, i;
        bool extend = true;
        for (i = 1; i <= n - 1; ++i) {
            while (b[j] <= a[i] && j <= n) {
                ++j;
            }
            if (j == n + 1) {
                break;
            }
            if (j == n) {
                extend = false;
            }
            j++;
        }
        i--;
        int res = (n - i) * m;
        if (extend) {
            res -= min(m, b[n] - 1);
        } else {
            int j = 1, i, lst = 0, lstt = 0;
            bool extend = true;
            for (i = 1; i <= n - 1; ++i) {
                while (b[j] <= a[i] && j <= n) {
                    ++j;
                }
                if (j == n + 1) {
                    i--;
                    break;
                }
                if (b[j - 1] > a[i - 1] && lst != j - 1) {
                    lstt = b[j - 1] - 1;
                }
                lst = j;
                j++;
            }
            lstt = min(lstt, m);
            res -= lstt;
        }
        cout << res << endl;
    }

}