#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int tc, n, m;
string s[N];
map <string, int> val;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("AC4.inp","r",stdin);
    freopen("AC4.out","w",stdout);

    val["Do"] = 1;
    val["Re"] = 2;
    val["Mi"] = 3;
    val["Fa"] = 4;
    val["Son"] = 5;
    val["La"] = 6;
    val["Si"] = 7;

    cin >> tc;
    while(tc--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> s[i];
        int ans = 0;
        for (int i = 1; i <= n - 2; ++i)
        {
            string l = s[i], mid = s[i + 1], r = s[i + 2];
            if(val[l] < val[mid] && val[r] < val[mid]) ++ans;
            if(val[l] > val[mid] && val[r] > val[mid]) ++ans;
        }
        //cout << ans << '\n';
        cout << (ans >= m ? "YES\n" : "NO\n");
    }

    return 0;
}