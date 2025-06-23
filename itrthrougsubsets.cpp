#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n; cin>>n;
    vector<ll> v(n);
    ll sum = 0;
    for(ll i = 0;i<n;i++){
        cin>>v[i];
        sum+= v[i];
    }
    ll mindif = sum;
    for(ll x = 1;x<(1<<n);x++){
        ll cursum = 0;
        for(ll i = 0;i<n;i++){
            if((x&(1<<i)) != 0){
                cursum+=v[i];
            }
        }
        mindif = min(mindif,abs(sum-(2*cursum)));
    }
    cout<<mindif<<endl;
}