#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        map <int, int> cnt;
        cnt.clear();
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        if (cnt.size() > 2) {
            cout << "NO" << '\n';
            continue;
        }
        if (cnt.size() == 2) {
            int a = cnt.begin()->second;
            int b = (++cnt.begin())->second;
            if (abs(a - b) > 1) {
                cout << "NO" << '\n';
                continue;
            }
        }
        cout << "YES" << '\n';
    }

}