#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
 
#define MOO(i, a, b) for(int i=a; i<b; i++)
#define M00(i, a) for(int i=0; i<a; i++)
#define MOOd(i,a,b) for(int i = (b)-1; i >= a; i--)
#define M00d(i,a) for(int i = (a)-1; i>=0; i--)
 
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<
 
template<class T> bool ckmin(T& a, const T& b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T& a, const T& b) {return a < b ? a = b, 1 : 0;}
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
 
const int MAX_N = 1000010;
int n;
int arr[MAX_N];
 
int main() { FAST
        freopen("IZhO17_money.INP", "r", stdin);
    freopen("IZhO17_money.ANS", "w", stdout);

    cin >> n;
    M00(i, n) cin >> arr[i];
    set<int> cur;
    int cnt = 1;
    int ub = 1e9;
    M00(i, n) {
        if(i != 0 && (arr[i] < arr[i-1] || arr[i] > ub)) {
            cnt++;
            auto it = cur.upper_bound(arr[i]);
            if(it == cur.end()) ub = 1e9;
            else ub = *it;
        }
        cur.insert(arr[i]);
    }
    finish(cnt);
}
 