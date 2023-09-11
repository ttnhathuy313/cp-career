#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector <int> val;
        val.clear();
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            val.push_back(abs(x - i));
        }
        int g = val[0];
        for (int i = 1; i < n; ++i) {
            g = __gcd(g, val[i]);
        }

        cout << g << endl;
    }
    return 0;
}