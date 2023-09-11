#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n, k;
struct line {
    int l, r;
} a[100005];
struct tree {
    int l, r, sum[11], bj;
} t[1600005];
int C[11][11], A[11], B[11], ans;

int read() {
    int x = 0;
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x;
}

int cmp(line u, line v) { return u.l < v.l; }

void build(int x, int l, int r) {
    t[x].l = l, t[x].r = r, t[x].bj = 1;
    if (l == r) {
        if (l == 1)
            t[x].sum[0] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * x, l, mid);
    build(2 * x + 1, mid + 1, r);
    for (int i = 0; i <= k; i++) t[x].sum[i] = t[2 * x].sum[i] + t[2 * x + 1].sum[i];
}

void pushdown(int x) {
    for (int i = 0; i <= k; i++) t[x].sum[i] = 1ll * t[x].bj * t[x].sum[i] % mod;
    t[2 * x].bj = 1ll * t[x].bj * t[2 * x].bj % mod;
    t[2 * x + 1].bj = 1ll * t[x].bj * t[2 * x + 1].bj % mod;
    t[x].bj = 1;
}

void dfs(int x, int l, int r) {
    if (t[x].bj != 1)
        pushdown(x);
    if (t[x].l > r || t[x].r < l)
        return;
    for (int i = 0; i <= k; i++) (t[x].sum[i] += B[i]) %= mod;
    if (t[x].l == t[x].r)
        return;
    dfs(2 * x, l, r);
    dfs(2 * x + 1, l, r);
    for (int i = 0; i <= k; i++) t[x].sum[i] = (t[2 * x].sum[i] + t[2 * x + 1].sum[i]) % mod;
}

void updata(int x, int l, int r) {
    if (t[x].bj != 1)
        pushdown(x);
    if (t[x].l > r || t[x].r < l)
        return;
    if (t[x].l >= l && t[x].r <= r) {
        t[x].bj = 2 * t[x].bj % mod;
        pushdown(x);
        return;
    }
    updata(2 * x, l, r);
    updata(2 * x + 1, l, r);
    for (int i = 0; i <= k; i++) t[x].sum[i] = (t[2 * x].sum[i] + t[2 * x + 1].sum[i]) % mod;
}

int query(int x, int l, int r, int mi) {
    if (t[x].bj != 1)
        pushdown(x);
    if (t[x].l > r || t[x].r < l)
        return 0;
    if (t[x].l >= l && t[x].r <= r)
        return t[x].sum[mi];
    int res = 0;
    (res += query(2 * x, l, r, mi)) %= mod;
    (res += query(2 * x + 1, l, r, mi)) %= mod;
    return res;
}

int main() {
        freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    n = read(), k = read();
    C[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    for (int i = 1; i <= n; i++) a[i].l = read() + 1, a[i].r = read() + 1;
    sort(a + 1, a + n + 1, cmp);
    build(1, 1, 2 * n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) A[j] = query(1, 1, a[i].l - 1, j), B[j] = 0;
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= j; l++) (B[j] += 1ll * A[l] * C[j][l] % mod) %= mod;
        }
        for (int j = 0; j <= k; j++) (B[j] += query(1, a[i].l, a[i].r, j)) %= mod;
        dfs(1, a[i].r, a[i].r);
        if (a[i].r != 2 * n + 1)
            updata(1, a[i].r + 1, 2 * n + 1);
    }
    for (int i = 1; i <= 2 * n; i++) (ans += query(1, i + 1, i + 1, k)) %= mod;
    printf("%d\n", ans);

    return 0;
}