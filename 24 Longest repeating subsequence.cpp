#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1] && i != j) // jsut add an condition that element at ith index should not be equal to jth index 
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m];
}

signed main() {
	string X; cin >> X;
	int n = X.length();

	cout << LCS(X, X, n, n) << endl;
	return 0;
}
// https://www.geeksforgeeks.org/longest-repeating-subsequence/


class Solution {
	public:
		int LongestRepeatingSubsequence(string s){
		    // Code here
		    int n = s.length();
		    string r = "";
		    for(int i =0;i<n;i++){
		        r.push_back(s[i]);
		    }
		    
		    int m = r.length();
		  
		    int t[n+1][m+1];
		    for(int i = 0;i<=n;i++ ){
		        for(int j=0;j<=m;j++){
		            if(i==0 || j==0){
		                t[i][j] = 0;
		            }
		        }
		    }
		    
		    for(int i = 1;i<=n;i++){
		        for(int j=1;j<=m;j++){
		            if((s[i-1] == r[j-1] ) && i!=j){
		                t[i][j] = 1+t[i-1][j-1];
		            }else{
		                t[i][j] = max(t[i-1][j] , t[i][j-1]);
		            }
		        }
		    }
		    return t[n][m];
		}

};

gfg solution