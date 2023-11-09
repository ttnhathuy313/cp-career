#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        n = s.size(); m = t.size();
        bool good = true, r0 = false, r1 = false;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                good = false;
                if (s[i] == '0') {
                    r0 = true;
                } else r1 = true;
            }
        }
        if (good) {
            cout << "Yes\n";
            continue;
        }

        if (r0 && r1) {
            cout << "No\n";
            continue;
        }

        if (m % 2 == 0) {
            cout << "No\n";
            continue;
        }


        good = true;
        for (int i = 0; i < m - 1; ++i) {
            if (t[i] == t[i + 1]) {
                good = false;
                break;
            }
        }
        // cout << r0 << ' ' << r1 << endl;
        if (!good) {
            cout << "No\n";
            continue;
        }
        if (r0 && t[0] == '0') {
            cout << "No\n";
            continue;
        }
        if (r1 && t[0] == '1') {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";

    }

}
/*

010110
01 0110 01
01 011 001 01

1001010011
0 1100101001 1
0 011 100101 001 1
0 011 01 1001 01 001 1
0 011 01 01 10 01 01 001 1

*/