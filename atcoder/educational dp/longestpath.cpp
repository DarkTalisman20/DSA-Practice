#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> indeg;

int main(){
    ll n, m; cin>>n>>m;
    indeg.resize(n+1,0);
    vector<vector<ll>> adj(n+1);
    for(ll i = 0;i<m;i++){
        ll a, b; cin>>a>>b;
        indeg[b]++;
        adj[a].push_back(b);
    }
    vector<ll> topo;
    for(ll i = 1;i<=n;i++){
        if(indeg[i]==0) {
            topo.push_back(i);
            //cout<<i<<'\n';
        }
    }
    ll itr = 0;
    while(topo.size()<n){
        //cout<<topo[itr]<<'\n';
        for(auto x : adj[topo[itr]]){
            indeg[x]--;
            //cout<<x<<" indeg = "<<indeg[x]<<'\n';
            if(indeg[x]==0) topo.push_back(x);
        }
        itr++;
    }
    // for(auto x : topo){
    //     cout<<x<<" ";
    // }
    //cout<<'\n';
    vector<ll> dp(n+1,0);
    ll res = -1;
    for(auto x : topo){
        for(auto y : adj[x]){
            //cout<<x<<" "<<y<< " : ";
            dp[y] = max(dp[y],dp[x]+1);
            res = max(res,dp[y]);
            //cout<<"prev node se = "<<dp[x]+1<<" new becomes = "<<dp[y]<<'\n';
        }
    }
    // for(int i = 1;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<'\n';
    cout<<res<<'\n';
    return 0;
}