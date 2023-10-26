#include <iostream>
#include <string>
#include <stack>

using namespace std;
#define int long long

const int N = 1e6 + 6;
int a[N];

void solve() {
    string s;
    int pos;
    cin >> s >> pos;
    int n = s.size();
    for (int i = 1; i <= n; ++i) {
        a[i] = 0;
    }
    s = ' ' + s;
    s = s + char('a' - 1);
    int cnt = 0;
    stack <int> st;
    while (!st.empty()) st.pop();
    for (int i = 1; i <= n + 1; ++i) {
        while (!st.empty() && s[st.top()] > s[i]) {
            int j = st.top();
            st.pop();
            cnt++;
            a[j] = cnt;
        }
        st.push(i);
    }

    int cur = n, iter = 0;
    while (true) {
        if (pos > cur) {
            iter++;
            pos -= cur;
            cur--;
        } else {
            break;
        }
    }
    int dem = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] <= iter) {
            continue;
        }
        dem++;
        if (dem == pos) {
            cout << s[i];
            return;
        }
    }
}  

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    
}