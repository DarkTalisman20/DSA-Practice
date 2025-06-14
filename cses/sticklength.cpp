#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n; cin>>n;
    vector<ll> a(n);
    for(ll i = 0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll x = a[(n/2)];
    ll sum = 0;
    for(ll i = 0;i<n;i++){
        sum+= abs(a[i]-x);
    }
    cout<<sum<<endl;
}