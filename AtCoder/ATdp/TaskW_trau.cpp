#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 100
#define mp make_pair
#define mid (l+r)/2
#define le node * 2 
#define ri node * 2 + 1 
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef pair<double,ll>pdi;
const ll inf=2e18;
const ll mod=1e9+7;
const ld Pi=acos(-1) ;
ll n , q ;
vll in  [300009] , out [300009] ;
ll   l  [300009] , r   [300009] , val [300009] ; 
ll tree [1000009] , lzy [1000009] ;
void lzyUpd ( ll node , ll l , ll r ) {
    tree [node] += lzy [node] ;
    if ( l != r ) {
        lzy [le] += lzy [node] ;
        lzy [ri] += lzy [node] ;
    }
    lzy [node] = 0 ; 
}
void upd ( ll node , ll l , ll r , ll s , ll e , ll x ) {
    lzyUpd ( node , l , r ) ;
    if ( s > r || e < l ) return ;
    if ( s <= l && e >= r ) {
        lzy [node] += x ;
        lzyUpd ( node , l , r ) ;
        return ; 
    }
    upd ( le , l , mid , s , e , x ) ;
    upd ( ri , mid + 1 , r , s , e , x ) ;
    tree [node] = max ( tree [le] , tree [ri] ) ;
}
ll query ( ll node , ll l , ll r , ll s , ll e ) {
    lzyUpd ( node , l , r ) ;
    if ( s > r || e < l ) return -inf;
    if ( s <= l && e >= r ) return tree [node] ;
    return max ( query ( le , l , mid , s , e ) , query ( ri , mid + 1 , r , s , e ) ) ; 
}
int main () {
    freopen("TaskW.INP", "r", stdin);
    freopen("TaskW.ANS", "w", stdout);
    cin >> n >> q ;
    for ( ll i = 1 ; i <= q ; i ++ ) {
        scanf ("%lld%lld%lld",&l [i] ,&r [i] ,&val [i] ) ;
        in  [l[i]] .pb ( i ) ;
        out [r[i]] .pb ( i ) ; 
    }
    ll ans = 0 , sum = 0 ;  
    for ( ll i = 1 ; i <= n ; i ++ ) {
        for ( auto u : in [i] ) {
            sum += val [u] ; 
        }
        ll dp = sum + query ( 1 , 0 , n , 0 , i - 1 ) ; 
        upd ( 1 , 0 , n , i , i , dp - sum ) ; 
        for ( auto u : out [i] ) {
            sum -= val [u] ;
            upd ( 1 , 0 , n , l [u] , r [u] , val [u] ) ;   
        }
        ans = max ( ans , dp ) ; 
    }
    cout << ans << endl ; 
}

