/*

010110
01 0110 01
01 011 001 01

1001010011
0 1100101001 1
0 011 100101 001 1
0 011 01 1001 01 001 1
0 011 01 01 10 01 01 001 1

0111001100
011100110001

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool check(string s) {
    int n = s.size() - 1;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == s[n - i + 1]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n & 1) {
            cout << -1 << endl;
            continue;
        }
        s = ' ' + s;

        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            cnt += s[i] == '0';
        }
        if (cnt != n / 2) {
            cout << -1 << endl;
            continue;
        }

        vector <int> res;
        res.clear();

        while (!check(s)) {
            int l = 1, r = (int)s.size() - 1;
            while (l < r) {
                if (s[l] != s[r]) {
                    ++l; --r;
                } else break;
            }
            if (s[l] == '0') {
                s.insert(r + 1, "01");
                res.push_back(r);
            } else {
                s.insert(l, "01");
                res.push_back(l - 1);
            }
        }
        
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << ' ';
        }
        cout << endl;
    }

}