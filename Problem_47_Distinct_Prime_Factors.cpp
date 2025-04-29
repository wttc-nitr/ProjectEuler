/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vb vector<bool>
#define vi vector<int>
#define vc vector<char>
#define INF (1LL << 60)
#define inf (1 << 30)

const int MAX = 1e7;
bitset<MAX+1> primes;

void generatePrimes (void) {
	primes[2] = 1;

	for (int i = 3; i <= MAX; i += 2)
		primes[i] = 1;

	for (int i = 3; i * i <= MAX; i += 2) {
		if (primes[i]) {
			for (int j = 3 * i; j <= MAX; j += 2 * i)
				primes[j] = 0;
		}
	}
}

bool has4Primes (int x) {
	if (primes[x])
		return false;

	int cnt = 0;

	for (int i = primes._Find_first(); x > 1; i = primes._Find_next(i)) {
		bool primeFactorFound = false;

		while (x % i == 0) {
			x /= i;
			primeFactorFound = true;
		}

		if (primeFactorFound) {
			cnt++;

			if (cnt > 4)
				return false;
		}

		if (primes[x]) {
			cnt++;
			break;
		}
	}

	return cnt == 4;
}

void solve(void) {
    generatePrimes();

    for (int i = 2 * 3 * 5 * 7; ; i++) {
    	if (has4Primes(i) && has4Primes(i + 1) && has4Primes (i + 2) && has4Primes(i + 3)) {
    		cout << i << ' ' << i + 1 << ' ' << i + 2 << ' ' << i + 3;
    		return;
    	}
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int test_cases = 1; 
    while (test_cases-- > 0) {
        solve();
    }

#ifndef ONLINE_JUDGE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}