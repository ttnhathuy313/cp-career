#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 1e6 + 5;
int n, a, b;
int cx[] = {1 , 0 , -1 , 0}, 
    cy[] = {0 , 1 , 0 , -1};
ii Point[N];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TaskC.inp", "r", stdin);
    freopen("TaskC.out", "w", stdout);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i)
        cin >> Point[i].first >> Point[i].second;
    int uu = 0;
    int ans = -1;
    for (int dir = 0; dir < 4; ++dir) {
        int res = 0, u = a + cx[dir], v = b + cy[dir];
        for (int i = 1; i <= n; ++i) {
            if(dir == 0 && a < u && u <= Point[i].first)
                res++;
            if(dir == 1 && b < v && v <= Point[i].second)
                res++;
            if(dir == 2 && a > u && u >= Point[i].first)
                res++;
            if(dir == 3 && b > v && v >= Point[i].second)
                res++;
        }
        if (ans < res) {
            ans = res;
            uu = dir;
        }
    }
    cout << ans << '\n';
    cout << a + cx[uu] << ' ' << b + cy[uu];
    return 0;
}