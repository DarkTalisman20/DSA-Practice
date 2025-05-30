#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = ((long long)(1e9)) + 7;

int main(){
    ll n, k; cin>>n>>k;
    vector<ll> a(n);
    for(ll i = 0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));
    for(ll i = 0;i<=a[0] && i<=k ;i++){
        dp[1][i] = 1;
    }
    for(ll i = 2;i<=n;i++){
        vector<ll> prefixsum(k+1);
        prefixsum[0] = dp[i-1][0];
        for(ll j = 1;j<=k;j++){
            prefixsum[j] = (prefixsum[j-1] + dp[i-1][j])%MOD; 
        }
        for(ll j = 0;j<=k;j++){
            dp[i][j] = (a[i-1]<j)?((prefixsum[j]-prefixsum[j-a[i-1]-1] + MOD)%MOD):(prefixsum[j]);
        }
    }
    cout<<dp[n][k]<<'\n';
    return 0;
}