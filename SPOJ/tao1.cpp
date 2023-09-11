#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < ll , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define ll long long
#define oo 1e7

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    FOR(i , 1 , oo)
    {
        ofstream fo("SEQ198.inp");
        int n = 60;
        fo << n << endl;
        FOR(i , 1 , n)
            fo << rand() % 30 + 1 << " ";
        system("SEQ198.exe");
        system("SEQ1981.exe");
        if(system("fc SEQ198.ans SEQ198.out") == 1)
            exit(0);
    }
}
