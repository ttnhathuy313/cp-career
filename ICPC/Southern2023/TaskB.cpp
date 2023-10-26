#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <assert.h>

using namespace std;

const int N = 1e4 + 4, oo = 1e9;
int dem[14];

void upd(int &a, int b) {
    a = min(a, b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;

    int res = 0, needed = 0;
    while (n % 7 == 0) {
        needed ++;
        res += 7;
        dem[7]++;
        n /= 7;
    }
    while (n % 5 == 0) {
        needed ++;
        res += 5;
        dem[5]++;
        n /= 5;
    }

    while (n % 8 == 0) {
        needed ++;
        res += 8;
        dem[8]++;
        n /= 8;
    }
    while (n % 9 == 0) {
        needed ++;
        res += 9;
        dem[9]++;
        n /= 9;
    }
    if (n % 6 == 0) {
        needed ++;
        res += 6;
        dem[6]++;
        n /= 6;
    }
    if (n % 4 == 0) {
        needed ++;
        res += 4;
        dem[4]++;
        n /= 4;
    }
    if (n % 2 == 0) {
        needed ++;
        res += 2;
        dem[2]++;
        n /= 2;
    }
    if (n % 3 == 0) {
        needed ++;
        res += 3;
        dem[3]++;
        n /= 3;
    }
    if (n != 1) {
        cout << -1 << endl;
        return 0;
    }
    if (needed > k) {
        cout << -1 << endl;
        return 0;
    }
    dem[1] = k - needed;
    for (int i = 1; i <= 9; i++) {
        while (dem[i] > 0) {
            cout << i;
            dem[i]--;
        }
    }
}