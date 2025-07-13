#include<bits/stdc++.h>
using namespace std;
using ll = long double;

void fn(){
    ll n; cin>>n;
    vector<ll> a(n);
    ll px,py,qx,qy; cin>>px>>py>>qx>>qy;
    ll maxval = LLONG_MIN;
    ll sm = 0;
    for(ll i = 0;i<n;i++){
        cin>>a[i];
        maxval = max(maxval,a[i]);
        sm+=a[i];
    }
    ll x = sqrtl(((qx-px)*(qx-px))+((qy-py)*(qy-py)));
    if(x<(2*maxval - sm) || x>sm ){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
}

int main(){
    ll t = 1; cin>>t;
    while(t--){
        fn();
    }
    return 0;
}