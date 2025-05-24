#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s,t;
    cin>>s>>t;
    vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1,0));
    for(int i = 1;i<=s.length();i++){
        for(int j = 1; j<=t.length(); j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string res="";
    int l = s.length(), r = t.length();
    while(l!=0 && r!=0){
        if(s[l-1]==t[r-1]){
            res+=s[l-1];
            l--; r--;
        }
        else{
            if(dp[l-1][r]>=dp[l][r-1]){
                l--;
            }
            else{ r--; }
        }
    }
    reverse(res.begin(),res.end());
    cout<<res<<'\n';
    return 0;
}