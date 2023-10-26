#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        if (n <= 6) {
            cout << "NO\n";
            continue;
        }
        if (n % 3 == 0) {
            if (n < 1 + 4 + 7) {
                cout << "NO\n";
                continue;
            }
        }
        cout << "YES\n";
        if (n % 3 == 0) {
            cout << "1 4 " << n - 5 << "\n";
        } else if (n % 3 == 1) {
            cout << "1 2 " << n - 3 << "\n";
        } else if (n % 3 == 2) {
            cout << "1 2 " << n - 3 << "\n";
        }

    }

    return 0;
}