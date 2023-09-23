#include<iostream>
using namespace std;


 int minDistance(string s, string r) {
        int n=s.length();
        int m=r.length();

        int t[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 ||j==0){
                    t[i][j] = 0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == r[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                }else{
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
                }
            }
        }
        int insert = 0;
        int del=0;
        int replace=0;
        
        // insertions
        if(n<m){
            insert = m-n;
        }
        // deletions
        if(n>m){
            del = n-m;
        }
        // replacements
        replace = m-t[n][m];

        return insert+del+replace;
        

    }
signed main() {
	string X, Y; cin >> X;
    cin>>Y;
	cout << minDistance(X, Y) << endl;
	return 0;
}
