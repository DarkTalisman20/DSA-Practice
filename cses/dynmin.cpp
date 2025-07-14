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
        return LLONG_MAX;
    }
    ll z = node_left + ((node_right - node_left)/2);
    return min(query(2*node, node_left, z, q_left, q_right),query(2*node+1, z+1, node_right, q_left, q_right));
}

void update(ll idx, ll val, ll n){
    tree[n+idx] = val;
    ll k = (n+idx)/2;
    while(k>=1){
        tree[k] = min(tree[2*k],tree[2*k + 1]);
        k/=2;
    }
}

int main(){
    ll n,q; cin>>n>>q;
    vector<ll> x(n);
    for(ll i =0;i<n;i++) cin>>x[i];
    while(__builtin_popcount(n)!=1){
        n++; x.push_back(LLONG_MAX);
    }
    tree.resize(2*n,0);
    //build
    for(ll i = 0;i<n;i++){
        tree[n+i] = x[i];
    }
    for(ll i = n-1;i>=1;i--){
        tree[i] = min(tree[2*i],tree[2*i + 1]);
    }
    //query processing
    for(ll i = 0; i<q;i++){
        int a, b, c; cin>>a>>b>>c;
        if(a==2){
            b--; c--;
            cout<<query(1,0,n-1,b,c)<<endl;
        }
        else if(a==1){
            b--;
            update(b,c,n);
        }
    }
    return 0;
}