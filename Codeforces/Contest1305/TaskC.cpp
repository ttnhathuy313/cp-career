#include<bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e6 + 5;
int n, mod;
int a[N], cnt[N], h[N];

int modPow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

signed main() {
    freopen("taskC.inp","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> mod;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i) {
        a[i] %= mod;
        int k = a[i];
        for (int j = 0; j < mod; ++j) {
            h[j] += cnt[k];
            --k;
            if(k == -1) k = mod - 1;
        }
        ++cnt[a[i]];
    }
    int res = 1;
    for (int i = 0; i < mod; ++i) {
        res = (res * modPow(i, h[i])) % mod;
    }
    cout << res << endl;
}