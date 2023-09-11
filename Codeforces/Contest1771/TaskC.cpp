#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, V = 32000;
int n, m, cnt[V], a[N];
bitset <V> bs;
vector <int> primes;

const int MAX = 100000000;
const int LMT = 10000;
bool isprime[MAX];

void sieve()    //Sieve of Eratosthenes
{
    memset(isprime, true, sizeof(isprime));

    int i, k, j;
    isprime[1] = false;
    for (i = 4; i <= MAX; i+=2)
    {
        isprime[i] = false;
    }
    for (i = 3; i <= LMT; i+=2)
    {
        if(isprime[i])
            for (j = i*i, k = i<<1; j <= MAX; j+=k)
            {
                isprime[j] = false;
            }
    }
}

int abso(int a)     //fn to return absolute value
{
    return a>0?a:-a;
}
int gcd(int a,int b)    //Euclidean GCD recursive fn
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int pollard_rho(int n)  //pollard rho implementation
{
    if(n%2==0)
        return 2;

    int x = rand()%n+1;
    int c = rand()%n+1;
    int y = x;
    int g = 1;

    //fn is f(x) = x*x + c
    while(g==1)
    {
        x = ((x*x)%n + c)%n;    
        y = ((y*y)%n + c)%n;
        y = ((y*y)%n + c)%n;
        g = gcd(abso(x-y),n);
    }
    return g;
}

int factors[MAX/100], total;

void factorize(int n)   //fn to factorize the number
{
    if(n == 1)
        return;

    if(isprime[n])      //if n is prime,store it
    {
        factors[total++] = n;
        return;
    }
    int divisor = pollard_rho(n);   //get a divisor of n
    factorize(divisor);
    factorize(n/divisor);
}


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("TaskC.INP", "r", stdin);
	freopen("TaskC.OUT", "w", stdout);

	sieve();
	memset(cnt, 0, sizeof cnt);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		vector <int> single;
		single.clear();
		bool ok = false;
		vector <int> roll_back;
		roll_back.clear();
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			int x = a[i];
			if (ok == true) {
				continue;
			}
			total = 0;
			factorize(x);
			for (int j = 0; j < total; ++j) {
				if (factors[j] < V) {
					if (cnt[factors[j]] >= 1) {
						ok = true;
						break;
					}
				} else single.push_back(factors[j]);
			}
			for (int j = 0; j < total; ++j) {
				if (factors[j] < V) {
					cnt[factors[j]]++;
					roll_back.push_back(factors[j]);
				} 
			}
		}
		sort(single.begin(), single.end());
		for (int i = 1; i < single.size(); ++i) {
			if (single[i] == single[i - 1]) {
				ok = true;
			}
		}
		for (int v : roll_back) {
			cnt[v]--;
		}
		if (ok) {
			cout << "YES" << endl;
		} else cout << "NO" << endl;
	}

	return 0;
}