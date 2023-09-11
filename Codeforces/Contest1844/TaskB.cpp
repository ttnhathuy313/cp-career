#include <iostream>
#include <vector>
#include <cmath>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        if (n == 2) {
            cout << "1 2" << endl;
            continue;
        }
        deque <int> q;
        q.push_back(1);
        for (int i = 4; i <= n; ++i) {
            if (i & 1) {
                q.push_front(i);
            } else q.push_back(i);
        }
        cout << 3 << ' ';
        for (auto i : q) {
            cout << i << ' ';
        }
        cout << 2 << ' ';
        cout << endl;
    }
}