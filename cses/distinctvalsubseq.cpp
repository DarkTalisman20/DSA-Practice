#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int main(){
    ll n; cin>>n;
    map<ll,ll> mp; vector<ll> v(n);
    for(ll i = 0;i<n;i++){
        cin>>v[i]; mp[v[i]]++;
    }
    ll sum = 1;
    for(auto x : mp){
        sum = (sum * (x.second+1))%MOD;
    }
    cout<<sum - 1<<endl;
    return 0;
}