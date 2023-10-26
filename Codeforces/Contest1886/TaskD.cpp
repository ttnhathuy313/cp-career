#include <iostream>
#include <string>

using namespace std;

#define int long long

const int N = 3e5 + 5, MOD = 998244353;
int st[4 * N], a[N], n, m;
string s;

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = st[id * 2]  * st[id * 2 + 1] % MOD;
}

void update(int id, int l, int r, int pos) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        update(id * 2, l, mid, pos);
    } else {
        update(id * 2 + 1, mid + 1, r, pos);
    }
    st[id] = st[id * 2] * st[id * 2 + 1] % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    cin >> n >> m >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; ++i) {
        a[i] = (s[i] == '?' ? i - 1 : 1);
    }
    build(1, 1, n);
    cout << st[1] << '\n';
    while (m--) {
        int pos;
        char c;
        cin >> pos >> c;
        s[pos] = c;
        if (c == '?') {
            a[pos] = pos - 1;
        } else {
            a[pos] = 1;
        }
        update(1, 1, n, pos);
        cout << st[1] << '\n';
    }
    
}