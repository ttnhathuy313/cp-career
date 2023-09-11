#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

const int N = 1e6 + 5;
int cnt[3000];
char ans[N];


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector <int> uoc;
        uoc.clear();
        for (int i = 1; i <= sqrt(n); ++i) if ((n % i) == 0) {
            uoc.push_back(i);
            if ((n / i) != i) {
                uoc.push_back(n / i);
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j : uoc) {
                if (i - j >= 1) {
                    cnt[ans[i - j]] = 1;
                }
            }
            for (char j = 'a'; j <= 'z'; ++j) if (cnt[j] == 0) {
                ans[i] = j;
                break;
            }
            for (int j : uoc) {
                if (i - j >= 1) {
                    cnt[ans[i - j]] = 0;
                }
            }
        }
        for (int i= 1; i <= n; ++i) {
            cout << ans[i];
        }
        cout << endl;
    }
}