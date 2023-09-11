#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define ll long long

const int N = 1e6 + 5;
const int VAL = 2e5 + 5;
int n , ssc;
char f[N];
bool cnt[VAL][200];


struct DSU {
    int n;
    vector <int> lab, Rank;
    DSU() {}
    DSU(int _n) {
        this -> n = _n;
        lab.assign(n + 5, -1);
        Rank.assign(n + 5, 0);
    }
    int root(int x) {
        return (lab[x] == -1 ? x : lab[x] = root(lab[x]));
    }
    void merge(int u, int v) {
        int x = root(u), y = root(v);
        if (x == y) return;
        if (Rank[x] < Rank[y]) swap(x, y);
        lab[y] = x;
        Rank[x] += (Rank[x] == Rank[y]);
    }
} dsu;

main()
{
    freopen("TaskD.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ssc = n;
    for (int i = 1; i <= n; ++i) {
        cin >> f;
        int n = strlen(f);
        REP(j , n)
            cnt[i][f[j]] = true;
    }
    dsu = DSU(N);
    for (int i = 'a'; i <= 'z'; ++i)
    {
        int root = 0;
        for (int j = 1; j <= n; ++j) {
            if(cnt[j][i] != 0)
            {
                if(root == 0)
                    root = j;
                else if(dsu.root(root) != dsu.root(j))
                {
                    dsu.merge(root, j);
                    ssc--;
                }
            }
        }
    }
    cout << ssc << endl;
}