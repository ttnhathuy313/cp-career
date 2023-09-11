#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int n, m, x;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TaskD.inp","r",stdin);
    cin >> x;
    if(x == 0) {
        cout <<"1 1" << endl;
        cout << 0 <<endl;
        return 0;
    }
    int c = (int)log2(x) + 1;
    int y = x + pow(2, c);
    cout << 2 << ' ' << 3 << '\n';
    cout << y << ' '<< x << " 0\n";
    cout << (y^x) << " " << y << ' ' << x;
    return 0;
}