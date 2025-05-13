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

const int N = 80, M = 80;
vector<vi> matrix(N, vector<int>(M));
vector<vector<ll>> cache(N, vector<ll>(M, -1));

void read_input (void) {
	string str; 
    int i = 0;

    while (cin >> str) {
    	int num = 0, j = 0;

    	for (auto c : str) {
    		if (c == ',') {
    			matrix[i][j] = num;
	    		j++;

	    		num = 0;
	    		continue;	
    		}
    		
    		num = num * 10 + (c - '0');	
    	}

    	if (num > 0) {
    		matrix[i][j] = num;
    	}

    	i++;
    }
}

bool isValid (int i, int j) {
	return i >= 0 && i < N && j >= 0 && j < M;
}

ll get_min_sum (int i, int j) {
	if (i >= N || j >= M)
		return inf;

	if (i == N-1 && j == M-1)
		return matrix[i][j];

	if (cache[i][j] != -1)
		return cache[i][j];

	auto cnt1 = get_min_sum (i+1, j);
	auto cnt2 = get_min_sum (i, j+1);

	return cache[i][j] = 0LL + matrix[i][j] + min (cnt1, cnt2);
}

void solve(void) {
	read_input();

	cout << get_min_sum (0,0);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    freopen ("/home/J0J0/Downloads/0081_matrix.txt", "r", stdin);

    int test_cases = 1; 
    while (test_cases-- > 0) {
        solve();
    }

#ifndef ONLINE_JUDGE
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}