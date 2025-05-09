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

bool isPalindrome (string const & str) {
	int N = str.size();

	for (int i = 0; i < N/2; i++) {
		if (str[i] != str[N-i-1])
			return false;
	}

	return true;
}

string addStrings (string const& aa, string const& bb) {
	int N = aa.size(), M = bb.size();

	int carry = 0;
	string ans = "";

	int i = 0;

	while (i < N || i < M || carry > 0) {
		int sum = 0;

		if (i < N)
			sum = (aa[N-i-1] - '0');

		if (i < M)
			sum += (bb[M-i-1] - '0');

		sum += carry;
		ans += (sum % 10) + '0';
		carry = sum / 10;
		i++;
	}

	reverse(ans.begin(), ans.end());

	return ans;
}

void solve(void) {
	int ans = 0;

    for (int i = 1; i < 10'000; i++) {
    	int count = 0;
    	string str1 = to_string(i);
    	bool palindromeFound = false;

    	while (count + 1 < 50) {
    		string str2 = str1;
    		reverse(str2.begin(), str2.end());

    		auto sum = addStrings (str1, str2);

    		if (isPalindrome(sum)) {
    			palindromeFound = true;
    			break;
    		}

    		str1.swap(sum);
    		count++;
    	}

    	if (!palindromeFound)
    		ans++;
    }

    cout << ans;
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