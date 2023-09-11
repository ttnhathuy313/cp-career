#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e3, maxval = (1 << 10);
int B[maxn+1], A[maxn+1], D[maxn+1], m, n, ans, Dp[maxn+1][maxval];

int bit(int i, int x)
{
    return (x >> i) & 1;
}

int off(int i, int x)
{
    return x ^ (1 << i);
}

void Input()
{
    cin >> m;
    for (int i=1; i<=m; i++) cin >> B[i];
    sort(B+1, B+m+1);
    A[n = 1] = B[1];
    D[1] = 1;
    for (int i=2; i<=m; i++)
        if (B[i] == B[i-1]) D[n]++;
        else D[++n] = 1, A[n] = B[i];
}

bool ok(int x, int i)
{
    for (int u=1; u<=i-1; u++)
        if (bit(u-1, x))
            for (int v=u+1; v<=i; v++)
                if (bit(v-1, x))
                {
                    int a = A[v] - A[u];
                    if (a == 1 || a == 8 || a == 9) return 0;
                }
    return 1;
}

bool OK(int x, int i)
{
    for (int u=0; u<=8; u++)
        if (bit(u, x))
            for (int v=u+1; v<=9; v++)
                if (bit(v, x))
                {
                    int a = A[i-9+v] - A[i-9+u];
                    if (a == 1 || a == 8 || a == 9) return 0;
                }
    return 1;
}

void DP()
{
    int val = (1 << 10) - 1;
    for (int j=1; j<=n; j++)
        for (int i=0; i<=val; i++) Dp[j][i] = -1;
    Dp[1][0] = D[1];
    Dp[1][1] = 0;
    for (int i=2; i<=10; i++)
        for (int x=0; x<=val; x++)
        {
            if (x == (1 << i)) break;
            if (!ok(x, i)) { Dp[i][x] - 1; continue; }
            int y = x;
            if (bit(i-1, x)) y = off(i-1, x);
            Dp[i][x] = Dp[i-1][y] + D[i] * (!bit(i-1, x));
        }

    for (int i=11; i<=n; i++)
        for (int x=0; x<=val; x++)
        {
            if (!OK(x, i)) { Dp[i][x] = -1; continue; }
            int z = x;
            if (bit(9, x)) z = off(9, x);
            int y = z << 1;
            Dp[i][x] = Dp[i-1][y] + D[i] * (!bit(9, x));
            y ++;
            if (Dp[i][x] == -1)
                {
                    if (Dp[i-1][y] != -1) Dp[i][x] = Dp[i-1][y] + D[i] * (!bit(9, x));
                }
            else
                if (Dp[i-1][y] != -1) Dp[i][x] = min(Dp[i][x], Dp[i-1][y] + D[i] * (!bit(9, x)));
        }

    ans = m;
    for (int x=0; x<=val; x++)
        if (Dp[n][x] != -1) ans = min(ans, Dp[n][x]);
    cout << ans;
}

int main()
{
    freopen("SEQ198.inp","r",stdin);
    freopen("SEQ198.ans","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    Input();
    DP();
    return 0;
}
