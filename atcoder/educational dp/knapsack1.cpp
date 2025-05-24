#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n,w;
    cin>>n>>w;
    vector<pair<ll,ll>> p(n);
    vector<vector<ll>> dp(n+1,vector<ll>(w+1,LLONG_MIN));
    for(ll i = 0;i<n;i++){
        ll a,b; cin>>a>>b;
        p[i] = {a,b};
    }
    for(ll i = 0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(ll i =0 ;i <=w;i++){
        dp[0][i] = 0;
    }
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=w;j++){
            if(p[i-1].first <= j){
                dp[i][j] = max(dp[i-1][j-p[i-1].first] + p[i-1].second, dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][w]<<'\n';
    return 0;
}