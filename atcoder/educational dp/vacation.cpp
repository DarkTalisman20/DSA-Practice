#include<bits/stdc++.h>
using namespace std;

int n = 0;

int main(){
    cin>>n;
    vector<vector<int>> dp(n,vector<int>(3,-1));
    vector<vector<int>> p(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>p[i][0]>>p[i][1]>>p[i][2];
    }
    dp[0][0] = p[0][0]; dp[0][1] = p[0][1]; dp[0][2] = p[0][2];
    for(int i = 1;i<n;i++){
        dp[i][0] = p[i][0] + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = p[i][1] + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = p[i][2] + max(dp[i-1][0],dp[i-1][1]);
    }
    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<'\n';
    return 0;
}