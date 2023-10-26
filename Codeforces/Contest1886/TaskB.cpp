#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int dist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        int start_x, start_y, circ1_x, circ1_y, circ2_x, circ2_y;
        cin >> start_x >> start_y >> circ1_x >> circ1_y >> circ2_x >> circ2_y;
        double d1_to = dist(start_x, start_y, circ1_x, circ1_y);
        double d2_to = dist(start_x, start_y, circ2_x, circ2_y);
        double d1 = dist(0, 0, circ1_x, circ1_y);
        double d2 = dist(0, 0, circ2_x, circ2_y);
        double d = dist(circ1_x, circ1_y, circ2_x, circ2_y);
        double radius = -1, l = 0, r = 1e4;
        int iteration = 90;
        while (iteration--) {
            double mid = (l + r) / 2;
            if (mid * mid >= max(d1_to, d1)) {
                radius = mid;
                r = mid;
                continue;
            }
            if (mid * mid >= max(d2_to, d2)) {
                radius = mid;
                r = mid;
                continue;
            }
            if (mid * mid >= min(d1_to, d2_to) && mid * mid >= min(d1, d2)) {
                if (4 * mid * mid >= d) {
                    radius = mid;
                    r = mid;
                    continue;
                }
            }
            l = mid;
        }
        cout << fixed << setprecision(9) << radius << "\n";
    }

    return 0;
}