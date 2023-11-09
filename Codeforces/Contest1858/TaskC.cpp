#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long

const int N = 1e5 + 5;
int fac[N], mark[N];
vector <int> res;


void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        mark[i] = 0;
    }
    for (int i = 1; i <= n; ++i) if (!mark[i]) {
        int v = i;
        while (v <= n) {
            cout << v << " ";
            mark[v] = 1;
            v *= 2;
        }
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);

    for (int i = 1; i < N; i++) {
        fac[i] = i;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                fac[i] = max(j, fac[i / j]);
                break;
            }
        }
    }

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
        if (tc != 0) cout << endl;
    }

}