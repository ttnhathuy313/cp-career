#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5;
int x, k, rem;
vector <int> divisors;
vector <int> adj[N];

void write(int i, int depth) {
    if (rem == 0) return;
    if (depth == 0 || i == 0) {
        --rem;
        cout << divisors[i] << ' ';
        return;
    }
    for (int j : adj[i]) write(j, depth - 1);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TaskE.INP", "r", stdin);
    freopen("TaskE.OUT", "w", stdout);

    rem = 100000;
    cin >> x >> k;
    for (int i = 1; i <= sqrt(x); ++i) if (x % i == 0) {
        divisors.push_back(i);
        if (x / i != i) divisors.push_back(x / i);
    }
    sort(divisors.begin(), divisors.end());
    for (int i = 0; i < divisors.size(); ++i) {
        for (int j = 0; j < divisors.size(); ++j) if (divisors[j] % divisors[i] == 0) {
            adj[j].push_back(i);
        }
    }
    write(divisors.size() - 1, k);

  return 0;
}