#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
#define endl '\n'

const int N = 1e6 + 5;
int a[N], grundy[N];
map <int, int> cnt;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        cnt.clear();
        for (int i = 1; i <= n; ++i) {
            grundy[i] = 0;
            cin >> a[i];
            a[i]--;
        }
        sort(a + 1, a + n + 1);
        int mex = 0;
        for (int i = 1; i <= n; ++i) {
            grundy[i] = mex;
            cnt[a[i]]++;
            while (cnt[mex] > 0) {
                mex++;
            }
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            cerr << grundy[i] << endl;
            res ^= grundy[i];
        }
        if (res == 0) {
            cout << "RR" << endl;
        } else cout << "Hieu" << endl;
    }

}