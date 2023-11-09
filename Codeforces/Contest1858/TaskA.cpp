#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < b) {
            cout << "Second\n";
            continue;
        }
        else if (a > b) {
            cout << "First\n";
            continue;
        } else {
            if (c & 1) {
                cout << "First" << endl;
            } else {
                cout << "Second" << endl;
            }
        }
    }

}