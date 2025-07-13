#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void fn(){
    ll n; cin>>n;
    vector<ll> a(n);
    for(ll i =0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> orig(n);
    orig[n-1] = a[n-1];
    for(ll i = n-2;i>=0;i--){
        orig[i] = gcd(a[i],orig[i+1]);
    }

    ll x = 1; 
    for(ll i = 0;i<n; i++){
        ll k = a[i]/orig[i];
        x = (x/gcd(x,k))*k;
    }
    cout<<x<<endl;
}

int main(){
    ll t = 1; cin>>t;
    while(t--){
        fn();
    }
    return 0;
}
