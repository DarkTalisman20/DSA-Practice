#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n; cin>>n;
    vector<ll> a(n);
    for(ll i = 0;i<n;i++)  cin>>a[i];
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    for(ll i = 1;i<=n;i++){
        dp[i][i] = a[i-1];
    }
    for(ll i = 1; i<n;i++){
        ll l = 1, r = l+i;
        while(r<=n){
            dp[l][r] = max((a[l-1]-dp[l+1][r]),(a[r-1]-dp[l][r-1]));
            l++; r++;
        }
    }
    cout<<dp[1][n]<<'\n';
}