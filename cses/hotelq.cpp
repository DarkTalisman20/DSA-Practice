#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> tree;

void update(ll idx, ll val, ll n){
    tree[idx] -= val;
    ll k = idx/2;
    while(k>=1){
        tree[k] = max(tree[2*k],tree[2*k + 1]);
        k/=2;
    }
}

ll fn(ll idx, ll val, ll n){
    if(tree[idx]<val){
        return 0;
    }
    else{
        if(idx>=n && idx<= 2*n - 1){
            update(idx,val,n);
            return idx+1-n;
        }
        else{
            ll z = fn(2*idx, val, n);
            if(z==0){
                z = fn(2*idx + 1, val, n);
            }
            return z;
        }
    }
}

int main(){
    ll n,m; cin>>n>>m;
    vector<ll> h(n);
    for(ll i = 0;i<n;i++){
        cin>>h[i];
    }
    while(__builtin_popcount(n)!=1){
        n++; h.push_back(0);
    }
    tree.resize(2*n);
    for(ll i = 0;i<n;i++){
        tree[n+i] = h[i];
    }
    for(ll i = n-1;i>=1;i--){
        tree[i] = max(tree[2*i], tree[2*i + 1]);
    }
    for(ll i = 0;i<m;i++){
        ll a; cin>>a;
        cout<<fn(1,a,n)<<" ";
    }
    cout<<endl;
    return 0;
}