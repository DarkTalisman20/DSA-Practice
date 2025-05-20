#include<bits/stdc++.h>
using namespace std;

int n,k; 

int itr(vector<int> &dp, vector<int> &h){
    dp[n-1] = 0;
    for(int i = n-2;i>=0;i--){
        for(int j = 1; j<=k;j++){
            if(i+j>=n)  continue;
            dp[i] = min(dp[i],abs(h[i]-h[i+j])+dp[i+j]);
        }
    }
    return dp[0];
}

int main(){
    cin>>n>>k;
    vector<int> h(n);
    vector<int> dp(n,INT_MAX);
    for(int i = 0;i<n;i++){
        cin>>h[i];
    }
    cout<<itr(dp,h)<<'\n';
    return 0;
}