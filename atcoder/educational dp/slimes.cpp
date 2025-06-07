#include<bits/stdc++.h>
using namespace std;
using ll = long long;

//priority queue huffmann coding doesnt work because we loose track of the ordering of elements and hence cant 
//keep track of the elements which were adjacent to one another
//this is partition dp where we have to divide the whole problem into 2 parts

int main(){
    ll n; cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<ll> cost(n+1,0);
    cost[1] = a[0];
    for(ll i = 2;i<=n;i++){
        cost[i] = cost[i-1] + a[i-1];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    for(ll diff = 1;diff<=n-1;diff++){
        for(ll j = 1;j<=n-diff;j++){
            ll l = j; ll r = j+diff;
            ll mincost = LLONG_MAX;
            for(ll k = l; k<r;k++){
                ll cst = dp[l][k] + dp[k+1][r] + (cost[k]-cost[l-1]) + (cost[r] - cost[k]);
                mincost = min(mincost,cst);
            }
            dp[l][r] = mincost;
        }
    }
    cout<<dp[1][n]<<'\n';
    return 0;
}

/*
   1  2  3  4
1  0  3  
2  3  0  5
3     5  0  7
4        7  0

*/