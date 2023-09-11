#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5, oo = 1e9;
int n, q;
bool a[N];
char f[N];
vector <int> ans;
vector <int> res[100000];

signed main() {
    freopen("taskB.inp","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> f;
    int n = strlen(f);
    for (int i = n; i >= 1; --i)
        f[i] = f[i - 1];
    int cnt = 0;
    int r = strlen(f) - 1;
    while(1) {
        bool ok = false;
        int n = r;
        for (int i = 1; i <= n; ++i)
            a[i] = 0;
        ans.clear();
        int ll = 1 , rr = n , ress = 0;
        while (ll <= rr) {
            int mid = (ll + rr) >> 1;
            int x = 0, pos1 = oo, pos2 = -oo;
            for (int i = 1; i <= n; ++i) {
                if(f[i] == '(') {
                    x++;
                    if(x == mid) {
                        pos1 = i;
                        break;
                    }
                }
            }
            x = 0;
            for (int i = n; i >= 1; --i) {
                if(f[i] == ')') {
                    if(x + 1 == mid)
                    {
                        x++;
                        pos2 = i;
                        break;
                    }
                    ++x;
                }
            }
            if(pos1 <= pos2)
                ress = mid, ll = mid + 1;
            else rr = mid - 1;
        }
        if(ress == 0)
            break;
        ++cnt;
        int x = 0;
        for (int i = 1; i <= n; ++i) {
            if(f[i] == '(') {
                x++;
                a[i] = true;
                res[cnt].push_back(i);
            }
            if(x == ress)
                break;
        }
        x = 0;
        for (int i = n; i >= 1; --i) {
            if(f[i] == ')')
            {
                x++;
                a[i] = true;
                res[cnt].push_back(i);
            }
            if(x == ress)
                break;
        }
        r = 0;
        for (int i = 1; i <= n; ++i){
            if(!a[i])
                f[++r] = a[i];
        }
    }
    cout << cnt << "\n";
    for (int i = 1; i <= cnt; ++i) {
        cout << res[i].size() << "\n";
        sort(res[i].begin() , res[i].end());
        for (int v : res[i]) cout << v << ' '; cout << endl;
    }
}