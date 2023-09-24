#include<iostream>
#include<vector>
using namespace std;

bool present(string s , vector<string> w, int i , int j ){
        // string temp = "";
        // while(i<j){
        //     temp.push_back(s[i]);
        //     i++;
        // }
        // return  find(w.begin(),w.end(), temp);

        string temp = s.substr(i, j - i + 1);
        auto it = find(w.begin(), w.end(), temp);
        return it != w.end();
        
    }
    vector<string> solve(string s,vector<string>& w, int i, int j,vector<string> &ans ){
        if(i>j) return ans; 
        // if(t[i][j] !=""){
        //     ans.push_back(t[i][j]);
        //     return ans;
        // }
        if(i == j){
            if(present(s, w, i , j)){
                ans.push_back(s.substr(i, j - i + 1));
                return ans;
            }
        }

        if(present(s,w,i,j)){
            ans.push_back(s.substr(i, j - i + 1));
                return ans;
        }
        

        vector<string> temp ;
        vector<string> anss = ans;
        for(int k=i;k<=j-1;k++){
            if(present(s, w, i, k)){
                temp = solve(s,w,k+1,j,ans);

            }
        }
         temp.insert(temp.end(), ans.begin(), ans.end());

        return temp;


    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // for(int i = 0 ; i<=20;i++){
        //     for(int j=0;j<=20;j++){
        //         t[i][j] = "null";
        //     }
        // }
        vector<string> ans ;
        return solve(s,wordDict, 0, s.length()-1, ans);
    }
int main(){
    string s;
    cin>>s;
    
    vector<string> wordDict;
    for(int i = 0;i<j;j++){
        cin>>wordDict[i];
    }
    int j = wordDict.size();
    vector<string> ans = wordBreak(s,wordDict);
    
    for(int i = 0;i<j;i++){
        cout<<wordDict[i];
    }
    return 0;
}