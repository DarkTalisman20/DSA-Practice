#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> tree;

//finding range sum
ll query(ll node, ll node_left, ll node_right, ll q_left, ll q_right){
    if(q_left<=node_left && node_right<=q_right){
        return tree[node];
    }
    else if(q_left>node_right || q_right<node_left){
        return 0;
    }
    ll z = node_left + ((node_right - node_left)/2);
    return query(2*node, node_left, z, q_left, q_right) ^ query(2*node+1, z+1, node_right, q_left, q_right);
}

int main(){
    ll n,q; cin>>n>>q;
    vector<ll> x(n);
    for(ll i =0;i<n;i++) cin>>x[i];
    while(__builtin_popcount(n)!=1){
        n++; x.push_back(0);
    }
    tree.resize(2*n,0);
    //build
    for(ll i = 0;i<n;i++){
        tree[n+i] = x[i];
    }
    for(ll i = n-1;i>=1;i--){
        tree[i] = tree[2*i] ^ tree[2*i + 1];
    }
    //query processing
    for(ll i = 0; i<q;i++){
        ll a, b ; cin>>a>>b; --a; --b;
        cout<<query(1,0,n-1,a,b)<<endl;
    }
    return 0;
}