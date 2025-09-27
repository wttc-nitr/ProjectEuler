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



void solve(void) {
	string str;
	double ans = 0.0;
	int line = 0, maxLn = 0;

	while (cin >> str) {
		string temp1, temp2;
		line++;

		for (int i = 0, j = 0; i < (int)str.size(); i++) {
			if (str[i] == ',') {
				j = 1;
				continue;
			}

			if (j == 0)
				temp1 += str[i];
			else temp2 += str[i];
		}

		double num1 = stoi(temp1), num2 = stoi(temp2);
		double temp3 = num2 * log10(num1);

		if (temp3 > ans) {
			ans = temp3;
			maxLn = line;
		}
	}

	cout << maxLn;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("/home/J0J0/Music/0099_base_exp.txt", "r", stdin);
    
    int test_cases = 1; 
    while (test_cases-- > 0) {
        solve();
        // cout << log10(1190800);
    }

#ifndef ONLINE_JUDGE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}