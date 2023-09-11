#include <bits/stdc++.h>
 
using namespace std;

int t, n, x;

int main() {
 	ios_base::sync_with_stdio(0); cin.tie(0);
 	freopen("TaskA.inp", "r", stdin);
    cin >> t;
    while(t--) {
        cin >> n >> x;
        int maxx = 0;
        int ans = INT_MAX;
        for(int i=1;i<=n;i++) {
            int k;
            cin >> k;
            ans=min(ans,max(1,x/k)+int(x%k!=0));
        }
        cout<<ans<<"\n";
    }
    return 0;
}