
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

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

string get_product (string const& str, int b) {
	string final_product = "";
	short int carry = 0;

	for (int i = str.size() - 1; i >= 0; i--) {
		short int temp = (str[i] - '0') * b + carry;
		final_product += (temp % 10 + '0');
		carry = temp / 10;
	}

	while (carry > 0) {
		final_product += (carry % 10 + '0');
		carry /= 10;
	}

	reverse (final_product.begin(), final_product.end());

	return final_product;
}

int get_digits_sum (string const& str) {
	int sum = 0;

	for (auto c : str)
		sum += (c - '0');

	return sum;
}

void solve(void) {
	int mx = 0;

    for (int base = 99; base >= 1; base--) {
    	string product = to_string(base);

    	for (int cnt = 1; cnt <= 99; cnt++) {
    		mx = max (mx, get_digits_sum(product));
    		product = get_product(product, base);
    	}
    }

    cout << mx;
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