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

bool isValid (ll x) {
	int cnt1[10] = {0};
	int cnt2[10] = {0};

	for (int i = 2; i <= 6; i++) {
		string str1 = to_string(x), str2 = to_string(x * i);
		memset(cnt1, 0, sizeof cnt1);
		memset(cnt2, 0, sizeof cnt2);

		for (auto c : str1)
			cnt1[c-'0']++;

		for (auto c : str2)
			cnt2[c-'0']++;

		for (int i = 0; i < 10; i++) {
			if (cnt1[i] != cnt2[i])
				return false;
		}
	}

	return true;
}

void solve(void) {
    for (ll i = 1; ; i++) {
    	if (isValid (i)) {
    		cout << i;
    		break;
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