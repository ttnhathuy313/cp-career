#include <bits/stdc++.h>

using namespace std;
 
int ans[500][500];
 
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TaskE.inp", "r", stdin);
    int n; cin >> n;
    if (n < 3) {
        cout << -1 << '\n';
        return 0;
    }
    int sq = n * n;
    ans[0][0] = sq;
    ans[0][1] = sq-4;w
    ans[0][2] = sq-3;
    ans[1][0] = sq-2;
    ans[1][1] = sq-7;
    ans[1][2] = sq-1;
    ans[2][0] = sq-8;
    ans[2][1] = sq-6;
    ans[2][2] = sq-5;
    int x = sq-9;
    for (int i = 3; i < n; i++) {
        if (i&1) {
            for (int j = 0; j <= i; j++) {
                ans[i][j] = x--;
            }
            for (int j = i-1; j >= 0; j--) {
                ans[j][i] = x--;
            }
        }
        else {
            for (int j = 0; j < i; j++) {
                ans[j][i] = x--;
            }
            for (int j = i; j >= 0; j--) {
                ans[i][j] = x--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}