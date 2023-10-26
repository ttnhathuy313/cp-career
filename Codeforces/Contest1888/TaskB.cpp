#include <iostream>

using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        bool found = false;
        int n_even = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if ((a[i] % k) == 0) {
                found = true;
            }
            if (a[i] % 2 == 0) {
                n_even++;
            }
        }
        if (found) {
            cout << 0 << endl;
            continue;
        }
        int res = 9;
        if (k == 4) {
            res = max(0, 2 - n_even);
        }
        for (int i = 1; i <= n; ++i) {
            res = min(res, k - (a[i] % k));
        }
        cout << res << endl;
    }
    
}