#include<bits/stdc++.h>

using namespace std;
#define ll long long
typedef pair <int, int> ii;

const int N = 1e6 + 5;
int n, par[N];
ii a[N];
vector <ii> g[N], inv;
set <ii> st;

int acs(int u) {
    if(par[u] == u) return u;
    else return par[u] = acs(par[u]);
}

void join(int u , int v) {
    par[acs(u)] = acs(v);
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TaskD.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].first >> a[i].second;
        g[a[i].first].push_back(ii(i, a[i].second));
    }
    for (int i = 1; i <= n; ++i)
        par[i] = i;
    int cnt = n;
    for (int i = 1; i <= 2 * n; ++i)
    {
        inv.clear();
        for (ii v : g[i])
        {
            st.insert(ii(v.second , v.first));
            for(auto it = st.begin() ; it != st.end() ; it++)
            {
                ii x = *(it);
                if (x.first < i) inv.push_back(ii(x.first, x.second));
                else {
                    if(x.first >= v.second) break;
                    if(acs(x.second) != acs(v.first)) {
                        join(x.second , v.first);
                        cnt--;
                    } else {
                        cout << "NO";
                        exit(0);
                    }
                }
            }
        }
        for (ii d : inv) st.erase(ii(d.first , d.second));
    }
    if(cnt == 1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}