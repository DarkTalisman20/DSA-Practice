#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

//dfs uses stack , bfs uses queue

int main(){
    ll n; cin>>n;
    vector<vector<ll>> adj(n+1);
    for(ll i = 0;i<n-1;i++){
        ll a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    stack<ll> st;
    st.push(1);
    vector<ll> vis(n+1);
    stack<ll> order;
    vector<ll> parent(n+1);
    vis[1] = 1;
    while(!st.empty()){
        ll x = st.top();
        st.pop();
        order.push(x);
        for(auto z : adj[x]){
            if(vis[z]==0){
                st.push(z); vis[z] = 1;
                parent[z] = x;
            }
        }
    }
    vector<vector<ll>> dp(n+1,vector<ll>(2,1));
    while(!order.empty()){
        ll x = order.top();
        order.pop();
        for(auto y : adj[x]){
            if(y==parent[x])    continue;
            dp[x][0] = ((dp[x][0]%MOD)*((dp[y][0]+dp[y][1])%MOD))%MOD;
            dp[x][1] = ((dp[x][1]%MOD)*(dp[y][0]%MOD))%MOD;
        }
    }
    cout<<(dp[1][0]+dp[1][1])%MOD<<endl;
    return 0;
}