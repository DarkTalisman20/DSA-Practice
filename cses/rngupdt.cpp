#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> tree;

//put val at inter node
void fn(ll node, ll node_left, ll node_right, ll b, ll c, ll d){
    if(node_left>=b && node_right<=c){
        tree[node] += d;
        return;
    }
    else if(node_left>c || node_right<b){
        return;
    }
    else{
        int x = node_left + (node_right-node_left)/2;
        fn(2*node, node_left, x, b, c, d); 
        fn(2*node + 1, x+1, node_right, b, c, d);
        return;
    }
}

ll giveval(ll idx, ll n){
    ll x = tree[n+idx];
    ll k = (n+idx)/2;
    while(k>=1){
        x += tree[k];
        k/=2;
    }
    return x;
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
    //query processing
    for(ll i = 0; i<q;i++){
        int a; cin>>a;
        if(a==1){
            int b,c,d; cin>>b>>c>>d;
            b--; c--;
            fn(1,0,n-1,b,c,d);
        }
        else if(a==2){
            int b; cin>>b;
            b--;
            cout<<giveval(b,n)<<endl;
        }
    }
    return 0;
}