#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int a, b;
        cin >> a >> b;
        if (a != 1) {
            cout << 1 << endl;
            continue;
        }
        cout << b + 1 << endl;

    }

}