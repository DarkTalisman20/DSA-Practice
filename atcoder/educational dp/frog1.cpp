#include<bits/stdc++.h>
using namespace std;

int n = 0;

int iterativefn(vector<int> &dp, vector<int> &h, int l){
    dp[n-1]= 0;
    dp[n-2] = abs(h[n-2]-h[n-1]);
    for(int i = n-3;i>=0;i--){
        int res1 = dp[i+1] + abs(h[i]-h[i+1]);
        int res2 = dp[i+2] + abs(h[i]-h[i+2]);
        dp[i] = min(res1,res2);
    }
    return dp[0];
}

int fn(vector<int> &dp,vector<int> &h, int l){
    if(l==n-1){return 0;}
    if(l==n-2){
        return dp[l] = abs(h[l]-h[l+1]);
    }
    int res1 = (dp[l+1]!=-1)?dp[l+1] : fn(dp,h,l+1);
    int res2 = (dp[l+2]!=-1)?dp[l+2] : fn(dp,h,l+2);
    return dp[l] = min((abs(h[l]-h[l+1]) + res1),(abs(h[l]-h[l+2]) + res2));
}

int main(){
    cin>>n;
    vector<int> h(n);
    vector<int> dp(n,-1);
    for(int i = 0;i<n;i++)  cin>>h[i];
    cout<<iterativefn(dp,h,0)<<'\n';
    return 0;
}