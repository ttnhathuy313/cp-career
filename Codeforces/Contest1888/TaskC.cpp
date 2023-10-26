#include <iostream>
#include <map>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int a[N], f[N], l[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        map <int, int> lst;
        for (int i= 1; i <= n; ++i) {
            cin >> a[i];
            f[i] = l[i] = lst[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            if (lst[a[i]] == 0) {
                f[i] = 1;
            } else {
                f[i] = 0;
            }
            lst[a[i]] = i;
            f[i] += f[i - 1];
        }
        lst.clear();
        int res = 0;
        for (int i = n; i >= 1; --i) {
            if (lst[a[i]] == 0) {
                res += f[i];
            }
            lst[a[i]] = i;
        }

        cout << res << endl;
    }

}