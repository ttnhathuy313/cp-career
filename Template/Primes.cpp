#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
bitset <N> bs;
vector <int> primes;

void sieve() { //Remember to call at the beginning
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 1; i < N; ++i) if (bs[i]) {
		for (ll j = i * i; j < N; j += i) bs[j] = false;
		primes.push_back(i);
	}
}

vector <ii> PrimeFactorize(ll a) {
	vector<ii> pf;
	for(ll p = 2; p * p <= n; p++){
		if(n % p == 0){
			int a = 0;
			while(n % p == 0){
				a++;
				n /= p;
			}
			pf.push_back({p, a});
		}
	}
	if(n > 1){
		pf.push_back({n, 1});
	}
	return pf;
}

ll NumDivisors(int a) {
	ll res = 1;
	int PF_idx = 0, PF = primes[PF_idx];
	while (1LL * PF * PF <= a) {
		int exp = 0;
		while (a % PF == 0) {
			a /= PF;
			exp++;
		}
		res = res * (exp + 1);
		PF = primes[++PF_idx];
	}
	return res;
}

ll SumDivisors(int a) {
	ll res = 1;
	int PF_idx = 0, PF = primes[PF_idx];
	while (1LL * PF * PF <= a) {
		int exp = 0;
		while (a % PF == 0) {
			a /= PF;
			exp++;
		}
		res = res * ((Pow(PF, exp + 1) - 1) / (PF - 1));
		PF = primes[++PF_idx];
	}
	if (a != 1) res *= (1 + a);
	return res;
}

bool isPrime(ll a) { 
	if (a <= N) return bs[a]; 
	for (int i = 0; i < (int)primes.size(); i++) {
		if (primes[i] * primes[i] > a) break;
		if (a % primes[i] == 0) return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	return 0;
}