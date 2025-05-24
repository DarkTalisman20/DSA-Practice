#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF LLONG_MAX

int main(){
    ll n, w;
    cin>>n>>w;
    ll sum = 0;
    vector<ll> wt(n), c(n);
    for(ll i = 0;i<n;i++){
        cin>>wt[i]>>c[i];
        sum+=c[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(sum+1,INF));
    for(ll i = 0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(ll i= 1; i<=n;i++){
        for(ll j = 1;j<=sum;j++){
            if(j<c[i-1]) dp[i][j] = dp[i-1][j];
            else{
                if(dp[i-1][j-c[i-1]]!= INF && dp[i-1][j-c[i-1]] + wt[i-1]<= w){
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j-c[i-1]]+wt[i-1]);
                }
                else{
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
    }
    for(ll i = sum; i>=0;i--){
        if(dp[n][i]!=INF){
            cout<<i<<'\n';
            break;
        }
    }
    return 0;
}