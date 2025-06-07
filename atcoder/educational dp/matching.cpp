#include<bits/stdc++.h> 
using namespace std; 
using ll = long long; 
const int MOD = 1e9 + 7; 
int main(){ 
    int n; 
    cin>>n; 
    vector<vector<int>> a(n,vector<int>(n)); 
    for(int i = 0;i<n;i++){
         for(int j = 0;j<n;j++){ 
            cin>>a[i][j]; 
        } 
    } 
    vector<int> dp(1<<n,0); 
    dp[0] = 1; 
    for(int i = 1;i<(1<<n);i++){ 
        int x = __builtin_popcount(i); 
        for(int j = 0;j<n;j++){ 
            if(((1<<j)&i)!=0){ 
                if(a[x-1][j]==1){ 
                    dp[i] = (dp[i] + dp[i-(1<<j)])%MOD; 
                } 
            } 
        } 
    } 
    cout<<dp[(1<<n)-1]<<endl; 
    return 0; 
}